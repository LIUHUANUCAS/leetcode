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

    Implement int sqrt(int x).

    Compute and return the square root of x.

    69Sqrt(x).cpp
*/

class Solution {

       public:
            int mySqrt(int x) {
                if(x <= 0 )
                    return 0;
                int begin = 0;
                int end = x;
                while(begin <= end){

                    int mid = (begin + end)>>1;
                    cout<<"mid->"<<mid<<endl;
                    if(mid * mid == x)
                        return mid;
                    if(mid * mid > x)
                        end = mid -1;
                    else
                        begin = mid + 1;
                }
                return 0;
            }

};

int main(){
        Solution s;
        int x = 64;
//        for(int i = 1;i<100;++i){
//            int res = s.mySqrt(i);
//            cout<<res<<endl;
//
//        }
        cout<<s.mySqrt(2147395599)<<endl;
        return 0;

}
