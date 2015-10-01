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
    Given two strings s and t, write a function to determine if t is an anagram of s.

    For example,
    s = "anagram", t = "nagaram", return true.
    s = "rat", t = "car", return false.

    Note:
    You may assume the string contains only lowercase alphabets.

    242Valid Anagram.cpp
*/

class Solution {

       public:
            bool isAnagram(string s, string t) {
                sort(s.begin(),s.end());
                sort(t.begin(),t.end());
                return s == t;
            }

};

int main(){
        Solution solution;
        string s = "anagram", t = "nagaram";
        bool res = solution.isAnagram(s,t);
        cout<<res<<endl;
        return 0;


}
