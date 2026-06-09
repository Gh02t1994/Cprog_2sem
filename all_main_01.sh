#!/bin/bash

lab_dir=$(dirname "$(realpath "$0")")

cd "$lab_dir" || exit

for ((i=2; i<=4; i++)); do
    echo -e "\nLAB_01_0${i}_01\n"

    cd "lab_01_0${i}_01" || exit

    ./all.sh

    cd "$lab_dir" || exit
done

for ((i=5; i<=7; i++)); do
    echo -e "\nLAB_01_0${i}_05\n"

    cd "lab_01_0${i}_05" || exit

    ./all.sh

    cd "$lab_dir" || exit
done

for ((i=8; i<=9; i++)); do
    echo -e "\nLAB_01_0${i}_01\n"

    cd "lab_01_0${i}_01" || exit

    ./all.sh

    cd "$lab_dir" || exit
done