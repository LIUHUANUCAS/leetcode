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



    name.cpp
*/

class Solution {

       public:
		int trailingZeroes(int n) {
			if(n<=0)
				return 0;
			int count=0;
			while(n){
				count+=n/5;
				n/=5;
			}
			return count;
			/*	for(int i=5;i<=n;i*=5){
				count+= n/i;
			}
			return count;
*/
		}
};

int main(){
        Solution s;
		int n = 100;
		while(cin>>n){
			cout<<n<<endl;
		int res = s.trailingZeroes(n);
		cout<<res<<endl;
		}
        return 0;

}
