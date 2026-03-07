#!/bin/bash

gcc -std=c99 -Wall -Werror -Wextra -Wpedantic -Wfloat-equal -Wfloat-conversion -g -O0 -fsanitize=undefined -c main.c -o main.o

gcc  main.o -fsanitize=undefined -lm -o app.exe