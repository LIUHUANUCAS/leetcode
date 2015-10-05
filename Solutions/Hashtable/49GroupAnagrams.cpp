#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<string>
#include<stack>
#include<queue>
#include<deque>
#include <cstdlib>
#include<iterator>
using namespace std;


/**
    doc
    Given an array of strings, group anagrams together.
    
    For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
    Return:
    
    [
        ["ate", "eat","tea"],
        ["nat","tan"],
        ["bat"]
    ]
    Note:
    For the return value, each inner list's elements must follow the lexicographic order.
    All inputs will be in lower-case.


    49GroupAnagrams.cpp
*/
/**
    Solutions:
    the purpose is to reorginize the strings in the vector as to make the anagrams be the adjacent.
    the anagrams is some strings that have the same length and the same characters ,for example , ate vs tea both
    have the same length and the same characters:a,t,e.
    
    we will use a map that map the anagrams into a vector or list,the key is the sorted string.
    anagrams will be in the same list,at last we should sort the list.
     
**/

class Solution {

       public:
            vector<vector<string>> groupAnagrams(vector<string>& strs) {
                unordered_map<string,vector<string> > hmap;
                vector<vector<string>> res;
                for(auto &e : strs){
                    string te = e;
                    sort(te.begin(),te.end());
                    if(hmap.count(te) == 0 ){
                        vector<string> svec;
                        svec.push_back(e);
                        hmap[te] = svec;
                    }else{
                        hmap[te].push_back(e);
                    }
                }
                
                for(auto&e : hmap){
                    sort(e.second.begin(),e.second.end());
                    res.push_back(e.second);
                }
                return res;
            }
};

int main(){
        Solution s;
        unordered_map<int,int> hmap;
        vector<string>  strs = {
            // "dbac","abdc","lghiab"
            "eat", "tea", "tan", "ate", "nat", "bat"
            
        };
        vector<vector<string>> res =     s.groupAnagrams(strs);
        for(auto&e : res){
            
            copy(e.begin(),e.end(),ostream_iterator<string>(cout," "));
            cout<<endl;
        }
            
        return 0;
        
}
