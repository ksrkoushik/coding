#!/bin/bash
my_array=("sri" "1" "45" "-25" "vish")
echo "${my_array[0]}"
echo "${my_array[4]}"
echo "${my_array[@]}"
echo "${#my_array[@]}"
# we can also pass the array without quotes
echo ${my_array[1]}
# inside the array also we can pass without quotes
new=(vish dhruv)
echo ${new[1]}
echo ${new[@]}
echo ${#new[@]}
