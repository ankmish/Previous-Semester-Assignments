#!/bin/sh

for ((i=0;i<5;i++))
do
echo "Enter a number"
read n
if [ $i -eq 0 ]
then
no[0]=$n
else
j=$(($i-1))
while [ $j -ge 0 ]
do
if [ ${no[$j]} -gt $n ]
then
no[$(($j+1))]=${no[$j]}
j=`expr $j - 1`
fi
done
no[$(($j+1))]=$n
fi
done
echo ${no[@]:0}