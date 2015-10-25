#include<iostream>
#include<vector>
#include<cstdlib>
#include<iterator>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;


/**
    doc


    000cpptemplate.cpp
*/

class Solution {

       public:
		bool isUgly(int num){
			if(num <= 0)
				return 0;
			if(num==1)
				return 1;
			while(num%2 == 0){
				num/=2;
			}
			while(num %3 == 0){
				num/=3;
			}
			while(num % 5 == 0)
				num/=5;
			if(num !=1)
				return 0;
			else
				return 1;
			/*
			while(num){
				if(num&1==0){
					num/=2;
				}else if(num %3 == 0){
					num/=3;
				}else if(num%5 == 0){
					num/=5;
				}else
					break;
			}*/
		
		}
};

int main(){
        Solution s;
		int n;
		while(cin>>n)
			cout<<s.isUgly(n)<<endl;
        return 0;
}
