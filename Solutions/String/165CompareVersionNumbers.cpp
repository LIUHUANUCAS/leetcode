#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<vector>
#include<sstream>
#include<algorithm>
#include<iterator>
using namespace std;
/**
    doc

    Compare two version numbers version1 and version2.
    If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

    You may assume that the version strings are non-empty and contain only digits and the . character.
    The . character does not represent a decimal point and is used to separate number sequences.
    For instance, 2.5 is not "two and a half" or "half way to version three",
    it is the fifth second-level revision of the second first-level revision.

    Here is an example of version numbers ordering:

    0.1 < 1.1 < 1.2 < 13.37

    165CompareVersionNumbers.cpp
*/
/**
    Solutions:
        we should split the string by '.' and the result should be transerformed into integers
        and we can compare array of the number with each other.

*/
class Solution {
    public:
        int compareVersion(string version1, string version2) {
            vector<int> vv1 = version2vectorInt(version1);
            vector<int> vv2 = version2vectorInt(version2);
            vector<int>::iterator it1 = vv1.begin(),it2 = vv2.begin();
            for(;it1!=vv1.end()&&it2!=vv2.end();++it1,++it2){
                if(*it1 > *it2)
                    return 1;
                else if(*it1 < *it2)
                    return -1;
            }

            if(it1 == vv1.end() && it2 == vv2.end() )
                return 0;

            if(it2 == vv2.end()){
                for(;it1!=vv1.end();++it1)
                    if(*it1 != 0)
                        return 1;
                return 0;
            }

            if(it1 == vv1.end()){
                for(;it2!=vv2.end();++it2)
                    if(*it2 != 0)
                        return -1;
                return 0;
            }
        }

        vector<int> version2vectorInt(string v){
            vector<int> res;
            string s;
            for(auto&e:v){
                if(e != '.')
                    s+=e;
                else
                {
                    int x = string2int(s);
                    res.push_back(x);
                    s="";
                }
            }
            res.push_back(string2int(s));
            return res;
        }
        int string2int(string s){
            stringstream ss;
            int x =1;
            ss<<s;
            ss>>x;
            return x;
        }

};

int main(){

    vector<int> array = {1,2,3,4,5};
    Solution s;
    string v1 = "1";
//    string v2 = "12.6.9.3.3.4.5.6.7.09";
    string v2 = "1.1";
    cout<<"v1:"<<v1<< " v2:"<<v2<<endl;
    int res = s.compareVersion(v1,v2);
    cout<<res<<endl;
//    vector<int> a = s.version2vectorInt(v2);
//    copy(a.begin(),a.end(),ostream_iterator<int>(cout," "));
//    cout<<endl;
//    stringstream sst;
//    string  str="023";
//    sst<<str;
//    int x =1;
//    sst>>x;
//    cout<<x<<endl;
    cout<<"hello c++11"<<endl;
    return 0;
}
