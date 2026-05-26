#!/bin/bash

script_dir=$(dirname "$(realpath "$0")")
prog=$(realpath "$script_dir/../../app.exe")

in_file="$1"
file_out="$(realpath "$script_dir/../data")/$2"

$prog "$in_file" > "pos_out.txt"

"$script_dir"/comparator.sh "pos_out.txt" "$file_out"