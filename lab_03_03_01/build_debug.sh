#!/bin/bash

gcc -std=c99 -Wall -Werror -Wextra -Wpedantic -Wvla -g -O0 -c *.c

gcc *.o -lm -o app.exe