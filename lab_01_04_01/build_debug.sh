#!/bin/bash

gcc -std=c99 -Wall -Werror -Wextra -Wpedantic -Wfloat-equal -Wfloat-conversion -g -O0 -c main.c

gcc main.o -lm -o app.exe