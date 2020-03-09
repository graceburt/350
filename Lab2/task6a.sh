#!/bin/sh

# Grace Burton
# Lab 02
# task6b.sh

# default = "$PS1"
# PS1 = "[COSC350 \W]:"
# PS1 = "$default"

for i in $(seq 1 5);
  do 
  	for j in $(seq 1 $i); 
  		do
  			echo -n "$i"
  		done
  	echo
  done 

exit 0