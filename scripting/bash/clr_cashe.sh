#!/bin/bash

# A bash Script to remove files but keep file structure

for DIRECTORY in $( ls -lR | grep ^.*:$ | sed 's/.$//' ) $PWD
# List everything recursively - ls -lR
# filter for directories - grep ^.*:$
# Remove semicolon from directories - sed 's/.$//'
do
	for FILE in $( ls -l $DIRECTORY | grep [-][r-][w-][x-][r-][w-][x-][r-][w-][x-] | rev | cut -d " " -f 1 | rev )
	do
		rm $DIRECTORY/$FILE
	done
done
