#!/bin/bash
str1="Srikanth"
str2="Vishnutej"
if [[ ${str1} == ${str2} ]]; then
	echo "Both strings are equal"
elif [[ ${str1} != ${str2} ]]; then
	echo "Both strings are not equal"
	if [[ ${str1} > ${str2} ]]; then
		echo "str1 is greater than str2"
	elif [[ ${str1} < ${str2} ]]; then
		echo "str1 is less than str2"
	fi
else
	echo "Invalid strings"
fi

