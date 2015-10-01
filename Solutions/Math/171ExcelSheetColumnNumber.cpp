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
    Given a positive integer, return its corresponding column title as appear in an Excel sheet.

    For example:

        1 -> A
        2 -> B
        3 -> C
        ...
        26 -> Z
        27 -> AA
        28 -> AB


    171Excel Sheet Column Number.cpp
*/
/**
    Solutions:
        number based on 26 like the number based on 2 or 10.
        but we should pay extra attention to the number of times of the special number 26.
        if a number mod 26 equals 0 that is to say the column title has a z,we should also
        reduce the the next position of the number ,which should minus 1.
*/

class Solution {

       public:
            string convertToTitle(int n) {
                    if(n <= 0)
                        return "";
                    string str= "";
                    int x = 0;
                    while(n){
                        char ch[3];
                        x= n%26;
                        char tmp ;
                        n/=26;
                        if(x == 0 ){
                            tmp = 'Z';
                            if(n == 1)
                                n = 0;
                            else
                                n--;
                        }
                        else
                            tmp =  x - 1 + 'A';
                        sprintf(ch,"%c",tmp);
                        str += string(ch);
                    }
                     reverse(str.begin(),str.end());
                     return str;
            }
};

int main(){
        Solution s;
        int nums = 1;
        int i = 700;
        string str="AB";
        str[1] ++;
//        cout<<str<<endl;
//        for(int i=1;i<=26*3;++i){
                str = s.convertToTitle(i);
                cout<<str<<endl;
//        }

        return 0;

}
