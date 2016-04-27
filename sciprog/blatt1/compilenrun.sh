#!/bin/bash
# compile:
# -g for debug symbols
# -s strip away the unnecessary
# -O1 .. O3 for speed
# -Os for size
g++ main.cpp Rational.cpp -std=c++11 -s -o b1
# run it immediately
./b1
