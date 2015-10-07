#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<iterator>

using namespace std;
/**
        
    doc
    
    Follow up for "Remove Duplicates":
    What if duplicates are allowed at most twice?
    
    For example,
    Given sorted array nums = [1,1,1,2,2,3],
    
    Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. 
    It doesn't matter what you leave beyond the new length.

    80RemoveDuplicatesFromSortedArrayII.cpp
*/

/**
    Solutions:
    we should draw some conclusion from the 26 Remove Duplicates From Sorted Array.
    we should make a count variable to mark how times the duplicate has appeared,and set a length to mark the length of the duplicate
        not more than twice . and set a val to store the duplicate that passed by.
    if the value of array passed by now is equal the val,
    then
        if the count <= 2 we should make the element to move the end of the new array,and the length added 1
        else    
            ignored the element,
    if the value of array passed by now is not equal the val
    then
        add the value to the new array,and length added one.   
*/

class Solution {
public:
    
    
    int removeDuplicates(vector<int>& nums) {
            int size = nums.size();
            if(size <= 2)
                return size;
            int begin =0;
            int val=nums[0];
            int count = 0;
            int length = 0;
            while(begin < size){
                if(nums[begin] == val){
                    count++;
                    if(count <= 2)
                        nums[length++] = nums[begin];
                }else{
                    nums[length++] = nums[begin];
                    val = nums[begin];
                    count = 1;
                }
                begin ++;
            }
            
            return length;
    }
    

   
};
int main(){
    vector<int> array = {
        // 1,1,2,2,3,3,4,5,4,5,4
        1,2,3,4,5,4,5,4
        };
    
    sort(array.begin(),array.end());
    Solution s;
    int length = s.removeDuplicates(array);
    copy(array.begin(),array.begin()+length,ostream_iterator<int>(cout," "));
    cout<<endl;
    cout<<length<<"---->>>finally"<<endl;
    return 0;
}
