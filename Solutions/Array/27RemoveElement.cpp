#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<iterator>

using namespace std;
/**
    Given an array and a value,
    remove all instances of that value in place and return the new length.
    The order of elements can be changed.
    It doesn't matter what you leave beyond the new length.
*/



int removeElement(int* nums, int numsSize, int val) {
    int i=0,j=numsSize - 1,count = numsSize-1;
   while(i <=j){
        if(val == nums[i]){
            while(i<=j && nums[j] == val){
                j--;
            }

            if(j < i){
                return i;
            }
            else{
                nums[i] = nums[j];
                j--;
                i++;
            }
        }else{
            i++;
        }
   }//while

   if(i == 0 )
     return 0;

    return j+1;
}
int main(){
//    int array[] = {1,2,3,2,2,1,2,3,4,5,6};
    int array[] = {4,4,5,4,4,1,2,3,4,5};
    int size = sizeof(array)/sizeof(int);
    int val = 4;
    copy(array,array+size,ostream_iterator<int>(cout," "));
    cout<<endl;
    int res = removeElement(array,size,val);
    copy(array,array+res,ostream_iterator<int>(cout," "));
    cout<<endl;
    printf("size = %d\n",size);
    printf("res = %d\n",res);

}
