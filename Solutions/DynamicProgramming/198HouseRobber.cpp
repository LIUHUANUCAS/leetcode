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

    You are a professional robber planning to rob houses along a street.
    Each house has a certain amount of money stashed,
    the only constraint stopping you from robbing each of them is that
    adjacent houses have security system connected and it will automatically contact the police
    if two adjacent houses were broken into on the same night.

    Given a list of non-negative integers representing the amount of money of each house,
    determine the maximum amount of money you can rob tonight without alerting the police.

    Credits:
    Special thanks to @ifanchu for adding this problem and creating all test cases. Also thanks to @ts for adding additional test cases.

    Hide Tags Dynamic Programming
    Show Similar Problems


    198House Robber.cpp
*/

class Solution {

       public:

            int rob1(vector<int>& nums) {
                int n = nums.size();
                if(n == 0)
                    return 0;
                if(n == 1)
                    return nums[0];

                if(n == 2)
                    return max(nums[0],nums[1]);

                vector<int> d(n,0);
                d[0] = nums[0];
                d[1] = max(nums[1],nums[0]);
                for(int i=2;i<n;++i){
                    int dn = nums[i] + d[i-2];
                    d[i] = max(dn,d[i-1]);
                }

                return d[n-1];
            }

              int rob(vector<int>& nums) {
                int n = nums.size();
                if(n == 0)
                    return 0;
                if(n == 1)
                    return nums[0];
                if(n == 2)
                    return max(nums[0],nums[1]);
                int a  = nums[0];
                int b  = nums[1];
                b = max(a,b);
                for(int i=2;i<n;++i){
                    int dn = nums[i] + a;
                    dn = max(dn,b);
                    a = b;
                    b = dn;
                }
                return b;
            }

};

int main(){
        Solution s;
        vector<int > nums = {4,3,2,3};
        int res = s.rob(nums);
        cout<<res<<endl;
        cout<<"Dynamic programming"<<endl;
        return 0;

}
