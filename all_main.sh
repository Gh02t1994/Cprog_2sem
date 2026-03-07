#!/bin/bash

for ((i=2; i<=4; i++)); do
    echo -e "\nLAB_01_0${i}_01\n"

    cd "lab_01_0${i}_01"

    ./all.sh

    cd ..
done

for ((i=5; i<=7; i++)); do
    echo -e "\nLAB_01_0${i}_05\n"

    cd "lab_01_0${i}_05"

    ./all.sh

    cd ..
done

for ((i=8; i<=9; i++)); do
    echo -e "\nLAB_01_0${i}_01\n"

    cd "lab_01_0${i}_01"

    ./all.sh

    cd ..
done