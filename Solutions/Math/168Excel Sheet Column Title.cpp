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
    Related to question Excel Sheet Column Title

    Given a column title as appear in an Excel sheet, return its corresponding column number.

    For example:

        A -> 1
        B -> 2
        C -> 3
        ...
        Z -> 26
        AA -> 27
        AB -> 28


    168Excel Sheet Column Title.cpp
*/
/**
    Solutions:
        number based on 26 like the number based on 2 or 10.
*/

class Solution {

       public:
            int titleToNumber(string s) {
                int n = s.size();
                if(n==0)
                    return 0;
                if(n == 1)
                    return s[0]-'A' + 1;

                int nums=0;
                for(int i= 0 ;i< n ;++i){
                    nums *=26;
                    nums += s[i] - 'A' + 1;
                }
                return nums;
            }

};

int main(){
        Solution s;
        int nums = 0;
        string str = "A";
        nums = s.titleToNumber(str);
        cout<<nums<<endl;


        return 0;

}
