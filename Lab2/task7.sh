#!/bin/bash

# Grace Burton
# Lab 02
# task7.sh

#**********NO SPACES BETWEEN = SIGN *******************

#When a function is called, the positional parameter the script 
#$*, $@, $#, $0, $1, $2, .. and so on are replaced 
#by the parameters to the function.

# fact ()
# {
# 	#i is going to be what is input in the "main" below

# 	local i="$1"
# 	local f

# 	# fact() is called until the value of $f is returned 
# 	#and is it is <= 2
# 	if [ "$i" -le 2 ]; 
# 	then
# 		echo "$i"
# 	else
# 		f=$(( i - 1))
# 		f=$(fact $f)
# 		f=$((f * i))
# 		echo "$f"
# 	fi

# }

# 	if [ $# -eq 0 ];
# 	then 
# 		echo "Error: no number inputted."
# 		exit 1
# 	fi

# 	fact "$1"

echo "Enter a positive integer"
read input

f=1
i="$input"

while [ $input -gt 0 ];
	  	do 
			f=$(($f * $input))
			input=$(($input - 1))
done

echo "The factorial of $i is $f"

if [ $input -eq 2 ];
then
	echo $input
fi


exit 0