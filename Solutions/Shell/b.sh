#!/bin/bash
rows=`cat file.txt | wc -l`
cols=`cat file.txt| awk 'NR==1' | tr -s ' ' '\n' | wc -l`
echo $rows
echo $cols
for((i=1;i<=$cols;++i))
do
	for((j=1;j<=$rows;++j))
	do

	done
done
