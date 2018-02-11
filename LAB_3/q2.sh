#!/bin/bash

echo 'Enter the size of array:'
read size
echo Enter $size values:
read -a arr
echo Prime Numbers are:
for num in "${arr[@]}"
do
    flag=0
    half=$(expr $num/2 |bc)
    for i in `seq 2 $half`
    do
        #rem=$(expr $num % $i)
        if [ $(expr $num % $i) -eq 0 ]
        then
            flag=1
            break
        fi
    done
    if [ $flag -eq 0 ]
    then
        echo $num
    fi
done
