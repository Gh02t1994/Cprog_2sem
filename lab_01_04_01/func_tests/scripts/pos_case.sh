#!/bin/bash

prog=./app.exe

in_file="$1"
file_out="./func_tests/data/$2"

$prog < "$in_file" > "pos_out.txt"

./func_tests/scripts/comparator.sh "pos_out.txt" "$file_out"