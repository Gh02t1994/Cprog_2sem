#!/bin/bash

clang -std=c99 -Wall -Werror -Wextra -Wpedantic -Wfloat-equal -Wfloat-conversion -g -O0 -fsanitize=undefined -c main.c -o main.o

clang  main.o -fsanitize=undefined -lm -o app.exe