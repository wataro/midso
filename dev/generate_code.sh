#!/usr/bin/env bash

for i in dev/midso/*.yaml;
do
    python dev/generate_code.py $i
done

ls -R include/midso src/midso test/midso

for i in include/midso/*.h
do
    python rule/cpplint.py $i
done

for i in src/midso/*.cpp
do
    python rule/cpplint.py $i
done

for i in test/midso/*.cpp
do
    python rule/cpplint.py $i
done
