#!/bin/bash

# Define variables
unset var1  # var1 is unset
var2=""     # var2 is set to an empty string
var3="Hello, World!"  # var3 is set to a non-empty string

# Check if var1 is set using -v
if [[ -v var1 ]]; then
    echo "var1 is set"
else
    echo "var1 is not set"
fi

# Check if var2 is empty using -z
if [[ -z ${var2} ]]; then
    echo "var2 is an empty string"
else
    echo "var2 is not an empty string"
fi

# Check if var3 is non-empty using -n
if [[ -n ${var3} ]]; then
    echo "var3 is a non-empty string"
else
    echo "var3 is an empty string"
fi

