#!/bin/bash

gcc -std=c99 -Wall -Werror -Wextra -Wpedantic -Wfloat-equal -Wfloat-conversion -g -O0 -fsanitize=address -c main.c -o main.o

gcc  main.o -fsanitize=address -lm -o app.exe