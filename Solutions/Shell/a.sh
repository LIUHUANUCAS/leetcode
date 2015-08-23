#!/bin/bash
cat words.txt |tr -s ' ' '\n' | sort | uniq -c | sort -k1 -r | awk '{print $2 " " $1}' 
#cat words.txt | sed 's/ \{1,\}/\n/g' | sort | uniq -c | sort -k1 -r | awk '{print $2 " " $1}' 
#awk '{print $2 \' $1}'

#cmd=`cat words.txt | sed 's/ \{1,\}/\n/g' | sort `

