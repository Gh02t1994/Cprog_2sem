#!/bin/bash

script_dir=$(dirname "$(realpath "$0")")
dir=$(realpath "$script_dir/../..")
cd "$dir" || exit

prog="./app.exe"

args="$1"

argv=$(cat "$args") 
if ! $prog $argv > /dev/null 2>&1; then
    exit 0
else
    exit 1
fi
