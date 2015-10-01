#include<iostream>
#include<vector>
#include <cstdlib>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>

using namespace std;


/**
    doc
	Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

	For example:
	
	Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
	
	Follow up:
	Could you do it without any loop/recursion in O(1) runtime?
	
	Hint:
	
	A naive implementation of the above process is trivial. Could you come up with other methods?
	What are all the possible results?
	How do they occur, periodically or randomly?
	You may find this Wikipedia article useful.


    258AddDigits.cpp
*/
/**
	Solutions:
	you can use the loop the implementation the algorithm,what's more,you can also use the
	formulate as follow:
	dr(n) = n - (n-1)/9 * 9
	you can find the prove on the Wikipedia,where the website is :https://en.wikipedia.org/wiki/Digital_root
 *
*/

class Solution {

       public:
			int addDigits(int num){
				if(num < 0)
					return 0;
				while(num>9){
					int n = num%10;
					n+= num/10;
					num = n;
				}
				return num;
			
			}
			
			int addDigits2(int num){
				return num - (num-1) / 9 * 9;
			}
};

int main(){
        Solution s;
		int n;
		while(cin>>n){
			cout<<s.addDigits(n)<<endl;
		}
        return 0;

}
