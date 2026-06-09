#!/bin/bash

task_dir=$(dirname "$(realpath "$0")")

cd "$task_dir" || exit

./clean.sh

./check_scripts.sh

echo -e "\nDEBUG TESTING"
./build_debug.sh
./func_tests/scripts/func_tests.sh
./clean.sh

echo -e "\nASAN TESTING"
./build_debug_asan.sh
./func_tests/scripts/func_tests.sh 
./clean.sh

echo -e "\nUBSAN TESTING"
./build_debug_ubsan.sh
./func_tests/scripts/func_tests.sh
./clean.sh

echo -e "\nRELEASE TESTING"
./build_release.sh
./func_tests/scripts/func_tests.sh
./clean.sh

./collect_coverage.sh

./clean.sh