#!/bin/bash
echo "building..."

rm -f main.o
rm -f test
g++ -Wall -g -std=c++11 -c simplog.c
g++ -Wall -g -std=c++11 -c main.cc
g++ -Wall -g -std=c++11 -o test main.o simplog.o -pthread -lwiringPi

rm -f main.o
rm -f simplog.o

echo "complete"