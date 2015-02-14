import argparse
import yaml
from os import path
from pprint import pprint

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


ARG_FORMATTER = '{type} {name}'
ARG_WITH_DEFAULT_FORMATTER = '{type} {name} = {default}'

MEMBER_FORMATTER = '{args};'
DECLARE_FUNC_FORMATTER = '    {rettype} {name}({args});'
DEFINE_FUNC_FORMATTER = '{rettype} {classname}::{name}({args}){{\n}}'
TEST_FUNC_FORMATTER = 'TEST({classname}, {name}){{\n}}'

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

{declares}
}};

#endif  // {include_guard}
'''

SOURCE_FORMATTER = '''/**
    Copyright (c) 2015 <Taro WATASUE>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#include "{basename}.h"

{defines}
'''

TEST_FORMATTER = '''/**
    Copyright (c) 2015 <Taro WATASUE>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#include <gtest/gtest.h>
#include "{basename}.h"

{tests}
'''

def get_function_declare(func_dict):
    key = func_dict.keys()[0]
    rettype = func_dict[key]['return']
    assert '()' == key[-2:]
    name = key[:-2]
    arg_list = []
    for arg_dict in func_dict[key].get('args', []):
        if 'default' in arg_dict:
            arg = ARG_WITH_DEFAULT_FORMATTER.format(**arg_dict)
        else:
            arg = ARG_FORMATTER.format(**arg_dict)
        arg_list.append(arg)
    args = '\n        '.join(arg_list)
    return DECLARE_FUNC_FORMATTER.format(**locals())


def get_header_contents(yaml_path):
    include_guard = get_include_guard(yaml_path)
    classname = get_class(yaml_path)
    declare_list = []
    for func_dict in yaml.load(open(args.yaml_path)):
        dec = get_function_declare(func_dict)
        declare_list.append(dec)
    declares = '\n'.join(declare_list)
    return HEADER_FORMATTER.format(**locals())


def get_function_define(func_dict, classname):
    key = func_dict.keys()[0]
    rettype = func_dict[key]['return']
    assert '()' == key[-2:]
    name = key[:-2]
    arg_list = []
    for arg_dict in func_dict[key].get('args', []):
        arg = ARG_FORMATTER.format(**arg_dict)
        arg_list.append(arg)
    args = '\n        '.join(arg_list)
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
    key = func_dict.keys()[0]
    rettype = func_dict[key]['return']
    assert '()' == key[-2:]
    name = key[:-2]
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


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('yaml_path')
    args = parser.parse_args()

    print get_header_contents(args.yaml_path)
    print get_source_contents(args.yaml_path)
    print get_test_contents(args.yaml_path)

