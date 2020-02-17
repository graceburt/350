#!/bin/bash

# Grace Burton
# Lab 02
# task6b.sh

for i in $(seq 1 5);
  do 
  	for j in $(seq 1 $i); 
  		do
  			echo -n "*"
  		done
  	echo
done
for k in $(seq 1 4); 
	do
    for p in $(seq 4 -1 $k); 
    	do
        echo -n "*"
    done
	echo
done

exit 0