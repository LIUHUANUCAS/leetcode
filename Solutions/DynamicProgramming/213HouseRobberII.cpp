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

    Note: This is an extension of House Robber.

    After robbing those houses on that street, the thief has found himself a new place for his thievery
    so that he will not get too much attention.

    This time, all houses at this place are arranged in a circle.
    That means the first house is the neighbor of the last one. Meanwhile,
    the security system for these houses remain the same as for those in the previous street.

    Given a list of non-negative integers representing the amount of money of each house,
    determine the maximum amount of money you can rob tonight without alerting the police.


    213House RobberII.cpp
*/

class Solution {

       public:
           int rob(vector<int>&nums){
                int size = nums.size()-1;
                if(size+1 == 0 )
                    return 0;
                if(size+1 == 1)
                    return nums[0];
                if(size +1 == 2)
                    return max(nums[0],nums[1]);

                int d1 = rob3(nums,0,size-1);
                int d2 = rob3(nums,1,size);
                return max(d1,d2);
           }
            int rob3(vector<int>&nums,int begin,int end){
                if(begin == end)
                    return nums[end];
                if(begin > end)
                    return 0;
                if(end - begin == 1)
                    return max(nums[begin],nums[end]);
                int n = end - begin + 1;
                vector<int> d(n,0);
                d[0] = nums[begin];
                d[1] = max(nums[begin],nums[begin+1]);
                for(int i=begin+2,j=0;i<=end;++i){

                    int dn = nums[i] + d[i-begin-2];
                    d[i-begin] = max(dn,d[i-begin-1]);
                }
                return d[n-1];
            }


            int robk(vector<int>& nums) {
                int n = nums.size();
                if(n == 0)
                    return 0;
                if(n == 1)
                    return nums[0];

                if(n == 2)
                    return max(nums[0],nums[1]);

                vector<int> d(n,0);
                vector<int> flag(n,0);
                d[0] = nums[0];
                d[1] = max(nums[1],nums[0]);
                flag[0] = 1;
                if(nums[1] >= nums[0])
                        flag[1] = 0;
                else
                        flag[1] = 1;
                for(int i=2;i<n;++i){
                    int dn = nums[i] + d[i-2];
                    if(dn > d[i-1]){
                        flag[i] = flag[i-2];
                        d[i] = dn;
                    }
                    else{
                        flag[i] = flag[i-1];
                        d[i] = d[i-1];
                    }
//                    d[i] = max(dn,d[i-1]);
                    copy(nums.begin(),nums.end(),ostream_iterator<int>(cout," "));
                    cout<<endl;
                    copy(d.begin(),d.end(),ostream_iterator<int>(cout," "));
                    cout<<endl;
                     copy(flag.begin(),flag.end(),ostream_iterator<int>(cout," "));
                    cout<<endl;

                }
//                 copy(flag.begin(),flag.end(),ostream_iterator<int>(cout," "));
//                    cout<<endl;

//                for(int i=n-1;i>=0;++i)
//                    if(flag[i] !=0)
//                        return d[i];
//                return d[n-2];
//                return d[n-1];
                if(flag[n-1])
                    return d[n-2];
                else
                    return d[n-1];
            }

              int rob2(vector<int>& nums) {
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
//        vector<int > nums = {1,1,3,6,7,10,7,1,8,5,9,1,4,4,3};
        vector<int > nums = {2};
        int res = s.rob(nums);
        cout<<res<<endl;
        cout<<"Dynamic programming"<<endl;
        return 0;

}
