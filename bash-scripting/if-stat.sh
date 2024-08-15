#!/bin/bash
read -p "What is your name?" name
if [[ -z ${name} ]]
then
	read -p "Please enter your name" name
	echo "Hi ${name}, how can i help you?"
else
	echo "Hi ${name}"
fi

