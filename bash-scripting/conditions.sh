#!/bin/bash

# Define the file name
file="example.txt"

# Create the file for demonstration purposes
touch ${file}

# Check if the file exists
if [[ -e ${file} ]]; then
    echo "File '${file}' exists."
else
    echo "File '${file}' does not exist."
fi

# Remove the file after the check
#rm ${file}

