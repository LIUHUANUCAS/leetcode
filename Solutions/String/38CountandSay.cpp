#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
/**
    doc
    The count-and-say sequence is the sequence of integers beginning as follows:
    1, 11, 21, 1211, 111221, ...

    1 is read off as "one 1" or 11.
    11 is read off as "two 1s" or 21.
    21 is read off as "one 2, then one 1" or 1211.
    Given an integer n, generate the nth sequence.

    Note: The sequence of integers will be represented as a string.

    Hide Tags String


    38CountandSay.cpp
*/
/**
    Solutions:

*/
class Solution {
    public:
        string countAndSay(int n) {
            if(n<=0)
                return "";
            if(n == 1)
                return "1";
            string s= "1";
            int count = 1;
            string str="";
            while(count<n){
                str= "";
                char ch = s[0];
                size_t i = 1;
                int times = 1;
                while(i<s.size()){
                    if(s[i] == ch){
                        times++;
                        i++;
                    }
                    else //if(s[i] != ch)
                        {
                        char ctmp[21]="";
                        sprintf(ctmp,"%d",times);
                        times = 1;
                        str+= string(ctmp);
                        str+=ch;
                        ch = s[i];
                        i++;
                    }
                }
                char ctmp[21]="";
                sprintf(ctmp,"%d",times);
                times = 1;
                str+= string(ctmp);
                str+=ch;
                s = str;
                count++;
            }
            return s;
        }


};

int main(){

    vector<int> array = {1,2,3,4,5};
    Solution s;
    int n = 4;
    while(cin>>n)
        cout<<s.countAndSay(n)<<endl;

    cout<<"hello c++11"<<endl;
    return 0;
}
