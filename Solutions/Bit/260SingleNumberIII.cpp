#include<iostream>
#include<vector>
#include <cstdlib>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;


/**
    doc


    000bit.cpp
*/

class Solution {

       public:
		vector<int> singleNumber(vector<int>& nums) {
			int a=0;
			int b=0;
			for(auto&e:nums){
				a^=e;
			}
			while(!(a&1) ){
				b++;
				a=a>>1;
			}
			int c = 1<<b;
			a=0;
			b=0;
			for(auto &e :nums){
				int t = e & c;
				if(t)
					a^=e;
				else
					b^=e;
			}
			vector<int> res={a,b};
			return res;
		}

};

int main(){
        Solution s;

		vector<int> nums={1,14,15,15,14,3,13,2,3,4,4,2,5,1};

		vector<int> res = s.singleNumber(nums);
		copy(res.begin(),res.end(),ostream_iterator<int>(cout," "));
		cout<<endl;
        return 0;

}
