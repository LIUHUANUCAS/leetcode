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

    Reverse digits of an integer.
    Example1: x = 123, return 321
    Example2: x = -123, return -321


    7Reverse Integer
*/

class Solution {

       public:
         int reverse(int x) {
            int flag = 0;
            if(x < 0 )
                flag=1;
            if(x == 0)
                return 0;
            x = abs(x);
            int res=0;
            while(x){
                if(res > 0xFFFFFFFF/10)
                    return 0;
                res*=10;
                int tmp = x%10;
                if(res >= 0xFFFFFFFF- tmp)
                    return 0;
                res+= tmp;
                x/=10;
            }
            if(res <=0) return 0;
            if(flag) return -res;
            return res;
         }
};

int main(){
        Solution s;
        int n=100;
        string a = "1534236469";
//        int b= 9646324351;
        int c= 2147483412;
        int res = s.reverse(1534236469);
        cout<<res<<endl;
//        reverse(a.begin(),a.end());
//        cout<<b<<endl;
//        cout<<s.reverse(9646324351);
//        for(int i=-n;i<n;++i){

//                cout<<i<<"->" << res <<endl;
//        }

}
