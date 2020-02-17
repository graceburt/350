#!/bin/bash

# Grace Burton
# Lab 02
# task6c.sh

echo "Pick a number between 5 and 9"
read var

while [ $var -lt 5 -o $var -gt 9 ]; do
	echo "Incorrect input, try again!"
	echo "Pick a number between 5 and 9"
	read var
done
	#calculate spaces based on value of var
	# for k in $(seq 1 $var); 
	# 	do
	# 	    for p in $(seq $var -1 $k); 
	# 	    	do
	# 	        echo -n "0"
	#     done
	# 	echo
	# done

	#print out the number based on var
	for i in $(seq 1 $var);
	  do 
	  	for j in $(seq $i $var); 
	  		do
	  			echo -n " "
	  		done
	  	for j in $(seq 1 $i); 
	  		do
	  			echo -n " $i"
	  		done
	  	echo
	  done 

exit 0;
