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
#include<string>
using namespace std;


/**
    doc
    Implement a basic calculator to evaluate a simple expression string.

    The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

    You may assume that the given expression is always valid.

    Some examples:
    "3+2*2" = 7
    " 3/2 " = 1
    " 3+5 / 2 " = 5
    Note: Do not use the eval built-in library function.


   227BasicCalculatorII.cpp
*/
/**
    Solutions:
        The problem is samaliar with the 224BasicCalculator,which hava operators:+,-,(,).But this problem has
        +,-,*,/ four operators.as we have known that the operator *,/ have priority over operator +,-. so we must
        consider the caculation order when dealing with the express string. when the operator is '*' or '/',we will
        push it into the operator stack.when the stack has one + or -,we will not caculate the value,until there is
        a / or *.we will first caculate the express about * /,and then caculate until the stack is empty.
        finally, we will pop the result from the stack.


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
                sst1+=s[0];
                for(size_t j = i+1;j<s.size();++j){
                    char e = s[j];

                    bool flag = (e == '+' || e == '-' || e == '*' || e == '/') ;
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
//                        cout<<e<<endl;
                    bool flag = (e == "+" || e == "-" || e == "*"||e=="/");
                    if( flag){
                        if(e == "+" || e == "-")
                            while(!operate.empty()){
                                performOperate();
                            }
                        operate.push(e);//operator push stack
                    }else{//numbers
                        int x = atoi(e.c_str());
                        nums.push(x);
                        bool f = 0;
                        while(!operate.empty() &&  (operate.top() == "*" || operate.top() == "/") ){
                                    performOperate();
                                    f = 1;
                        }

//                        while(f && !operate.empty() && operate.top() == "-"){
//                            cout<<"f:"<<f<<endl;
//                            performOperate();
//                        }

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
//                cout<<"x1="<<x1<<" x2 = "<<x2<<" "<<x1<<ch<<x2<<endl;
                switch(ch){
                        case '+': x1+=x2;break;
                        case '-': x1-=x2;break;
                        case '*': x1*=x2;break;
                        case '/': x1/=x2;break;
                        default:break;
                    }
                nums.push(x1);
            }
};

int main(){
        Solution s;
        vector<string> vecs={"3+2*2-2+3/2"," 3/2 "," 3+2-3 - 5 / 2 -13","12-3*4","1-1+1","1-5*2/6-3"};

        for(auto&str:vecs){
            int res = s.calculate(str);
            cout<<"res-> "<<res<<endl;
        }
        string sn = "1023";

        int num = atoi(sn.c_str());
        cout<<num<<endl;
        return 0;

}
