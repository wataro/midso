import argparse
import yaml
from os import path
from pprint import pprint


ARG_FORMATTER = '{type} {name}'
ARG_WITH_DEFAULT_FORMATTER = '{type} {name} = {default}'

MEMBER_FORMATTER = '{args};'
DECLARE_FUNC_FORMATTER = '    {rettype} {name}({args});'
DECLARE_CONST_FUNC_FORMATTER = '    {rettype} {name}({args}) const;'
INTERFACE_FUNC_FORMATTER = '    virtual {rettype} {name}({args}) = 0;'
INTERFACE_CONST_FUNC_FORMATTER = (
    '    virtual {rettype} {name}({args}) const = 0;'
)
DEFINE_FUNC_FORMATTER = '{rettype} {classname}::{name}({args}) {{\n}}'
TEST_FUNC_FORMATTER = 'TEST({classname}, {name}) {{\n}}'

HEADER_FORMATTER = '''/**
    Copyright (c) 2015 <Taro WATASUE>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#ifndef {include_guard}
#define {include_guard}

class {classname} {{
 public:
    {classname}();

    ~{classname}();

{declares}

 private:
    DISALLOW_COPY_AND_ASIGN({classname});
}};

#endif  // {include_guard}
'''

INTERFACE_FORMATTER = '''/**
    Copyright (c) 2015 <Taro WATASUE>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#ifndef {include_guard}
#define {include_guard}

class {classname} {{
 public:
    virtual ~{classname}();

{declares}

}};

#endif  // {include_guard}
'''

SOURCE_FORMATTER = '''/**
    Copyright (c) 2015 <Taro WATASUE>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#include "midso/{basename}.h"

{defines}
'''

TEST_FORMATTER = '''/**
    Copyright (c) 2015 <Taro WATASUE>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#include <gtest/gtest.h>
#include "midso/{basename}.h"

{tests}
'''

def get_basename(yaml_path):
    rest, basename = path.split(yaml_path)
    return path.splitext(basename)[0]


def get_class(yaml_path):
    basename = get_basename(yaml_path)
    words = basename.split('_')
    return ''.join(w.title() for w in words)


def get_include_guard(yaml_path):
    rest, basename = path.split(yaml_path)
    rest, dirname1 = path.split(rest)
    basename = path.splitext(basename)[0].upper()
    if 'midso' == dirname1:
        return 'INCLUDE_MIDSO_{}_H_'.format(basename)
    else:
        assert 'midso' == path.basename(rest), rest
        return 'INCLUDE_MIDSO_{}_{}_H_'.format(dirname1, basename)


def get_name(func_dict):
    if isinstance(func_dict, str):
        assert '()' == func_dict[-2:]
        return func_dict[:-2]
    else:
        key = func_dict.keys()[0]
        assert '()' == key[-2:]
        return key[:-2]
    

def get_rettype(func_dict):
    if isinstance(func_dict, str):
        return 'void'
    else:
        key = func_dict.keys()[0]
        return func_dict[key].get('return', 'void')


def get_args(func_dict, with_default=False):
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
        args = '\n        '.join(arg_list)
    return args

def is_interface(yaml_path):
    classname = get_class(args.yaml_path)
    return 'Interface' == classname[-len('Interface'):]

def is_const_method(func_dict):
    if isinstance(func_dict, str):
        return False
    else:
        key = func_dict.keys()[0]
        if 'args' in func_dict[key]:
            return 'const' in func_dict[key]['args']
        else:
            return False


def get_function_declare(func_dict, formatter):
    rettype = get_rettype(func_dict)
    name = get_name(func_dict)
    args = get_args(func_dict, with_default=True)
    return formatter.format(**locals())


def get_interface_contents(yaml_path):
    include_guard = get_include_guard(yaml_path)
    classname = get_class(yaml_path)
    declare_list = []
    for func_dict in yaml.load(open(args.yaml_path)):
        if is_const_method(func_dict):
            formatter = INTERFACE_CONST_FUNC_FORMATTER
        else:
            formatter = INTERFACE_FUNC_FORMATTER
        dec = get_function_declare(func_dict, formatter)
        declare_list.append(dec)
    declares = '\n'.join(declare_list)
    return INTERFACE_FORMATTER.format(**locals())


def get_header_contents(yaml_path):
    include_guard = get_include_guard(yaml_path)
    classname = get_class(yaml_path)
    declare_list = []
    for func_dict in yaml.load(open(args.yaml_path)):
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
    for func_dict in yaml.load(open(args.yaml_path)):
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
    for func_dict in yaml.load(open(args.yaml_path)):
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


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('yaml_path')
    args = parser.parse_args()

    save_header_file(args.yaml_path)
    save_source_file(args.yaml_path)
    save_test_file(args.yaml_path)

