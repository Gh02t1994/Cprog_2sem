#!/bin/bash

script_dir=$(dirname "$(realpath "$0")")
dir=$(realpath "$script_dir/../..")
cd "$dir" || exit

prog="./app.exe"

stream_in="./func_tests/data/$1"
args="$2"

argv=$(cat "$args") 

new_in_file="./func_tests/data/neg_${stream_in//[^0-9]/}_in_file_n.txt"
touch "$new_in_file"

if ! $prog $argv > /dev/null 2>&1; then
    exit 0
else
    exit 1
fi
