#!/bin/bash

nums1=$(cat "$1")
nums2=$(cat "$2")

if [ "$nums1" = "$nums2" ]; then
    exit 0
else
    exit 1
fi