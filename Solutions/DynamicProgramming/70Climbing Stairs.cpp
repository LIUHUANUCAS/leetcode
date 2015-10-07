#include<iostream>
#include<vector>
#include <cstdlib>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;


/**
    doc
    You are climbing a stair case. It takes n steps to reach to the top.

    Each time you can either climb 1 or 2 steps.
    In how many distinct ways can you climb to the top?

    Hide Tags Dynamic Programming



    70Climbing Stairs.cpp
*/

class Solution {

       public:
            int climbStairs(int n) {
                if(n <= 0 )
                    return 0;
                if(n == 1)
                    return 1;
                int a=1,b=2;
                for(int i=2;i<n;++i){
                    b = a+b;
                    a = b-a;
                }
                return b;
            }

             int climbStairs1(int n) {
                vector<int> path(n,0);
                path[0] = 1;
                path[1] = 2;
                for(int i=2;i<n;++i){
                    path[i] = path[i-1] + path[i-2];
                }
                return path[n-1];
            }
};

int main(){
        Solution s;
        int n=12;
        int paths = s.climbStairs(n);
        cout<<paths<<endl;
        return 0;

}
