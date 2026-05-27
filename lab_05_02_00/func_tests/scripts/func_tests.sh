#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

path_dir=$(dirname "$(realpath "$0")")
data_dir=$(realpath "$path_dir/../data")

pos_passed=0
pos_failed=0
pos_all=$(find "$data_dir" -name "pos_*_in.txt" | grep -c .)

all_args=$(find "$data_dir" -name "pos_*_args.txt" | sort)

echo -e "\n${GREEN}POSITIVE TESTS${NC}"
for args in $all_args; do
    file_name=$(basename "$args")
    out_file="pos_${file_name//[^0-9]/}_out.txt"

    if "$path_dir"/pos_case.sh "$out_file" "$args"; then
        echo -e "File $file_name ${GREEN}PASSED${NC}"
        ((pos_passed++))
    else
        echo -e "File $file_name ${RED}FAILED${NC}"
        ((pos_failed++))
    fi
done

echo -e "Positive tests: ${GREEN}PASSED${NC} $pos_passed/$pos_all; ${RED}FAILED${NC} $pos_failed/$pos_all."

neg_passed=0
neg_failed=0
neg_all=$(find "$data_dir" -name "neg_*_in.txt" | grep -c .)

all_args=$(find "$data_dir" -name "neg_*_args.txt" | sort)

echo -e "\n${RED}NEGATIVE TESTS${NC}"
for args in $all_args; do
    file_name=$(basename "$args")
    
    file="neg_${file_name//[^0-9]/}_in.txt"

    if "$path_dir"/neg_case.sh "$args"; then
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