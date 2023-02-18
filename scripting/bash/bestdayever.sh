#!/bin/bash

name=$1
compliment=$2

user=$(whoami)
today=$(date)
folder=$(pwd)

echo "fghjk $name"
sleep 1
echo "dfghjkl $name"
sleep 1
echo "fghj $name"
sleep 2

echo "You are currently logged in as $user and you are in the directory $folder. Also today is $today"

