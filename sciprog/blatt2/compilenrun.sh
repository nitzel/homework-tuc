#!/bin/bash
# compile:
# -g for debug symbols
# -s strip away the unnecessary
# -O1 .. O3 for speed
# -Os for size
g++ Node.cpp List.cpp main.cpp -std=c++11 -g -o b2
# run it immediately
./b2
