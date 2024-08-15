#!/bin/bash

# Define the file name
file="example1.txt"
dir="example_dir"
block_device="/dev/sda"
char_device="/dev/tty"

# Create the file and directory for demonstration purposes
touch ${file}
mkdir ${dir}

# Check if the file exists
if [[ -e ${file} ]]; then
    echo "'${file}' exists."
fi

# Check if it is a regular file
if [[ -f ${file} ]]; then
    echo "'${file}' is a regular file."
fi

# Check if it is a directory
if [[ -d ${dir} ]]; then
    echo "'${dir}' is a directory."
fi

# Check if the file is readable
if [[ -r ${file} ]]; then
    echo "'${file}' is readable."
fi

# Check if the file is writable
if [[ -w ${file} ]]; then
    echo "'${file}' is writable."
fi

# Check if the file is executable
if [[ -x ${file} ]]; then
    echo "'${file}' is executable."
fi

# Check if the file is non-empty
if [[ -s ${file} ]]; then
    echo "'${file}' is not empty."
fi

# Check if it is a block special file
if [[ -b ${block_device} ]]; then
    echo "'${block_device}' is a block special file."
fi

# Check if it is a character special file
if [[ -c ${char_device} ]]; then
    echo "'${char_device}' is a character special file."
fi

# Check if it is a symbolic link
if [[ -L ${file} ]]; then
    echo "'${file}' is a symbolic link."
fi

# Check if it is a named pipe (FIFO)
if [[ -p ${file} ]]; then
    echo "'${file}' is a named pipe."
fi

# Check if it is a socket
if [[ -S ${file} ]]; then
    echo "'${file}' is a socket."
fi

# Clean up the created file and directory
#rm ${file}
#rmdir ${dir}

