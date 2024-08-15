#!/bin/bash
users="admin tech expert"
for user in ${users}
do
	echo "${user}"
done

for num in {1..10}
do
	echo ${num}
done

items="bat ball gloves helmet pads"
for item in ${items}
do
	echo ${item}
done

counter=1
while [[ $counter -le 10 ]]
do
echo $counter
((counter++))
done

count=10
while [[ $count -ge 0 ]]
do
	echo $count
	((count--))
done

cnt=1
until [[ $cnt -gt 5 ]]
do
echo $cnt
((cnt++))
done
