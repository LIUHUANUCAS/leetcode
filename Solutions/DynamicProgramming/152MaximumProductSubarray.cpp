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

    Find the contiguous subarray within an array (containing at least one number) which has the largest product.

    For example, given the array [2,3,-2,4],
    the contiguous subarray [2,3] has the largest product = 6.

    Hide Tags Array Dynamic Programming
    Show Similar Problems


    152Maximum Product Subarray.cpp
*/
/**
    Solutions:
    smax[k] stands for the max contiguous subarray product which ends with a[k];
    smin[k] stands for the min contiguous subarray product which ends with a[k];

    so
    smax[0] = a[0]
    smin[0] = a[0]
    smax[k] = max of    smax[k-1] * a[k] if a[k] > 0
                        smin[k-1] * a[k] if a[k] < 0
    smax[k] = max(smax[k],a[k])

    smin[k] = min of    smax[k-1] * a[k] if a[k] < 0
                        smin[k-1] * a[k] if a[k] > 0

    smin[k] = min(smin[k],a[k])

    finally

    the max contiguous subarray product is max(smax)
    the min contiguous subarray product is min(smin)

*/

class Solution {

       public:

            int maxProduct(vector<int>& nums) {

                int n = nums.size();
                if(n == 0)
                    return 0;
                if(n == 1)
                    return nums[0];
                if(n == 2){
                    int tmp = max(nums[0],nums[0]*nums[1]);
                    return max(tmp,nums[1]);
                }

                vector<int> smax(n,1);
                vector<int> smin(n,1);
                smax[0] = nums[0];
                smin[0] = nums[0];
                for(int i=1;i<n;++i){
                    int a = nums[i] * smax[i-1];
                    int b = nums[i] * smin[i-1];
                    smax[i] = max(a,b);
                    smax[i] = max(smax[i],nums[i]);
                    smin[i] = min(a,b);
                    smin[i] = min(smin[i],nums[i]);

                }
                return *max_element(smax.begin(),smax.end());
            }

};

int main(){
        Solution s;
//        vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
        vector<int> nums = {2,-3,1,-1,3,-5};
        //{2,3,-2,-4,-5};
        int res = s.maxProduct(nums);
        cout<<res<<endl;
        cout<<"Dynamic programming"<<endl;
        return 0;

}
