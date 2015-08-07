#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
/**
    doc
    The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
    (you may want to display this pattern in a fixed font for better legibility)

    P   A   H   N
    A P L S I I G
    Y   I   R

    And then read line by line: "PAHNAPLSIIGYIR"
    Write the code that will take a string and make this conversion given a number of rows:

    string convert(string text, int nRows);
    convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

    6ZigZagConversion.cpp
*/
class Solution {
    public:
        string convert(string s, int numRows) {
            int rows=  (s.size()+1)/(numRows+1) * 2 + 1;
            cout<<rows<<endl;
            vector<vector<string> > array(numRows,vector<string>(rows," ") );

            int i=0,j=0;
            bool flag = 1;
            for(auto&e: s){
                array[i][j] = e;
                if(flag)
                    i++;
                else
                    i-=numRows/2;
                if(i == numRows){
                    j++;
                    i=numRows/2;
                    flag = 0;
                }else
                if(i <= 0){
                    i = 0;
                    flag=1;
                    j++;
                }
            }
            for(auto&e:array){
                copy(e.begin(),e.end(),ostream_iterator<string>(cout," "));
                cout<<endl;
            }
            string str="";
            for(auto&e:array){
                for(auto&st:e){
                    if(st !=" ")
                        str+=st;
                }
            }
//            cout<<str<<endl;
            return str;
        }
};

int main(){

    Solution s;
//    string str = "LIUHUANPENGXINGJIULIUJIANFEIZHANGSANLISIWANGWUNIHAOZHEYANGSHIDUIDE";//PAYPALISHIRING
    string str = "PAYPALISHIRING";//PAYPALISHIRING
    str = s.convert(str,7);
    cout<<str<<endl;
    cout<<"hello c++11"<<endl;
    return 0;
}
