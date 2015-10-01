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


    75Sort Colors.cpp
*/

class Solution {

       public:
            void sortColors(vector<int>& nums) {
                int size = nums.size();
                if(size == 0 || size == 1)
                    return ;
                int pivot = 1;
                cout<<pivot<<"piovt"<<endl;
                int begin = 0;
                int end = size - 1;
                for(int i=0,j=1;i<size-1;){
                    int j = i+1;
                    while(j<size && nums[j] >= nums[i])
                        j++;
                    if(j < size){
                        nums[j]

                    }


                }

                copy(nums.begin(),nums.end(),ostream_iterator<int>(cout," "));
                cout<<endl;
            }

};

int main(){
        Solution s;
//        vector<int> array={1,0,0,1,0,2,1,2,2,2,1,1,1,1,0,0,0,1,1,1,1,1,0,2,2,2,2,2};
        vector<int> array={1,0,0,1,0,2};

        s.sortColors(array);

        copy(array.begin(),array.end(),ostream_iterator<int>(cout," "));

        return 0;
}
