#!/bin/bash

clang -std=c99 -Wall -Werror -Wextra -Wpedantic -g -O0 -fsanitize=undefined -c main.c -o main.o

clang  main.o -fsanitize=undefined -lm -o app.exe