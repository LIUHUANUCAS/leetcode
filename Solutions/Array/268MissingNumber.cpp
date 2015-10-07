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
    Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

    For example,
    Given nums = [0, 1, 3] return 2.
    
    Note:
    Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

    268MissingNmber.cpp
*/
/**
    Solutions:
    we can draw the conclusion that the missing number will be the in 1...n,where n is the size of the array.
    What's more,the sum of the array will be equal to n*(n+1)/2 - missingNumber
    so missingNumber = n*(n+1)/2 - sum of the array.
*/
class Solution {

       public:
        int missingNumber(vector<int>& nums) {
            int sum=0;
            int count = 0;
            for(auto& e :nums){
                count++;
                sum += count;
                sum-=e;
            }
            return sum;
        }
        
};

int main(){
        Solution s;
        vector<int> res ={1,2,3,5,0};
        int num = s.missingNumber(res);
        return 0;

}
