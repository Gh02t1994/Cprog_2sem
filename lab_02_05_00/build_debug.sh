#!/bin/bash

gcc -std=c99 -Wall -Werror -Wextra -Wpedantic -Wvla -g -O0 -c main.c

gcc main.o -lm -o app.exe