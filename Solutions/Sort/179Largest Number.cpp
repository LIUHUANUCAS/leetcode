#include<iostream>
#include<vector>
#include <cstdlib>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<sstream>
#include<string>

using namespace std;


/**
    doc
    Given a list of non negative integers, arrange them such that they form the largest number.

    For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

    Note: The result may be very large, so you need to return a string instead of an integer.

    Credits:
    Special thanks to @ts for adding this problem and creating all test cases.

    Hide Tags Sort


    179Largest Number.cpp
*/
int func(string s1,string s2){
                int i=0;
                while(i<s1.size() && i < s2.size()){
                    if(s1[i] == s2[i]){
                        i++;
                    }else
                        return s1[i] - s2[i];

                }

                if(s1.size() == s2.size())
                    return 0;

                //s2 is shorter
                if(i < s1.size()){
                    if(s1[i] == '0')
                        return 1;
                    else
                        return -1;
                }

                if(i < s2.size()){
                    if(s2[i] == '0')
                        return 1;
                    else
                        return -1;
                }


                else if(s1.size() < s2.size())
                        return 1;
                else
                    return -1;
//                    return 0;
//                if(i >= s1.size())
//                    return 0;
//                if(i>= s2.size())
//                    return 1;
           }
class Solution {

       public:

            string largestNumber(vector<int>& nums) {
                    vector<string> svec;
                    for(auto&e:nums){
                        ostringstream  ss;
                        ss<<e;
                        svec.push_back(ss.str());
                    }
                    copy(svec.begin(),svec.end(),ostream_iterator<string>(cout," "));
                    cout<<endl;

                    sort(svec.begin(),svec.end(),func);
                    string str="";
                    for(auto&e:svec)
                        str+=e;
                    return str;
            }
};

int main(){
        Solution s;
        vector<int> array = {3, 30, 34, 5, 9};

//        string res = s.largestNumber(array);
//        cout<<res<<endl;
        cout<<func("34","3")<<endl;
//        cout<<func("12","30")<<endl;

        return 0;

}
