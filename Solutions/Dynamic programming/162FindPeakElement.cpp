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

    A peak element is an element that is greater than its neighbors.

    Given an input array where num[i] ¡Ù num[i+1], find a peak element and return its index.

    The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

    You may imagine that num[-1] = num[n] = -¡Þ.

    For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

    click to show spoilers.

    Note:
    Your solution should be in logarithmic complexity.

    162Find Peak Element.cpp
*/

class Solution {

       public:

        int findPeakElement(vector<int>& nums) {
            int begin = 0;
            int end = nums.size()-1;
            return findElement(nums,begin,end);
        }

        int findElement(vector<int>&nums,int begin,int end){
            if(begin == end)
                return begin;
            if(end - begin == 1){
                 return  nums[begin] > nums[end] ? begin:end;
            }
            int mid = (begin+end)>>1;

            if(nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1])
                return mid;
            else if(nums[mid] < nums[mid+1])
                return findElement(nums,mid+1,end);
            else
                return findElement(nums,begin,mid-1);
        }
};
int main(){
        Solution s;
        vector<int> vec = { 1,4,2};
        copy(vec.begin(),vec.end(),ostream_iterator<int>(cout," "));
        cout<<endl;
        int index = s.findPeakElement(vec);
        cout<<index<<endl;

}

// if( nums[begin] > nums[end])
//                return begin;
//                else return end;

