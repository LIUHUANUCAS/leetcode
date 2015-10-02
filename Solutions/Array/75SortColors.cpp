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
    Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

    Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
    
    Note:
    You are not suppose to use the library's sort function for this problem.
    
        
    Follow up:
    A rather straight forward solution is a two-pass algorithm using counting sort.
    First, iterate the array counting number of 0's, 1's, and 2's, 
    then overwrite array with total number of 0's, then 1's and followed by 2's.
    
    Could you come up with an one-pass algorithm using only constant space?

    75SortColors.cpp
*/
/**
    Solutions:
    we can draw the conclusion that the format of the sortColors array will start with 0s followed with 
    some 1s and end in 2s.
    that is to say,we can move all 0s to the head of the array and 2s to the tail of the array.
    what will you do if just moved all 2s to the tail or just moved all 0s to the head?
    Thus, the solution is simple,just move all 0s to head and move all 2s to the tail,while do nothing about 1s or just pass it.
    so the solution will have used three pointers,one--begin  is to point the tail of 0s at present,one--end is to point the head of 2s from the 
    end. last one--i pointer will be used to pass through  elements of the array from the [begin,end].
    But at the same time ,the begin pointer will be added 1 when there is a 0 finded,the end pointer will substract 1 when there is
    a 2 finded.    
*/
class Solution {

       public:
            void sortColors(vector<int>& nums) {
                int begin = 0;
                int size = nums.size();
                int end = size -1;
                int i=0;
                while(1){
                    if(i>end || begin > i)
                        break;
                    if(nums[i] == 0 && begin != i)
                        swap(nums[begin++],nums[i]);
                    else if(nums[i] == 2 && i != end)
                        swap(nums[end--],nums[i]);
                    else 
                        i++;
                }
            }

};

int main(){
        Solution s;
       vector<int> array={0,2,1,2//,1,1,0,2,1,2,2,2,1,1,1,1,0,0,0,1,1,1,1,1,0,2,2,2,2,2
           };
        // vector<int> array={1,0,0,1,0,2};

        s.sortColors(array);

        copy(array.begin(),array.end(),ostream_iterator<int>(cout," "));
        cout<<endl;

        return 0;
}
