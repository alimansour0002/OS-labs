#!/bin/bash
gcc publisher.c  -o publisher
gcc subscriber.c  -o subscriber
read n
for (( i=1; i<=$n; i++ ))
do  
   gnome-terminal  -- ./subscriber 
done
gnome-terminal  -- ./publisher $n
