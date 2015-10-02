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
    Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

    Solve it without division and in O(n).
    
    For example, given [1,2,3,4], return [24,12,8,6].

    000cpptemplate.cpp
*/

/**
    Solutions：
    there are n numbers,so the problem is to get the product of 
    Ak = a1*a2*a3……an / k = a1 * a2 *……a(k-1) * a(k+1) * a(k+2)*……an
    we can get the truth that the value of Ak is the product of  ak left numbers and the ak right numbers
    so we can get the value of ak left numbers product -- we can pass through the left to the right of the Array,and then get the
    product before ak
    Simaliarly,we can pass the Array from the right to the left,thus we can get the product after ak
    Finally,the product except ak will be solved.
    Good idea...
      
*/

class Solution {

       public:
       
        vector<int> productExceptSelf(vector<int>& nums) {
            vector<int> res(nums.size(),1);
            for(int i =1;i < nums.size();++i){
                res[i] = res[i-1] * nums[i-1];
            }
            
            int right = 1;
            for(int i = nums.size()-1;i>=0;--i){
                res[i] = right * res [i];
                right *= nums[i]; 
            }
            
            return res;
        
        }

};

int main(){
        Solution s;
        vector<int> nums = {1,2,3,4,5,8,7,6};
        vector<int> res =s.productExceptSelf(nums);
        copy(res.begin(),res.end(),ostream_iterator<int>(cout," "));
        cout<<endl;
        return 0;

}
