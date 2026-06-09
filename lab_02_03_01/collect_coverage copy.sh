#!/bin/bash

GREEN='\033[0;32m'
NC='\033[0m'

gcc --coverage main.c -lm -o app_cov.exe

./func_tests/scripts/func_tests.sh

gcov app_cov.exe-main.gcda > "coverage.txt"

sec_line=$(head -n 2 "coverage.txt" | tail -n 1)

persentage=$(echo "$sec_line" | grep -o '[0-9.]*%')

echo -e "\n${GREEN}COVERAGE RATION${NC} $persentage"