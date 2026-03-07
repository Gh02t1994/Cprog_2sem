#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

pos_passed=0
pos_failed=0
pos_all=$(find ./func_tests/data -name "pos_*_in.txt" | grep -c .)

all_files=$(find ./func_tests/data -name "pos_*_in.txt" | sort)

echo -e "\n${GREEN}POSITIVE TESTS${NC}"
for file in $all_files; do
    out_file="pos_${file//[^0-9]/}_out.txt"
    if ./func_tests/scripts/pos_case.sh "$file" "$out_file"; then
    echo -e "File $(basename "$file") ${GREEN}PASSED${NC}"
    ((pos_passed++))
    else
    echo -e "File $(basename "$file") ${RED}FAILED${NC}"
    ((pos_failed++))
    fi
done

echo -e "Positive tests: ${GREEN}PASSED${NC} $pos_passed/$pos_all; ${RED}FAILED${NC} $pos_failed/$pos_all."

neg_passed=0
neg_failed=0
neg_all=$(find ./func_tests/data -name "neg_*_in.txt" | grep -c .)

all_files=$(find ./func_tests/data -name "neg_*_in.txt" | sort)

echo -e "\n${RED}NEGATIVE TESTS${NC}"
for file in $all_files; do
    if ./func_tests/scripts/neg_case.sh "$file"; then
    echo -e "File $(basename "$file") ${GREEN}PASSED${NC}"
    ((neg_passed++))
    else
    echo -e "File $(basename "$file") ${RED}FAILED${NC}"
    ((neg_failed++))
    fi
done

echo -e "Negative tests: ${GREEN}PASSED${NC} $neg_passed/$neg_all; ${RED}FAILED${NC} $neg_failed/$neg_all."

if [ $pos_failed -ne 0 ] || [ $neg_failed -ne 0 ]; then
    exit $((pos_failed + neg_failed))
else
    exit 0
fi