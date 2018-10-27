#!/bin/sh
echo "Enter no of strings"
read n
for ((i=0;i<$n;i++))
do
echo "Enter a string"
read str[$i]
done
for ((i=0;i<$n;i++))
do
for ((j=0;j<$(($n-1-$i));j++))
do
if [ "${str[$j]}" \> "${str[$(($j+1))]}" ]
then
temp=${str[$j]}
str[$j]=${str[$(($j+1))]}
str[$(($j+1))]=$temp
fi
done
done
echo ${str[@]:0}
