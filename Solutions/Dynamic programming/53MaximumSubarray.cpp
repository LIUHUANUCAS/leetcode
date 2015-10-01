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

    Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

    For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
    the contiguous subarray [4,-1,2,1] has the largest sum = 6.

    click to show more practice.

    More practice:
    If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach,
    which is more subtle

    53Maximum Subarray.cpp
*/
/**
    Solutions:
    sum[k] stands for the max contiguous subarray which ends with a[k];
    d[k]  stands for the max contiguous subarray at a[k];

    so
    sum[k] = max(sum[k-1]+a[k],a[k])

    d[k] = max(sum[k],d[k-1]);

*/

class Solution {

       public:
            int maxSubArray(vector<int>& nums) {
                int n = nums.size();
                if(n == 0)return 0;
                if(n == 1)
                    return nums[0];

                vector<int> d(n,0);
                vector<int> sum(n,0);
                sum[0] = nums[0];
                d[0] = nums[0];

                for(int i=1;i<n;++i){
                    int tsum = sum[i-1] + nums[i];
                    sum[i] = max(tsum,nums[i]);
                    d[i] = max(sum[i],d[i-1]);
                }
//                copy(sum.begin(),sum.end(),ostream_iterator<int>(cout," "));
//                cout<<endl;
                return d[n-1];
            }

};

int main(){
        Solution s;
        vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
//        vector<int> nums = {-2,1};
        int res = s.maxSubArray(nums);
        cout<<res<<endl;
        cout<<"Dynamic programming"<<endl;
        return 0;

}
