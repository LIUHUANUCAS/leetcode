#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<sstream>
#include<iterator>
#include<cstring>
using namespace std;
/**
	doc:
		
		Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
		
		For example,
		"A man, a plan, a canal: Panama" is a palindrome.
		"race a car" is not a palindrome.
		
		Note:
		Have you consider that the string might be empty? This is a good question to ask during an interview.
		
		For the purpose of this problem, we define empty string as valid palindrome.
*/
bool isPalindrome(char *s) {
        size_t len = strlen(s);
     if(len == 0) return 1;
     size_t i=0,j=len-1;
     while(i< j){
        int f1 = isalnum(s[i]);
        if(!f1){
            i++;continue;
        }
        int f2 = isalnum(s[j]);
         if(!f2){
            j--;continue;
        }
        int res = s[i] - s[j];
        if(res == 0 || res == 'a'-'A' || res == 'A'-'a'){
            i++,j--;
        }
        else
            return 0;
     }
     return 1;
}
int main(){

	return 0;
}
