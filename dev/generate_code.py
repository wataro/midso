import argparse
import yaml
from os import path
from pprint import pprint


ARG_FORMATTER = '{type} {name}'
ARG_WITH_DEFAULT_FORMATTER = '{type} {name} = {default}'

DECLARE_FUNC_FORMATTER = '    {rettype} {name}({args});'
DECLARE_CONST_FUNC_FORMATTER = '    {rettype} {name}({args}) const;'
INTERFACE_FUNC_FORMATTER = '    virtual {rettype} {name}({args}) = 0;'
INTERFACE_CONST_FUNC_FORMATTER = (
    '    virtual {rettype} {name}({args}) const = 0;'
)
DEFINE_FUNC_FORMATTER = '{rettype} {classname}::{name}({args}) {{\n}}'
DEFINE_CONST_FUNC_FORMATTER = '{rettype} {classname}::{name}({args}) {{\n}}'
TEST_FUNC_FORMATTER = 'TEST({classname}, {name}) {{\n}}'

COPYRIGHT = '''/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/'''


HEADER_FORMATTER = '''{COPYRIGHT}
#ifndef {include_guard}
#define {include_guard}

class {classname}{superclass} {{
 public:

{declares}

 private:
    DISALLOW_COPY_AND_ASIGN({classname});
}};

#endif  // {include_guard}
'''

INTERFACE_FORMATTER = '''{COPYRIGHT}
#ifndef {include_guard}
#define {include_guard}

class {classname}{superclass} {{
 public:
    virtual ~{classname}();

{declares}

}};

#endif  // {include_guard}
'''

SOURCE_FORMATTER = '''{COPYRIGHT}
#include "midso/{basename}.h"

{defines}
'''

TEST_FORMATTER = '''{COPYRIGHT}
#include <gtest/gtest.h>
#include "midso/{basename}.h"

{tests}
'''

def get_basename(yaml_path):
    '''
    >>> get_basename('/path/to/layer_interface.yaml')
    'layer_interface'
    '''
    rest, basename = path.split(yaml_path)
    return path.splitext(basename)[0]


def get_class(basename):
    '''
    >>> get_class('layer_interface')
    'LayerInterface'
    '''
    words = basename.split('_')
    return ''.join(w.title() for w in words)


def get_include_guard(yaml_path):
    '''
    >>> get_include_guard('include/midso/layer_interface.yaml')
    'INCLUDE_MIDSO_LAYER_INTERFACE_H_'
    >>> get_include_guard('include/midso/layer/linear_layer.yaml')
    'INCLUDE_MIDSO_LAYER_LINEAR_LAYER_H_'
    '''
    rest, basename = path.split(yaml_path)
    rest, dirname1 = path.split(rest)
    basename = path.splitext(basename)[0].upper()
    if 'midso' == dirname1:
        return 'INCLUDE_MIDSO_{}_H_'.format(basename)
    else:
        dirname1 = dirname1.upper()
        assert 'midso' == path.basename(rest), rest
        return 'INCLUDE_MIDSO_{}_{}_H_'.format(dirname1, basename)


def get_superclass(yaml_contents):
    '''
    to build headerfile
    >>> get_superclass({'superclass': ['layer_interface']})
    ' : LayerInterface'
    >>> get_superclass({'superclass': ['layer_interface', 'trainable_interface']})
    ' : LayerInterface, TrainableInterface'
    '''
    if 'superclass' in yaml_contents:
        superclasses = [get_class(i) for i in yaml_contents['superclass']]
        return ' : ' + ', '.join(superclasses)
    else:
        return ''


def get_method_name(func_dict):
    '''
    >>> get_method_name('args_void_return_void()')
    'args_void_return_void'
    >>> get_method_name({'args_int_return_void()': {'args': {'type': 'int', 'name': 'n'}}})
    'args_int_return_void'
    >>> get_method_name({'args_void_return_int()': {'return': 'int'}})
    'args_void_return_int'
    '''
    raw_method_name = func_dict if isinstance(func_dict, str) else func_dict.keys()[0]
    assert raw_method_name.endswith('()'), raw_method_name
    return raw_method_name[:-len('()')]
    

def get_rettype(func_dict):
    '''
    >>> get_rettype('args_void_return_void()')
    'void'
    >>> get_rettype({'args_int_return_void()': {'args': {'type': 'int', 'name': 'n'}}})
    'void'
    >>> get_rettype({'args_void_return_int()': {'return': 'int'}})
    'int'
    '''
    if isinstance(func_dict, str):
        return 'void'
    else:
        key = func_dict.keys()[0]
        return func_dict[key].get('return', 'void')


def get_args(func_dict, with_default=False):
    '''
    >>> get_args('func()')
    ''
    >>> get_args({'func()': {'return': 'int'}})
    ''
    >>> get_args({'func()': {'args': [{'type': 'int', 'name': 'n'}]}})
    'int n'
    >>> get_args({'func()': {'args': [{'type': 'int &', 'name': 'dst'}, {'type': 'const int', 'name': 'n'}]}})
    'int & dst,\\n        const int n'
    >>> get_args(
    ...     {'func()': {'args': [{'type': 'int &', 'name': 'dst'}, {'type': 'const int', 'name': 'n', 'default': 1}]}},
    ...     with_default=True)
    'int & dst,\\n        const int n = 1'
    '''
    if isinstance(func_dict, str):
        return ''
    else:
        key = func_dict.keys()[0]
        assert '()' == key[-2:]
        name = key[:-2]
        arg_list = []
        for arg_dict in func_dict[key].get('args', []):
            if with_default and 'default' in arg_dict:
                arg = ARG_WITH_DEFAULT_FORMATTER.format(**arg_dict)
            else:
                arg = ARG_FORMATTER.format(**arg_dict)
            arg_list.append(arg)
        args = ',\n        '.join(arg_list)
    return args


def get_function_declare(func_dict, formatter):
    '''
    >>> get_function_declare('func()', DECLARE_FUNC_FORMATTER)
    '    void func();'
    >>> get_function_declare('func()', DECLARE_CONST_FUNC_FORMATTER)
    '    void func() const;'
    >>> get_function_declare({'func()': {'return': 'int'}}, DECLARE_CONST_FUNC_FORMATTER)
    '    int func() const;'
    >>> get_function_declare(
    ...     {'func()': {'args': [{'type': 'int &', 'name': 'dst'}, {'type': 'const int', 'name': 'n', 'default': 1}]}},
    ...     DECLARE_CONST_FUNC_FORMATTER)
    '    void func(int & dst,\\n        const int n = 1) const;'
    '''
    rettype = get_rettype(func_dict)
    name = get_method_name(func_dict)
    args = get_args(func_dict, with_default=True)
    return formatter.format(**locals())


def is_interface(yaml_path):
    '''
    >>> is_interface('dev/midso/layer_interface.yaml')
    True
    >>> is_interface('dev/midso/layer/linear_layer.yaml')
    False
    '''
    basename = get_basename(yaml_path)
    return basename.endswith('_interface')


def get_header_contents(yaml_contents, include_guard, classname, formatter):
    '''
    >>> yaml_contents = {
    ...     'superclass':['layer_interface'],
    ...     'method':[
    ...         {'func()': {'args': [{'type': 'int &', 'name': 'dst'}, {'type': 'const int', 'name': 'n', 'default': 1}]}},
    ...         {'propagate()': {'args':[{'type':'const Tensor &', 'name':'input_data'}]}},
    ...     ],
    ...     'const method':[
    ...         {'output_node()': {'return':'const Tensor &'}}
    ...     ]
    '''
    superclass = get_superclass(yaml_contents)
    declare_list = []
    for func_dict in yaml_contents['method']:
        dec = get_function_declare(func_dict, DECLARE_FUNC_FORMATTER)
        declare_list.append(dec)
    for func_dict in yaml_contents['const method']:
        dec = get_function_declare(func_dict, DECLARE_CONST_FUNC_FORMATTER)
        declare_list.append(dec)
    declares = '\n'.join(declare_list)
    return formatter.format(**locals())


def get_interface_contents(yaml_path):
    include_guard = get_include_guard(yaml_path)
    classname = get_class(yaml_path)
    superclass = get_superclass(args.yaml_path)
    declare_list = []
    for func_dict in get_methods(args.yaml_path):
        if is_const_method(func_dict):
            formatter = INTERFACE_CONST_FUNC_FORMATTER
        else:
            formatter = INTERFACE_FUNC_FORMATTER
        dec = get_function_declare(func_dict, formatter)
        declare_list.append(dec)
    declares = '\n'.join(declare_list)
    return INTERFACE_FORMATTER.format(**locals())


def get_header_contents(yaml_path, const_fomatter, noconst_formatter):
    include_guard = get_include_guard(yaml_path)
    classname = get_class(yaml_path)
    superclass = get_superclass(args.yaml_path)
    declare_list = []
    for func_dict in get_methods(args.yaml_path):
        if is_const_method(func_dict):
            formatter = DECLARE_CONST_FUNC_FORMATTER
        else:
            formatter = DECLARE_FUNC_FORMATTER
        dec = get_function_declare(func_dict, formatter)
        declare_list.append(dec)
    declares = '\n'.join(declare_list)
    return HEADER_FORMATTER.format(**locals())


def get_function_define(func_dict, classname):
    rettype = get_rettype(func_dict)
    name = get_name(func_dict)
    args = get_args(func_dict)
    return DEFINE_FUNC_FORMATTER.format(**locals())


def get_source_contents(yaml_path):
    basename = get_basename(yaml_path)
    classname = get_class(yaml_path)
    define_list = []
    for func_dict in get_methods(args.yaml_path):
        define = get_function_define(func_dict, classname)
        define_list.append(define)
    defines = '\n\n'.join(define_list)
    return SOURCE_FORMATTER.format(**locals())


def get_function_test(func_dict, classname):
    rettype = get_rettype(func_dict)
    name = get_name(func_dict)
    return TEST_FUNC_FORMATTER.format(**locals())


def get_test_contents(yaml_path):
    basename = get_basename(yaml_path)
    classname = get_class(yaml_path)
    test_list = []
    for func_dict in get_methods(args.yaml_path):
        test = get_function_test(func_dict, classname)
        test_list.append(test)
    tests = '\n\n'.join(test_list)
    return TEST_FORMATTER.format(**locals())


def save_header_file(yaml_path):
    basename = get_basename(yaml_path)
    if is_interface(yaml_path):
        contents = get_interface_contents(yaml_path)
    else:
        contents = get_header_contents(yaml_path)
    file_path = path.join('include', 'midso', '{}.h'.format(basename))
    with open(file_path, 'w') as f:
        f.write(contents)
        print 'saved: {}'.format(file_path)


def save_source_file(yaml_path):
    if is_interface(yaml_path):
        return
    basename = get_basename(yaml_path)
    contents = get_source_contents(yaml_path)
    file_path = path.join('src', 'midso', '{}.cpp'.format(basename))
    with open(file_path, 'w') as f:
        f.write(contents)
        print 'saved: {}'.format(file_path)


def save_test_file(yaml_path):
    if is_interface(yaml_path):
        return
    basename = get_basename(yaml_path)
    contents = get_test_contents(yaml_path)
    file_path = path.join('test', 'midso', '{}.cpp'.format(basename))
    with open(file_path, 'w') as f:
        f.write(contents)
        print 'saved: {}'.format(file_path)


def main():
    save_header_file(args.yaml_path)
    save_source_file(args.yaml_path)
    save_test_file(args.yaml_path)


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('yaml_path')
    parser.add_argument('--test', action='store_true')
    args = parser.parse_args()

    if args.test:
        import doctest
        doctest.testmod()
    else:
        main()


