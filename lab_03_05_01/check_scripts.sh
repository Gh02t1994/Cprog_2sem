#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

files=("build_debug.sh" "build_debug_asan.sh" "build_debug_ubsan.sh" "build_release.sh" "clean.sh" "collect_coverage.sh" "./func_tests/scripts/comparator.sh" "./func_tests/scripts/func_tests.sh" "./func_tests/scripts/neg_case.sh" "./func_tests/scripts/pos_case.sh")

for file in "${files[@]}"; do
if [ -e "$file" ]; then
    echo -e "${GREEN}EXIST${NC} $(basename "$file")"
else
    echo -e "${RED}NOT EXIST${NC} $(basename "$file")"
fi
done

chmod +x ./*.sh
chmod +x ./func_tests/scripts/*.sh