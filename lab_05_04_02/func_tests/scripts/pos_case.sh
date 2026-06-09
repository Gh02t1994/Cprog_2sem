#!/bin/bash

script_dir=$(dirname "$(realpath "$0")")
dir=$(realpath "$script_dir/../..")
cd "$dir" || exit

prog="./app.exe"

stream_in="./func_tests/data/$1"
expect="./func_tests/data/$2"
args="$3"

new_in_file="./func_tests/data/pos_${stream_in//[^0-9]/}_in_file_n.txt"
stdin="./func_tests/data/pos_${stream_in//[^0-9]/}_in.txt"
argv=$(cat "$args")

if grep -q '^st ' "$args"; then
    if ! $prog $argv < "$stdin" > /dev/null 2>&1; then
        exit 1
    fi
elif grep -q '^ft ' "$args"; then
    if ! $prog $argv < "$stdin" > "pos_out.txt"; then
        exit 1
    fi
elif grep -q '^at ' "$args"; then
    touch "$new_in_file"
    cat "$stream_in" > "$new_in_file"
    
    if ! $prog $argv < "$stdin" > /dev/null 2>&1; then
        exit 1
    fi
fi

if grep -q '^at ' "$args"; then
    "$script_dir"/comparator.sh "$new_in_file" "$expect"
else
    "$script_dir"/comparator.sh "pos_out.txt" "$expect"
fi
