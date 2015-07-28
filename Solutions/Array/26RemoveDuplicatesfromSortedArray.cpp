#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<iterator>

using namespace std;
/**
    Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

    Do not allocate extra space for another array, you must do this in place with constant memory.

    For example,
    Given input array nums = [1,1,2],

    Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
    It doesn't matter what you leave beyond the new length.

    26RemoveDuplicatesfromSortedArray.cpp
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int i=0,j=1;
        int size = nums.size();
        while(i<size && j < size){
            int val = nums[i];
            while(j<size && nums[j] == val){
                j++;
            }
            if(j == size)
                return i+1;
            if(j == i + 1){
                i++;
            }else{
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};
int main(){
    vector<int> array = {2,4,5,6,7,8,9,0};
    copy(array.begin(),array.end(),ostream_iterator<int>(cout," "));
    cout<<endl;
    sort(array.begin(),array.end());
    Solution s;
    int off = s.removeDuplicates(array);
    copy(array.begin(),array.begin()+off,ostream_iterator<int>(cout," "));
    cout<<endl;


}
