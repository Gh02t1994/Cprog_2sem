#!/bin/bash

script_dir=$(dirname "$(realpath "$0")")
dir=$(realpath "$script_dir/../..")
cd "$dir" || exit

prog="./app.exe"

touch "./func_tests/data/in.bin"
bin="./func_tests/data/in.bin"

stream_in="./func_tests/data/$1"
expect="./func_tests/data/$2"
args="$3"

argv=$(cat "$args")

if grep -q '^p ' "$args"; then
    $prog "import" "$stream_in" "$bin"
    $prog $argv > "pos_out.txt"
elif grep -q '^s ' "$args"; then
    $prog "import" "$stream_in" "$bin"
    $prog $argv
    $prog "export" "$bin" "pos_out.txt"
fi

rm "$bin"

"$script_dir"/comparator.sh "pos_out.txt" "$expect"