#!/bin/sh
g++ -std=c++1z -O2 -Wall $1 $2 -o two.out
./two.out
