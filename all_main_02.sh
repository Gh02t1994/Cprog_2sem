#!/bin/bash

lab_dir=$(dirname "$(realpath "$0")")

cd "$lab_dir" || exit

for ((i=1; i<=3; i++)); do
    echo -e "\nLAB_02_0${i}_01\n"

    cd "lab_02_0${i}_01" || exit

    ./all.sh

    cd "$lab_dir" || exit
done


echo -e "\nLAB_01_04_02\n"

cd "lab_02_04_02" || exit

./all.sh

cd "$lab_dir" || exit


echo -e "\nLAB_01_05_00\n"

cd "lab_02_05_00" || exit

./all.sh

cd "$lab_dir" || exit