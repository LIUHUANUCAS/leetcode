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
    A message containing letters from A-Z is being encoded to numbers using the following mapping:

    'A' -> 1
    'B' -> 2
    ...
    'Z' -> 26
    Given an encoded message containing digits, determine the total number of ways to decode it.

    For example,
    Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

    The number of ways decoding "12" is 2.

    Hide Tags Dynamic Programming String



    91Decode Ways.cpp
*/

class Solution {

       public:


           int numDecodings(string s) {
            int n = s.size();
            if(n==0)
                return 0;
            if(n == 1){
                if(s[0] == '0')
                    return 0;
                else
                    return 1;
            }
            vector<int> dp(n,1);
            for(int i=1;i<n;++i){
                int flag = 1;
                if(s[i] == '0'){
                    flag = 0;
                }

                int res = hasDecodeways(s[i-1],s[i]);
                int a =0;
                int b=0;
                if(res){
                    a = dp[i-2] + flag ;
                }else{
                    b = dp[i-1] + flag;
                }
                dp[i] = max(a,b);

            }

            return dp[n-1];
        }



        int numDecodings1(string s) {
            int n = s.size();
            if(n==0)
                return 0;
            if(n == 1){
                if(s[0] == '0')
                    return 0;
                else
                    return 1;
            }
            vector<int> dp(n,1);
            dp[0] = 1;
            for(int i=1;i<n;++i){
                int flag = 1;
                if(s[i] == '0')
                    flag = 0;
                dp[i] = dp[i-1] + flag + hasDecodeways(s[i-1],s[i]);
            }

            return dp[n-1];
        }

        int hasDecodeways(char cha,char chb ){
            int a = cha - '0' ;
            int b = chb - '0' ;
//            cout<<a<<" ->"<<b<<endl;
            if(a == 0)
                return 0;
            if(b == 0)
                return 0;
            if(a > 2)
                return 0;
            int c = a*10+b;
            if( c >= 1 && c <= 26 )
                return 1;
            return 0;
        }

};
/**
    Input:"11"
    Output:3
    Expected:2


    Input:"0"
    Output:1
    Expected:0

    Input:"10"
    Output:2
    Expected:1
*/

int main(){
        Solution s;
        string str = "101";
        int res = s.numDecodings(str);
        cout<<res<<endl;
        cout<<"Dynamic programming"<<endl;
        return 0;

}
