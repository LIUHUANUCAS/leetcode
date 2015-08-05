#!/bin/bash
filename=$1
#echo $filename
obj=${filename%%.*}
echo "execute filename is $obj"
g++ -g ./$filename -o  ./$obj -std=c++11
