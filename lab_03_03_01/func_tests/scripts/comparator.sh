#!/bin/bash

nums1=$(perl -0777 -ne 's/.*://; print join(" ", /(?<![a-zA-Z.])-?\d+(?:\.\d+)?(?!\.?[a-zA-Z0-9])/g)' "$1")
nums2=$(perl -0777 -ne 's/.*://; print join(" ", /(?<![a-zA-Z.])-?\d+(?:\.\d+)?(?!\.?[a-zA-Z0-9])/g)' "$2")

if [ "$nums1" = "$nums2" ]; then
    exit 0
else
    exit 1
fi