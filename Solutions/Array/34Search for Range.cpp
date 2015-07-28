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
    Given a sorted array of integers, find the starting and
    ending position of a given target value.

    Your algorithm's runtime complexity must be in the order of O(log n).

    If the target is not found in the array, return [-1, -1].

    For example,
    Given [5, 7, 7, 8, 8, 10] and target value 8,
    return [3, 4].

    34Search for Range.cpp
    Solution:
    binary search extend,
*/

class Solution {

    public:
            vector<int> searchRange(vector<int>& nums, int target) {
                    int left = bSearchLeft(nums,0,nums.size()-1,target);
                    int right = bSearchRight(nums,0,nums.size()-1,target);

                    if(left > right){
                        vector<int> res={-1,-1};
                        return res;
                    }

                    vector<int> res={left,right};
                    return res;

            }
           int bSearchLeft(vector<int>& num,int begin, int end, int e)
            {
                int mid, left = begin, right = end;
                while(left <= right)
                {
                    mid = (left + right) >> 1;
                    if(num[mid] >= e) right = mid - 1;
                    else left = mid + 1;
                }
                return left;
            }

            int bSearchRight(vector<int>& num,int begin, int end, int e)
            {
                int mid, left = begin, right = end;
                while(left <= right)
                {
                    mid = (left + right) >> 1;
                    if(num[mid] > e) right = mid - 1;
                    else left = mid + 1;
                }
                return right;
            }



};


int bsearchr(vector<int>& nums,int begin,int end,int target){
        while(begin<=end){
            int mid = (begin+end) >> 1;
            if(nums[mid] <= target)
                begin = mid+1;
            else
                end = mid-1;

        }

        cout<<"begin->"<<begin<<endl<<"end ->"<<end<<endl;
        return end;
}

int bsearchl(vector<int>& nums,int begin,int end,int target){
        while(begin<=end){
            int mid = (begin+end) >> 1;
            if(nums[mid] >= target)
                end = mid-1;
            else
                begin = mid+1;

        }
        cout<<"begin->"<<begin<<endl<<"end ->"<<end<<endl;
        return begin;
}

int main(){
        Solution s;
        vector<int> array={5, 7, 7, 8, 8, 10};
        int target = 4;
        vector<int > res = s.searchRange(array,target);
        copy(res.begin(),res.end(),ostream_iterator<int>(cout," "));
        cout<<endl;
//        vector<int> res (array,array+ sizeof(array)/sizeof(int));
//        copy(res.begin(),res.end(),ostream_iterator<int>(cout," "));


}
