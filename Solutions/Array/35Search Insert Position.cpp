#include<iostream>
#include<vector>
#include <cstdlib>
#include<iterator>
using namespace std;


/**
    doc

    Given a sorted array and a target value, return the index if the target is found.
    If not, return the index where it would be if it were inserted in order.

    You may assume no duplicates in the array.

    Here are few examples.
    [1,3,5,6], 5 → 2
    [1,3,5,6], 2 → 1
    [1,3,5,6], 7 → 4
    [1,3,5,6], 0 → 0

    35Search Insert Position.cpp
*/
/**
    Solutions:

    binary search extend...
    we can get the left most or right most index that the target element should insert into from the array.
    so we modify the classic binary search method.as follow....
    if target > nums[mid]:
        then modify the begin. begin = mid + 1
    else
        set end = mid - 1;
    return begin

    at last we should return the value of begin that stands for the left or equal the target index.

    if we change the if-else condition we can get the index that stands for the right or equal the target index.

    if target <= nums[mid]:
    then
        modify the end. end = mid - 1
    else
        set begin = mid + 1
    return end

    Complexity:

    from the Solutions above ,we can draw the conclusion that the method to solve the "search insert position"
    is extended from the classic algorithm--binary search
    so the time Complexity will be O(log(n)),where n is the size of the array.


*/
class Solution {

       public:

            int searchInsert(vector<int>& nums, int target) {
                if(nums.empty())
                    return 0;

                int begin =0;
                int end = nums.size()-1;

                while(begin <= end){
                    int mid = (begin + end) >> 1;
                    cout<<"mid:"<<mid<<endl;
                    if(target > nums[mid])
                        begin = mid+1;
                    else
                        end = mid - 1;
//                    if(target >= nums[mid])
//                        begin = mid+1;
//                    else
//                        end = mid - 1;
                }
                return begin;
            }

};

int main(){
        Solution s;
        vector<int> nums = {1,3,5,9};
        int target = 2;
        int index = s.searchInsert(nums,target);
        cout<<index<<endl;
        cout<<"binary search extend..."<<endl;

}
