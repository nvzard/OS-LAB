#!/bin/bash

echo 'Employee Name: '
read emp_name
echo 'Department:'
read depart
echo 'Basic Salary:'
read bs

if [ $bs -gt 10000 ]
then
    hra_temp=$(expr 'scale=2; 15/100' |bc)
    hra=$(expr "scale=2;$hra_temp*$bs" |bc)
    da_temp=$(expr "scale=2; 25/100" |bc)
    da=$(expr "scale=2;$da_temp*$bs" |bc)
    au_temp=$(expr "scale=2; 5/100" |bc)
    au=$(expr "scale=2;$au_temp*$bs" |bc)
else
    hra_temp=$(expr 'scale=2; 13/100' |bc)
    hra=$(expr "scale=2;$hra_temp*$bs" |bc)
    da_temp=$(expr "scale=2; 20/100" |bc)
    da=$(expr "scale=2;$da_temp*$bs" |bc)
    au_temp=$(expr "scale=2; 3/100" |bc)
    au=$(expr "scale=2;$au_temp*$bs" |bc)
fi

echo '\nHRA:'
echo $hra
echo 'DA:'
echo $da
echo 'AU:'
echo $au
