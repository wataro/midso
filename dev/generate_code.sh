#!/usr/bin/env bash

for i in `find dev/midso/ -name "*.yaml"`
do
    python dev/generate_code.py -f $i
done

ls -R include/midso src/midso test/midso

for i in `find include/midso/ -name "*.h"`
do
    python rule/cpplint.py $i
done

for i in `find src/midso/ -name "*.cpp"`
do
    python rule/cpplint.py $i
done

for i in `find test/midso/ -name "*.cpp"`
do
    python rule/cpplint.py $i
done
