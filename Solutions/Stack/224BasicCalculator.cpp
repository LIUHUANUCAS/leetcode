#include<iostream>
#include<vector>
#include <cstdlib>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include <stack>          // std::stack
#include <queue>
#include<sstream>
using namespace std;


/**
    doc

    Implement a basic calculator to evaluate a simple expression string.

    The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

    You may assume that the given expression is always valid.

    Some examples:
    "1 + 1" = 2
    " 2-1 + 2 " = 3
    "(1+(4+5+2)-3)+(6+8)" = 23

    Note: Do not use the eval built-in library function.


   224BasicCalculator.cpp
*/
/**
    Solutions:


*/

class Solution {
        private:
        stack<int> nums;
        stack<string> operate;

       public:
           string trim(string str){
                if(str.size() == 0)
                    return "";
                string s="";
                for(auto& e:str)
                    if(e!= ' ')
                        s+=e;
                return s;
           }
           vector<string> getNumberOperator(string str){
                string sst1="";
                vector<string> vecs;
                if(str.size() == 0)
                    return vecs;
                string s = trim(str);
                size_t i=0;
                while(s[i] == '('){
                    operate.push("(");
                    i++;
                }


                sst1+=s[i];
                for(size_t j = i+1;j<s.size();++j){
                    char e = s[j];

                    bool flag = (e == '+' || e == '-' || e == '(' || e == ')') ;
                    if(flag){
                        if(sst1 != "")
                            vecs.push_back(sst1);
                        sst1="";
                        string tmps;
                        tmps+=e;
                        vecs.push_back(tmps);
                    }
                    else
                        sst1+=e;
                }
                if(sst1 != "")
                    vecs.push_back(sst1);
                return vecs;
           }

            int calculate(string s) {
                if(s.empty())
                    return 0;
                stringstream sst;
                sst<<s[0];
                vector<string> svec= getNumberOperator(s);

                for(auto&e:svec){
                    bool flag = (e == "+" || e == "-" || e == "(");
                    if(e == ")"){
                        while(!operate.empty() && operate.top() != "(")
                            performOperate();
                        if(operate.top() == "("){
                            operate.pop();
                            while(!operate.empty() && operate.top() != "(")
                                performOperate();
                        }
                    }
                    else if( flag){
                        operate.push(e);//operator push stack
                    }else{//numbers
                        stringstream ss;
                        ss<<e;
                        int x=1;
                        ss>>x;
                        nums.push(x);
                        while(!operate.empty() &&  operate.top()!= "(" )
                                performOperate();
                    }
                }
                while(!operate.empty())
                    performOperate();
                int x = nums.top();
                nums.pop();
                return x;
            }

            void performOperate() {
                int x2 = nums.top();
                nums.pop();
                int x1 = nums.top();
                nums.pop();
                char ch = operate.top()[0];
                operate.pop();
                switch(ch){
                        case '+': x1+=x2;break;
                        case '-': x1-=x2;break;
                        default:break;
                    }
                nums.push(x1);
            }
};

int main(){
        Solution s;
        string tokens = "1234";
        int res = s.calculate(tokens);
        cout<<"res-> "<<res<<endl;
        return 0;

}
