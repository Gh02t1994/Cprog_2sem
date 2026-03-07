#!/bin/bash

prog=./app.exe
in_file="$1"

if ! "$prog" < "$in_file" > /dev/null 2>&1; then
    exit 0
else
    exit 1
fi