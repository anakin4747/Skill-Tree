#!/bin/bash

count=3

if [ $count -eq 3 ]
then
    echo "square"
fi

if (( $count == 3 ))
then
    echo "round"
fi

if [ $count -gt 2 ] && [ $count -lt 5 ]
then
    echo "and1"
fi

if [[ $count -gt 2 && $count -lt 5 ]]
then
    echo "and2"
fi

if [ $count -gt 2 -a $count -lt 5 ]
then
    echo "and3"
fi

