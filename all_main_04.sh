#!/bin/bash

lab_dir=$(dirname "$(realpath "$0")")

cd "$lab_dir" || exit


echo -e "\nLAB_04_01\n"

cd "lab_04_01" || exit

./all.sh

cd "$lab_dir" || exit


for ((i=2; i<=4; i++)); do
    echo -e "\nLAB_04_0${i}_01\n"

    cd "lab_04_0${i}_01" || exit

    ./all.sh

    cd "$lab_dir" || exit
done