#!/bin/bash
echo "Hello World!"
read -p "Enter your name" name
echo "$name"
echo "Arg one is $1"
echo "Arg two is $2"
echo "Arg all is $@"
