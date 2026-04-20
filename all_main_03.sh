#!/bin/bash

lab_dir=$(dirname "$(realpath "$0")")

cd "$lab_dir" || exit

for ((i=1; i<=6; i++)); do
    echo -e "\nLAB_03_0${i}_01\n"

    cd "lab_03_0${i}_01" || exit

    ./all.sh

    cd "$lab_dir" || exit
done