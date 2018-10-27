#!/bin/sh

for ((i=0;i<10;i++))
do
echo "Enter a no"
read no[$i]
done
for ((i=0;i<10;i++))
do
for ((j=0;j<$((9-$i));j++))
do
if [ ${no[$j]} -gt ${no[$(($j+1))]} ]
then
temp=${no[$j]}
no[$j]=${no[$(($j+1))]}
no[$(($j+1))]=$temp
fi
done
done
echo ${no[@]:0}