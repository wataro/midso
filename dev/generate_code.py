import argparse
import yaml
from os import path
from pprint import pprint


ARG_FORMATTER = '{type} {name}'
ARG_WITH_DEFAULT_FORMATTER = '{type} {name} = {default}'

DECLARE_FUNC_FORMATTER = '    {rettype}{name}({args});'
DECLARE_CONST_FUNC_FORMATTER = '    {rettype}{name}({args}) const;'
INTERFACE_FUNC_FORMATTER = '    virtual {rettype}{name}({args}) = 0;'
INTERFACE_CONST_FUNC_FORMATTER = (
    '    virtual {rettype} {name}({args}) const = 0;'
)
DEFINE_FUNC_FORMATTER = '{rettype}{classname}::{name}({args}) {{\n}}'
DEFINE_CONST_FUNC_FORMATTER = '{rettype}{classname}::{name}({args}) const {{\n}}'
TEST_FUNC_FORMATTER = 'TEST({classname}, {name}) {{\n}}'

COPYRIGHT = '''/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/'''


HEADER_FORMATTER = '''{copyright}
#ifndef {include_guard}
#define {include_guard}
#include "midso/common.h"
{includes}

namespace midso {{

class {classname}{superclass} {{
 public:
    {classname}() {{}}
    ~{classname}() {{}}
{declares}

 private:
    DISALLOW_COPY_AND_ASSIGN({classname});
}};

}}  // namespace midso

#endif  // {include_guard}
'''

INTERFACE_FORMATTER = '''{copyright}
#ifndef {include_guard}
#define {include_guard}
#include "midso/common.h"
{includes}

namespace midso {{

class {classname}{superclass} {{
 public:
    virtual ~{classname}() {{}}

{declares}
}};

}}  // namespace midso

#endif  // {include_guard}
'''

SOURCE_FORMATTER = '''{copyright}
#include "midso/{pathto}{basename}.h"

namespace midso {{

{defines}

}}  // namespace midso
'''

TEST_FORMATTER = '''{copyright}
#include "gtest/gtest.h"
#include "midso/{basename}.h"

{tests}
'''

def get_pathto(yaml_path):
    '''
    >>> get_pathto('dev/midso/layer/layer_interface.yaml')
    'layer/'
    >>> get_pathto('dev/midso/layer/backward/backward_layer_interface.yaml')
    'layer/backward/'
    '''
    rest, basename = path.split(yaml_path)
    pathto = ''
    while not rest.endswith('midso') and '' != rest:
        rest, basename = path.split(rest)
        pathto = path.join(basename, pathto)
    return pathto


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
    >>> get_include_guard('include/midso/layer/backward/linear_layer_backward.yaml')
    'INCLUDE_MIDSO_LAYER_BACKWARD_LINEAR_LAYER_BACKWARD_H_'
    '''
    basename = get_basename(yaml_path).upper()
    pathto = get_pathto(yaml_path)
    pathto = '_'.join(pathto.split('/'))
    pathto = pathto.upper()
    return 'INCLUDE_MIDSO_{}{}_H_'.format(pathto, basename)


def get_superclass(yaml_contents):
    '''
    to build headerfile
    >>> get_superclass({'superclass': ['dev/midso/layer/layer_interface.yaml']})
    ' : public LayerInterface'
    >>> get_superclass({'superclass': ['dev/midso/layer/layer_interface', 'dev/midso/layer/backward/backward_layer_interface.yaml']})
    ' : public LayerInterface, public BackwardLayerInterface'
    '''
    if 'superclass' in yaml_contents:
        superclasses = [get_class(get_basename(i)) for i in yaml_contents['superclass']]
        return ' : public ' + ', public '.join(superclasses)
    else:
        return ''


def get_includes(yaml_contents):
    '''
    >>> get_includes({})
    ''
    >>> get_includes({'superclass': ['dev/midso/layer/layer_interface.yaml']})
    '#include "midso/layer/layer_interface.h"'
    >>> get_includes({'superclass': ['dev/midso/layer/layer_interface', 'dev/midso/layer/backward/backward_layer_interface.yaml']})
    '#include "midso/layer/layer_interface.h"\\n#include "midso/layer/backward/backward_layer_interface.h"'
    '''
    super_bases = yaml_contents.get('superclass', [])
    includes = ['#include "midso/{}{}.h"'.format(get_pathto(i), get_basename(i)) for i in super_bases]
    return '\n'.join(includes)


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


def is_constructor(func_dict, classname):
    return get_method_name(func_dict) == classname
    

def get_rettype(func_dict, classname):
    '''
    >>> get_rettype('args_void_return_void()', 'LinearLayer')
    'void '
    >>> get_rettype({'args_int_return_void()': {'args': [{'type': 'int', 'name': 'n'}]}}, 'LinearLayer')
    'void '
    >>> get_rettype({'args_void_return_int()': {'return': 'int'}}, 'LinearLayer')
    'int '
    >>> get_rettype({'LinearLayer()': {'args': [{'type': 'int', 'name': 'a'}]}}, 'LinearLayer')
    ''
    '''
    if isinstance(func_dict, str):
        return 'void '
    elif is_constructor(func_dict, classname):
        return ''
    else:
        key = func_dict.keys()[0]
        return func_dict[key].get('return', 'void') + ' '


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


def get_function_declare(func_dict, formatter, classname):
    '''
    >>> get_function_declare('func()', DECLARE_FUNC_FORMATTER, 'LinearLayer')
    '    void func();'
    >>> get_function_declare('func()', DECLARE_CONST_FUNC_FORMATTER, 'LinearLayer')
    '    void func() const;'
    >>> get_function_declare({'func()': {'return': 'int'}}, DECLARE_CONST_FUNC_FORMATTER, 'LinearLayer')
    '    int func() const;'
    >>> get_function_declare(
    ...     {'func()': {'args': [{'type': 'int &', 'name': 'dst'}, {'type': 'const int', 'name': 'n', 'default': 1}]}},
    ...     DECLARE_CONST_FUNC_FORMATTER, 'LinearLayer')
    '    void func(int & dst,\\n        const int n = 1) const;'
    '''
    rettype = get_rettype(func_dict, classname)
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


def get_yaml_contents(yaml_path):
    with open(yaml_path) as f:
        return yaml.load(f)


def get_header_contents(yaml_path):
    copyright = COPYRIGHT
    basename = get_basename(yaml_path)
    classname = get_class(basename)
    include_guard = get_include_guard(yaml_path)
    if is_interface(yaml_path):
        formatter = INTERFACE_FORMATTER
        func_formatter = INTERFACE_FUNC_FORMATTER
        const_func_formatter = INTERFACE_CONST_FUNC_FORMATTER
    else:
        formatter = HEADER_FORMATTER
        func_formatter = DECLARE_FUNC_FORMATTER
        const_func_formatter = DECLARE_CONST_FUNC_FORMATTER
    yaml_contents = get_yaml_contents(yaml_path)
    if yaml_contents is None:
        includes = ''
        superclass = ''
        declares = ''
        return formatter.format(**locals())
    includes = get_includes(yaml_contents)
    superclass = get_superclass(yaml_contents)
    declare_list = []
    for func_dict in yaml_contents.get('method', []):
        dec = get_function_declare(func_dict, func_formatter, classname)
        declare_list.append(dec)
    for func_dict in yaml_contents.get('const method', []):
        dec = get_function_declare(func_dict, const_func_formatter, classname)
        declare_list.append(dec)
    declares = '\n'.join(declare_list)
    return formatter.format(**locals())


def get_function_define(func_dict, classname, formatter):
    rettype = get_rettype(func_dict, classname)
    if rettype.startswith('virtual '):
        rettype = rettype[len('virtual '):]
    name = get_method_name(func_dict)
    args = get_args(func_dict)
    return formatter.format(**locals()).strip()


def get_source_contents(yaml_path):
    copyright = COPYRIGHT
    pathto = get_pathto(yaml_path)
    basename = get_basename(yaml_path)
    classname = get_class(basename)
    yaml_contents = get_yaml_contents(yaml_path)
    if yaml_contents is None:
        defines = ''
        return SOURCE_FORMATTER.format(**locals())
    define_list = []
    for func_dict in yaml_contents.get('method', []):
        define = get_function_define(func_dict, classname, DEFINE_FUNC_FORMATTER)
        define_list.append(define)
    for func_dict in yaml_contents.get('const method', []):
        define = get_function_define(func_dict, classname, DEFINE_CONST_FUNC_FORMATTER)
        define_list.append(define)
    defines = '\n\n'.join(define_list)
    return SOURCE_FORMATTER.format(**locals())


def get_function_test(func_dict, classname):
    name = get_method_name(func_dict)
    if is_constructor(func_dict, classname):
        return ''
    else:
        return TEST_FUNC_FORMATTER.format(**locals())


def get_test_contents(yaml_path):
    copyright = COPYRIGHT
    basename = get_basename(yaml_path)
    classname = get_class(basename)
    yaml_contents = get_yaml_contents(yaml_path)
    if yaml_contents is None:
        tests = ''
        return TEST_FORMATTER.format(**locals())
    test_list = []
    for func_dict in yaml_contents.get('method', []):
        test = get_function_test(func_dict, classname)
        test_list.append(test)
    for func_dict in yaml_contents.get('const method', []):
        test = get_function_test(func_dict, classname)
        test_list.append(test)
    test_list = list(set(sorted(test_list)))
    tests = '\n\n'.join(test_list)
    return TEST_FORMATTER.format(**locals())


def save_header_file(args):
    yaml_path = args.yaml_path
    pathto = get_pathto(yaml_path)
    contents = get_header_contents(yaml_path)
    basename = get_basename(yaml_path)
    file_path = path.join('include', 'midso', pathto, '{}.h'.format(basename))
    if path.exists(file_path) and not args.overwrite:
        print 'ERROR: {} exists. If you want to overwrite it, use -f option.'.format(file_path)
        return
    with open(file_path, 'w') as f:
        f.write(contents)
        print 'saved: {}'.format(file_path)


def save_source_file(args):
    yaml_path = args.yaml_path
    if is_interface(yaml_path):
        return
    pathto = get_pathto(yaml_path)
    basename = get_basename(yaml_path)
    contents = get_source_contents(yaml_path)
    file_path = path.join('src', 'midso', pathto, '{}.cpp'.format(basename))
    if path.exists(file_path) and not args.overwrite:
        print 'ERROR: {} exists. If you want to overwrite it, use -f option.'.format(file_path)
        return
    with open(file_path, 'w') as f:
        f.write(contents)
        print 'saved: {}'.format(file_path)


def save_test_file(args):
    yaml_path = args.yaml_path
    if is_interface(yaml_path):
        return
    pathto = get_pathto(yaml_path)
    basename = get_basename(yaml_path)
    contents = get_test_contents(yaml_path)
    file_path = path.join('test', 'midso', pathto, '{}.cpp'.format(basename))
    if path.exists(file_path) and not args.overwrite:
        print 'ERROR: {} exists. If you want to overwrite it, use -f option.'.format(file_path)
        return
    with open(file_path, 'w') as f:
        f.write(contents)
        print 'saved: {}'.format(file_path)


def main(args):
    save_header_file(args)
    save_source_file(args)
    save_test_file(args)


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('yaml_path')
    parser.add_argument('-f', '--force', dest='overwrite', action='store_true')
    parser.add_argument('--test', action='store_true')
    args = parser.parse_args()

    if args.test:
        import doctest
        doctest.testmod()
    else:
        main(args)


