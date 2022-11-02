#!/bin/bash

gcc -pthread ex4.c -o ex4
for i in 1 2 4 10 100
do
     \time -o ex4.txt -a ./ex4 10000000 $i
done

# Write the script for compiling and running your program as specified in the task description.
