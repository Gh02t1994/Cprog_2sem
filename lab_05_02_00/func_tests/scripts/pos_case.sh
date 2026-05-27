#!/bin/bash

script_dir=$(dirname "$(realpath "$0")")
dir=$(realpath "$script_dir/../..")
cd "$dir" || exit

prog="./app.exe"

expect="./func_tests/data/$1"
args="$2"

argv=$(cat "$args")
if ! $prog $argv > "pos_out.txt"; then
    exit 1
fi

"$script_dir"/comparator.sh "pos_out.txt" "$expect"