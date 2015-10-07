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
    Suppose a sorted array is rotated at some pivot unknown to you beforehand.

    (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

    Find the minimum element.

    Follow up for "Find Minimum in Rotated Sorted Array":
    What if duplicates are allowed?

    Would this affect the run-time complexity? How and why?
    Suppose a sorted array is rotated at some pivot unknown to you beforehand.

    (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

    Find the minimum element.

    The array may contain duplicates.


    154FindMinimumInRotatedSortedArrayII.cpp
*/
/**
    Solutions:
    the assumation is that there is no duplicate exist in the array.
    from  rotation of the sorted array,we can draw the conclusion that the array will be the following format
    Ai,Ai+1,A... Amin,Ak,Ak+1,...An; there two pointers [begin,end] where the min value located.
    1.if A[begin] < A[end],so the A[begin,end] is sorted ,the min value is A[begin]
    2.if end == begin the min value  is A[end]
    3.if end - begin == 1 the min value is minimum of A[begin],A[end]
    4.if A[mid] > A[end] the min value locates in A[mid+1,end]
    5 if A[mid] < A[end] the min value locates in A[begin,mid]

    1,2,3 are terminated conditions.
    we should make a glance at the 4,5
    first,the 4 stated that if A[mid] > A[end], min value in A[mid+1,end],the reason is that if A[mid] > A[end] and A[min] must less than
        A[mid] so the A[min] can not be equal A[mid],so the next range of min value is [mid+1,end]
    second,the 5 stated that if A[mid] < A[end],the min value locates in A[begin,mid].what will happen if A[begin,mid]?
        A[mid] < A[end],so the min value will not be in A[mid+1,end] because A[mid] < A[mid+1],that is to say the A[mid,end] has been sorted
        so the min value must in A[begin,mid].Carefully,A[mid] may be the minimum value of the array.

    finally ,we should pay attention to the partial sorted array that is we can make the decision from the result of A[mid] < A[end],
    while we can also decide the range of the min value from the result of A[begin] < A[mid],details can be seen at the code findMin2 with comments.
*/
void printMatrix(vector<vector<int>>& matrix){
    for(auto&res:matrix){
        copy(res.begin(),res.end(),ostream_iterator<int>(cout," "));
        cout<<endl;
    }
    cout<<endl;
}

void printVector(vector<int>& res){
        copy(res.begin(),res.end(),ostream_iterator<int>(cout," "));
        cout<<endl;
}

class Solution {

       public:
        int findMin1(vector<int>& nums) {
            int size = nums.size();
            if(size == 1)
                return nums[0];
            int begin = 0;
            int end = size -1;

            while(begin <= end){
                int mid =  (end + begin)>>1;
                cout<<begin<<"->"<<end<<endl;
                cout<<"->"<<mid<<endl;

                if(nums[begin] < nums[end])
                    return nums[begin];
                if(begin == end)
                    return nums[end];
                if(end - begin == 1)
                    return nums[end] > nums[begin] ? nums[begin]:nums[end];
                if(nums[mid] > nums[end])
                    begin = mid+1;
                else if (nums[mid] == nums[end])
                    end--;//  = mid;
                else
                    end = mid;

            }
            return nums[end];
        }

        int findMin(vector<int>& nums) {
            int size = nums.size();
            if(size == 1)
                return nums[0];
            int begin = 0;
            int end = size -1;

            while(begin <= end){
                //cout<<begin<<"->"<<end<<endl;
                int mid =  (end + begin)>>1;
                //cout<<"->"<<mid<<endl;

                if(nums[begin] < nums[end])
                    return nums[begin];
                if(begin == end)
                    return nums[end];
                if(end - begin == 1)
                    return nums[end] > nums[begin] ? nums[begin]:nums[end];
                /**A[begin,mid] are sorted,the min value locates in A[mid+1,end]**/
                if(nums[begin] < nums[mid])
                    begin = mid +1 ;
                else if(nums[begin] == nums[mid])/**min value locates in A[begin,mid],A[mid] may be the min value*/
                    begin ++;
                else
                    end = mid;
                /***A[mid,end] are sorted**/
                /**
                if(nums[mid] < nums[end])
                    end = mid;
                else
                    begin   = mid + 1;
                **/
            }
            return nums[end];
        }
};

int main(){
        Solution s;
        vector<int> nums = {
//             4,1,2,3
                3,1,3,3,3,3
//             0,0,0,0,0,2,3,4,4,5,5,5,6,7,7,7,7
//             2,3,3,3,3,4,5,6,7,7,7,7,0,0,0,0,0,1,2,2,2,2
        };
        int minx = s.findMin(nums);
        cout<<"========================="<<endl;
        cout<<minx<<endl;

        return 0;
//        vector<int> res (array,array+ sizeof(array)/sizeof(int));
//        copy(res.begin(),res.end(),ostream_iterator<int>(cout," "));


}
