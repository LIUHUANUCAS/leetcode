#include<iostream>
#include<vector>
#include <cstdlib>
#include<iterator>
#include<map>
#include<unordered_map>
using namespace std;


/**
    Given an array of integers and an integer k, find out whether there 
    there are two distinct indices i and j in the array such that nums[i] = nums[j] 
    and the difference between i and j is at most k.

    
    happyNumber.cpp
*/

class Solution {

       public:
       
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            
            unordered_map<int,int> hmap;
            size_t n = nums.size();
            if(n <= 1)
                return 0;
            if(k <=0)
                return 0;
            hmap[nums[0]] = 0;
            for(size_t i =1;i< n ; ++i){
               int a = nums[i];
               
               if(hmap[a] == 0){//
                   if(a == nums[0]){
                       if(i-0 <= k ){
                           
                       // cout<<i<<"->"<<hmap[a]<<endl;
                           
                       return 1;
                       }
                   } 
                   hmap[a] = i;
                   
               }else{
                   if(i - hmap[a] <= k){
                       
                       // cout<<i<<"->"<<hmap[a]<<endl;
                        return 1;
                   }
                   else
                        hmap[a] = i;
                   
               }
               
               
            }//for 
            return 0;
      
        }

    
            
};




int main(){
        Solution s;
        
        vector<int> nums = {
            // 1,2,3,-1,5,4,3,-1,6,3
            -1,-1
            };
        int k=4;
        unordered_map<int,int> map1;
        map<int,int> mp;
        cout<<mp[0]<<endl;
        int a = map1[1];
        // cout<<a<<endl;
        // return 0;
        cin >> k;
        bool res = s.containsNearbyDuplicate(nums,k);
        cout<<res<<endl;
        return 0;
      

}
