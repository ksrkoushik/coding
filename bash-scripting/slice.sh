#!/bin/bash
letters=("A""B""C""D""E")
echo ${letters[@]}
echo ${letters:0:2}
b=${letters:0:2}
echo ${b}

new=(ABCDEF)
echo ${new[@]}
echo ${new:0:2}
c=${new:2:4}
echo $c
