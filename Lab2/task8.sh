#!/bin/bash

# Grace Burton
# Lab 02
# task8.sh


echo "Please enter one positive integer"
read input

num=$input
sec=$(($num - 1))

while [ $sec -ne 0 ];
do
		num=$(($num + $sec))
		sec=$(($sec - 1))
done 

echo $num