#include<iostream>
#include<vector>
#include <cstdlib>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>

using namespace std;


/**
    doc



    name.cpp
*/

class Solution {

       public:
       int divide(int dividend, int divisor) {
            if(dividend < divisor)
                return 0;
            if(dividend == divisor)
                return 1;
            int end = dividend>>1;
            int begin = 2;
            while(begin <= end){
                int mid = (begin + end )>>1;
                
                
            } 
       }

};

int main(){
        Solution s;

        return 0;

}
