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
            bool isPalindrome(int x) {
                if(x < 0)
                    return 0;
                if( x<=9 && x >=0)
                    return 1;
                int n = x;
            char s[33];
            sprintf(s,"%d",x);
            string str(s);
            return isPalindrome(str);

            }

            bool isPalindrome(string s){
                 int begin = 0;
                 int end = s.size()-1;
                 while(begin<=end){
                    if(s[begin++] != s[end--])
                        return 0;
                 }
                 return 1;
            }

};

int main(){
        Solution s;
        int x = 1234321;
        string str = "1321";
        bool res = s.isPalindrome(x);
        cout<<res<<endl;

}
