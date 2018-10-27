#!/bin/sh
age()
{
    return $((2017-$1))
}
echo "Enter birth year"
read doby
age doby
a=$?
echo "Age is $a"
