#!/bin/bash

./build_debug_asan.sh
./build_debug_ubsan.sh
./build_debug.sh
./build_release.sh
./check_scripts.sh
./collect_coverage.sh
./clean.sh