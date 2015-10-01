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
    Say you have an array for which the ith element is the price of a given stock on day i.
    If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock),
    design an algorithm to find the maximum profit.

   121Best Time to Buy and Sell Stock.cpp
*/
/**
    Solutions:

    the question is looking for the max value of prices[k] - prices[j] where j < k
    so
    the question can extends to the max contiguous subarray if we change  array prices to a array nums
    where  nums[i] = prices[i]-prices[i-1] for i > 0
    for nums[i] the real meaning is that it stands for the profit we can draw from the buying stock on day i-1 and
    selling it on day i
    what's more
    a subarray such as nums[i]...nums[j] for i < j stands for the profit we draw from that we buy stock on day i and
    sell it on day j,that is prices[j] - prices[i]. prices[j] - prices[i] = sum(nums[i]...nums[j])


    the finally solution as bellow:

    sum[k] stands for the max contiguous subarray which ends with a[k];
    d[k]  stands for the max contiguous subarray at a[k];

    so
    sum[k] = max(sum[k-1]+a[k],a[k])

    d[k] = max(sum[k],d[k-1]);

*/

class Solution {

       public:
            int maxProfit(vector<int>& prices) {
                int size = prices.size();
                if(size == 0 || size == 1)
                    return 0;
                vector<int> nums;
                for(int i=1;i<size;++i){
                    nums.push_back(prices[i] - prices[i-1]);
                }

                return max(0,maxSubArray(nums));
            }
            int maxSubArray(vector<int>& nums) {
                int n = nums.size();
                if(n == 0)
                    return 0;
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
                return d[n-1];
            }

};

int main(){
        Solution s;
        vector<int> nums = {2,3,5,10,1,100};
//        vector<int> nums = {-2,1};
        int res = s.maxProfit(nums);
        cout<<res<<endl;
        cout<<"Dynamic programming"<<endl;
        return 0;

}
