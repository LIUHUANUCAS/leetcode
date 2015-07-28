#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<iterator>
#include<vector>

using namespace std;
/**
    Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

    Note:
    You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
    The number of elements initialized in nums1 and nums2 are m and n respectively.
*/

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
     int end1 = m-1,end2=n-1,k = n + m -1;
     while(end1>=0&& end2 >=0){
        if(nums1[end1] > nums2[end2])
            nums1[k--] = nums1[end1--];
        else
            nums1[k--] = nums2[end2--];

     }
     while(end1 >=0 )
        nums1[k--] = nums1[end1--];
     while(end2 >=0 )
        nums1[k--] = nums2[end2--];
}

int main(){

    int size = 5;
    int arr [] = {-4,-2,-1, 1,2,2,3,4,5,6};
    int size2= sizeof(arr)/sizeof(int);
    vector<int> array1(arr,arr + sizeof(arr)/sizeof(int));
    vector<int> array(size2+size,0);
    for(int i=0;i<size;++i)
        array[i] = i;
    merge(array,size,array1,size2);
    copy(array.begin(),array.end(),ostream_iterator<int>(cout," "));
    cout<<endl;


}
