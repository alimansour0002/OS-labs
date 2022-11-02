#!/bin/bash

gcc -pthread ex3.c -o ex3
for i in 1 2 4 10 100
do
     \time -o ex3.txt -a ./ex3 10000000 $i
done

# Write the script for compiling and running your program as specified in the task description.
