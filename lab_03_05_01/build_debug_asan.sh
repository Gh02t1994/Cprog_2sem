#!/bin/bash

clang -std=c99 -Wall -Werror -Wextra -Wpedantic -Wvla -g -O0 -fsanitize=address -c *.c

clang *.o -fsanitize=address -lm -o app.exe