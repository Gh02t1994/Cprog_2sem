#!/bin/bash

script_dir=$(dirname "$(realpath "$0")")
dir=$(realpath "$script_dir/../..")
cd "$dir" || exit

prog="./app.exe"

touch "./func_tests/data/in.bin"
bin="./func_tests/data/in.bin"

stream_in="./func_tests/data/$1"
args="$2"

argv=$(cat "$args") 

if grep -q '^p ' "$args"; then
    $prog "import" "$stream_in" "$bin"

    if ! $prog $argv > /dev/null 2>&1; then
        exit 0
    else
        exit 1
    fi
elif grep -q '^s ' "$args"; then
    $prog "import" "$stream_in" "$bin"

    if ! $prog $argv > /dev/null 2>&1; then
        exit 0
    else
        exit 1
    fi
fi
