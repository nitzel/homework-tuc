#!/bin/bash
# compile:
# -g for debug symbols
# -s strip away the unnecessary
# -O1 .. O3 for speed
# -Os for size
g++ List.cpp main.cpp -std=c++11 -g -o b3
# run it immediately
./b3
