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
     vector<int> num(nums1);
     int i=0,j=0,k=0;
     while(i < m && j <n){
        if(num[i] <= nums2[j]){
            nums1[k++] = num[i++];

        }else{
            nums1[k++] = nums2[j++];
        }
     }

     while(i<m){
        nums1[k++] = num[i++];
     }
     while(j<n){
        nums1[k++] = nums2[j++];
     }
}

int main(){
//    int array[] = {1,2,3,2,2,1,2,3,4,5,6};
    int size = 5;

    int arr [] = { 2,2,3,4,5,6};
    int size2= sizeof(arr)/sizeof(int);
    vector<int> array1(arr,arr + sizeof(arr)/sizeof(int));
    vector<int> array(size2+size,0);
//    cout<<array.size();
    for(int i=0;i<5;++i)
        array[i] = i;

    merge(array,size,array1,size2);
    copy(array.begin(),array.end(),ostream_iterator<int>(cout," "));
    cout<<endl;


}
