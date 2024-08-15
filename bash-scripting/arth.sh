#!/bin/bash
read -p "Enter number1: " num1
echo "$num1"
read -p "Enter number2: " num2
echo "$num2"
if [[ ${num1} == ${num2} ]]; then
        echo "Both nums are equal"
elif [[ ${num1} != ${num2} ]]; then
        echo "Both nums are not equal"
        if [[ ${num1} > ${num2} ]]; then
                echo "num1 is greater than num2"
        elif [[ ${num1} < ${num2} ]]; then
                echo "num1 is less than num2"
        fi
else
        echo "Invalid numbers"
fi


