#!/usr/bin/env bash

for i in dev/midso/*.yaml;
do
    python dev/generate_code.py $i
done

ls -R include/midso src/midso test/midso

