#!/bin/bash

clang -std=c99 -Wall -Werror -Wextra -Wpedantic -g -O0 -fsanitize=address -c main.c -o main.o

clang  main.o -fsanitize=address -lm -o app.exe