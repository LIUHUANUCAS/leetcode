#include<iostream>
#include<vector>
#include <cstdlib>
#include<iterator>
using namespace std;


/**
    Write an algorithm to determine if a number is "happy".

    A happy number is a number defined by the following process: Starting with any positive integer, 
    replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), 
    or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
    Example: 19 is a happy number

    1^2 + 9^2 = 82
    8^2 + 2^2 = 68
    6^2 + 8^2 = 100
    1^2 + 0^2 + 0^2 = 1

    202happyNumber.cpp
*/

class Solution {

       public:
            bool isHappy(int n) {
                int res = n;
                while(1){
                    res = bitsum(res);
                    if(res == 1){
                        return 1;
                    }
                    if(res >=0 && res <=9)
                        return 0;
                }
            }
            
            int bitsum(int n){
                // if(n>=0 && n <=9)
                //     return n;
                int sum =0;
                while(n){
                    int t = n%10;
                    n/=10;
                    sum += t*t;
                }
                return sum;
            }
            
};




int main(){
        int n=10;
        Solution s;

        while(1){

         cin >> n;

         cout<<s.isHappy(n)<<endl;   

        }
      

}
