#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
/**
    doc
    Write a function to find the longest common prefix string amongst an array of strings.

    Hide Tags String

    14LongestCommonPrefix.cpp
*/
/**
    Solutions:
        we should compare two strings and determine their common prefix string,the result will be pushed into
        the string vector ,but the algorithm should be terminated,if the common prefix of two strings are empty string.
        we will pop back two strings from the string vector,and compare with each other.
        the while loop will break until the size of vector is 1.


*/
class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
                if(strs.size() == 0)
                        return "";
                string str="";
                while(strs.size()>1){
                    string s1= *(strs.end()-1);
                    strs.pop_back();
                    string s2= *(strs.end()-1);
                    strs.pop_back();
                    str = CommonPrefix(s1,s2);
                    if(str == "")
                        return "";
                    strs.push_back(str);
                }
                return strs[0];
        }

        string CommonPrefix(string s1,string s2){
                if(s1.empty() || s2.empty())
                    return "";
                size_t i=0;
                string str="";
                for(i=0;i<s1.size()&&i<s2.size();++i){
                    if(s1[i] == s2[i])
                        str+=s1[i];
                    else
                        return str;
                }
                return str;
        }


};

int main(){

    vector<int> array = {1,2,3,4,5};
    Solution s;
    vector<string> strs={"liuzhang","liuwang","liupeng","liustr","l"};
    string s1="liuzhang";
    string s2="liuzhwng";
    string str = s.longestCommonPrefix(strs);
    cout<<str<<endl;
    cout<<"hello c++11"<<endl;
    return 0;
}
