#!/bin/bash
admin="devdojo"
read -p "Enter your username:" username
if [[ ${username} == ${admin} ]]; then
	echo "You are the admin user"
else
	echo "You are not the admin user"
fi


