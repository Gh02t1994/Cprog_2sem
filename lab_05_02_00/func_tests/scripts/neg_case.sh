#!/bin/bash

script_dir=$(dirname "$(realpath "$0")")
prog=$(realpath "$script_dir/../../app.exe")

in_file="$1"

if ! "$prog" "$in_file" > /dev/null 2>&1; then
    exit 0
else
    exit 1
fi