#!/bin/bash

lab_dir=$(dirname "$(realpath "$0")")

cd "$lab_dir" || exit


echo -e "\nLAB_05_01_05\n"

cd "lab_05_01_05" || exit

./all.sh

cd "$lab_dir" || exit


echo -e "\nLAB_05_02_00\n"

cd "lab_05_02_00" || exit

./all.sh

cd "$lab_dir" || exit


echo -e "\nLAB_05_03\n"

cd "lab_05_03" || exit

./all.sh

cd "$lab_dir" || exit


echo -e "\nLAB_05_04_02\n"

cd "lab_05_04_02" || exit

./all.sh

cd "$lab_dir" || exit