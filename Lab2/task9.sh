#!/bin/bash

# Grace Burton
# Lab 02
# task9.sh

echo "In which DIRECTORY is the file located?"
read dir

if [ -d $dir ];
then 
	ls -al $dir
	att=$((0))
		while [ $att -ne 3 ]
		do
			echo "Which FILE would you like to search in?"
			read fil
			if [ -e $fil ];
			then

				echo "What WORD would you like to search?"
				read word
				if [ grep $word $fil ];
				then
					echo "$word FOUND!"
					exit 0;
				else
					echo "$word NOT FOUND!"
				fi

			else

				echo "there is no file $fil"
				att=$(($att+1))

			fi
		done

	echo $error
	exit 2;

else
	echo $error
	exit 1;
fi