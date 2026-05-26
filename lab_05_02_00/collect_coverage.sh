#!/bin/bash

GREEN='\033[0;32m'
NC='\033[0m'

gcc --coverage *.c -lm -o app.exe

./func_tests/scripts/func_tests.sh > /dev/null 2>&1


gcov app.exe-main.gcda > "coverage_1.txt"

sec_line=$(head -n 2 "coverage_1.txt" | tail -n 1)

persentage=$(echo "$sec_line" | grep -o '[0-9.]*%')

echo -e "\n${GREEN}COVERAGE RATION MAIN${NC} $persentage"


gcov app.exe-functions.gcda > "coverage_3.txt"

sec_line=$(head -n 2 "coverage_3.txt" | tail -n 1)

persentage=$(echo "$sec_line" | grep -o '[0-9.]*%')

echo -e "\n${GREEN}COVERAGE RATION FUNCTIONS${NC} $persentage"