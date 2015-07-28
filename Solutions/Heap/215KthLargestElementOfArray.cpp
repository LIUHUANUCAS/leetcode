#include<iostream>
#include<vector>
#include <cstdlib>
#include<iterator>
#include<algorithm>
using namespace std;


/**
    doc
    Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order,
    not the kth distinct element.

    For example,
    Given [3,2,1,5,6,4] and k = 2, return 5.

    Note:
    You may assume k is always valid, 1 ¡Ü k ¡Ü array's length.

    215KthLargestElementOfArray.cpp
*/

class Solution {

       public:

        int findKthLargest(vector<int>& nums, int k) {
            int*begin = &nums[0];
            int *end = begin + nums.size()-1;
            return findkth(begin,end,k);
        }

        int findkth(int*begin,int *end,int kth){
            if(begin <= end){
                int res = partition_kth(begin,end,kth);
                if(res < 0 )
                    return -1;
                if(res+1 == kth)
                    return *(begin+res);
                else if(res+1 > kth ){
                    return findkth(begin,begin+res-1,kth);
                }
                else{
                    return findkth(begin+res+1,end,kth-res-1);
                }
            }//if ebgin
            return -1;
        }
        int partition_kth(int *begin,int *end,int kth){
            int* rb = begin;
            if(begin <= end){
                int pivot = *begin;
                while(begin< end){
                    while(begin< end && *end <= pivot)
                        end--;
                    *begin = *end;
                    while(begin< end && *begin > pivot)
                        begin++;
                    *end = *begin;
                }

                *end = pivot;
                return end - rb;
            }
            return -1;
    }

};

int func(int x,int y){
    return x>y;
}
int main(){
//        int array[] = {3,2,1,5,6,4,7};
        int array[] = {99};
        int size = sizeof(array)/sizeof(int);
//        copy(array,array+size,ostream_iterator<int>(cout," "));
//        cout<<endl;
        int kth = 1;
        Solution s;
//        s.partition_kth(array,array+size-1,kth);
        vector<int> nums(array,array+size);
        int res = s.findKthLargest(nums,kth);
        cout<<kth<<"th is "<<res<<endl;
//        cout<<"ites"<<kth<<"kth"<<s.findkth(array,array+size-1,kth)<<endl;
//        partition_kth(array,array+size-1,kth);
//        cout<<endl;
        sort(array,array+size,func);
        copy(array,array+size,ostream_iterator<int>(cout," "));

}
