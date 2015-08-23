#!/bin/bash
#	Given a text file file.txt, transpose its content.
#	You may assume that each row has the same number of columns and each field is separated by the ' ' character.
#	For example, if file.txt has the following content:
#	name age
#	alice 21
#	ryan 30
#	Output the following:
#	name alice ryan
#	age 21 30

awk '{
  for(i=1;i<=NF;i++)
	  {
		  a[FNR,i]=$i
	  }
  }
  END{
	for(i=1;i<=NF;i++)
	{
		for(j=1;j<=FNR;j++)
			if(j!=FNR)
				{printf a[j,i]" "}
			else
				{
					printf a[j,i]
				}

			print ""
	}
	} ' file.txt
