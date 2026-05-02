#!/bin/bash

gcc -std=c99 -Wall -Werror -Wextra -Wpedantic -Wvla -O2 -c *.c

gcc *.o -lm -o app.exe