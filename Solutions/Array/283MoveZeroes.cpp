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


    000cpptemplate.cpp
*/

class Solution {

       public:
       void moveZeroes(vector<int>& nums) {
           if(nums.size() <= 1)
                return ;
           move(nums); 
       }
       
       void move(vector<int>& nums){
           int begin =0;
           int n =nums.size();
           int end = nums.size()-1;
           
           while(begin < n){
               if(nums[begin] == 0){
                int k = begin +1;
                while(k<n && nums[k] ==0)
                    k++;
                cout<<k<<endl;
                if(k < n )
                {
                    int t = nums[k];
                    nums[k] = nums[begin];
                    nums[begin] = t;  
                }else
                    return ;
               }
               
               begin ++;      
           }
       }
       
       void bubbleSort(vector<int>& nums){
           int n = nums.size();
           int count = 0;
           for(int i=0;i<n;){
               if(nums[i] != 0 ){
                i++;
                continue;
               }
               // cout<<i<<endl;
        copy(nums.begin(),nums.end(),ostream_iterator<int>(cout," "));
        cout<<endl;               
               for(int k=i;k<n-1;++k){
                   // if(nums[k] != 0 )
                   // continue;
                   if(nums[k+1] !=0){
                       
                       int t = nums[k];
                       nums[k] = nums[k+1];
                       nums[k+1] = t;
                   }
               }
               if(nums[i] !=0 )
                i++;
               
           }
           
       }
       
       void partition(vector<int>& nums){
           int begin = 0;
           int n = nums.size();
           int end = n - 1;
           
           while(begin < end){
               while(nums[end] == 0 && end >=0)
                end --;
               while(nums[begin] !=0 && begin < n)
                begin ++;
                
                if(begin < end ){
                    int k = nums[begin];
                    nums[begin] = nums[end];
                    nums[end] = k;
                }
                begin ++;
                end --;
           }
       }

};

int main(){
        Solution s;
        int array[]={0,0,
        0,0,1,2,0,0,0,3,0,0,0,4,5,0,6,7,8,0 ,0,0
        };
        
        vector<int> res = {
            
            1,0,1,2,0,0,0,3,0,0,0,4,5,0,6,7,8,0 ,0,0
            };
        s.moveZeroes(res);
        cout<<"reslult ...."<<endl;
        copy(res.begin(),res.end(),ostream_iterator<int>(cout," "));
        cout<<endl;


}
