#include<iostream>
#include<vector>
#include <cstdlib>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include <stack>          // std::stack
#include <queue>

using namespace std;


/**
    doc
    Given an absolute path for a file (Unix-style), simplify it.
    
    For example,
    path = "/home/", => "/home"
    path = "/a/./b/../../c/", => "/c"
    click to show corner cases.
    
    Corner Cases:
    Did you consider the case where path = "/../"?
    In this case, you should return "/".
    Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
    In this case, you should ignore redundant slashes and return "/home/foo".


    71SimplifyPath.cpp
*/

/**
    Solutions:
    we can split the path by '/' ,so the split strings will be the directory names or . or .. 
    we can get a vector of the directory.
    we will triverse the vector and use another vector change  directories if there is a '.',we will continue,
    if there is a '..',then the directories before will be poped from the vector
    if there is a directory name ,the directory will be pushed into another vector.
    finally, the directory in another vector will be the simplified path.
*/

class Solution {

       public:
        string simplifyPath(string path) {
            vector<string> spath;
            vector<string> svec = splitPath(path);
            if(svec.empty())
                return "/";

            for(auto& e : svec){
                if(e == ".")
                    continue;
                else if (e == ".."){
                    if(spath.size() > 0)
                        spath.pop_back();
                    }
                 else
                    spath.push_back(e);
            }
            string finallpath="";
            for(auto& e : spath)
                finallpath+="/"+e;
            if(finallpath == "")
                return "/";
            return finallpath;        
        }
        vector<string> splitPath(string path){
            int i=1;
            vector<string> vec;
            int n = path.size();
            int k=1;
            auto begin = path.begin();
            while(i < n){
                if(path[i] == '/'){
                   string s = string(begin + k,begin + i);
                   k = i+1;
                   if(s != "" && s != " ")
                   vec.push_back(s);
                }
                i++;
            }//end while
            if(k < n)
                vec.push_back(string(begin+k,path.end()));
            return vec;
        }

};

int main(){
        Solution s;
        string path = "/a/./b/../../d/c//";
        path ="/../a";
        string ss = s.simplifyPath(path);
        cout<<ss<<endl;
        return 0;

}
