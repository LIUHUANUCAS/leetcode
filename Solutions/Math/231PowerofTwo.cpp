#include<iostream>
#include<vector>
#include <cstdlib>
#include<iterator>
#include<algorithm>
#include<cstring>

using namespace std;


/**
    doc
    Given an integer, write a function to determine if it is a power of two.


    231Power of Two.cpp
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
         if(n <= 0)
            return 0;
//         n = abs(n);
         int size=32;
         int a =1;
         int t=0;
         int count = 0;
         for(int i=0;i<size;++i){
            t = n & a;
            a =a << 1;
            if(t != 0){
                count++;
                if(count > 1)
                    return 0;
            }
         }
         return 1;
    }
};

int main(){
        Solution s;
        int n=31;
        bool res;
        for(int i=0;i<1000;++i){
            res = s.isPowerOfTwo(i);
            if(res)
            cout<<res<<":"<<i<<endl;
        }

        cout<<(32& (1<<4))<<endl;
}
