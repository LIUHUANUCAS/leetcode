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

    Evaluate the value of an arithmetic expression in Reverse Polish Notation.

    Valid operators are +, -, *, /. Each operand may be an integer or another expression.

    Some examples:
    ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
    ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6



    150Evaluate ReversePolishNotation.cpp
*/
/**
    Solutions:
      we can use two stack,one for store the number or the result of the calculation,the other is used
      to store the operator.details can be expressed in Reverse Polish Notation.
*/

class Solution {
        private:
        stack<int> nums;
        stack<string> operate;

       public:
            int evalRPN(vector<string>& tokens) {
                for(auto&e:tokens){

                    bool flag = (e == "+" || e == "-" || e == "*" || e == "/" );
                    if(flag){
//                        cout<<"e-> "<<e<<endl;
                        if(operate.empty()){
                            performOperate(e);
                            continue;
                        }
                        string tops = operate.top();
                        operate.pop();
                        performOperate(tops);
                    }
                    else{

                        stringstream ss;
                        ss<<e;
                        int x=1;
                        ss>>x;
//                        cout<<"x "<<x<<endl;
                        nums.push(x);
                    }
                }
                int res = nums.top();
                nums.pop();
                return res;

            }

            void performOperate(string e) {
                int x2 = nums.top();
                nums.pop();
                int x1 = nums.top();
                nums.pop();
                char ch = e[0];
//                cout<<"x1="<<x1<<" x2= "<<x2<< " -> "<< x1<<ch<<x2<<endl;
                switch(ch){
                        case '+': x1+=x2;break;
                        case '-': x1-=x2;break;
                        case '*': x1*=x2;break;
                        case '/': x1/=x2;break;
                        default:break;
                    }
//                cout<<"res x1 "<<x1<<endl;
                nums.push(x1);
            }

};

int main(){
        Solution s;
//        vector<string> tokens = {"2", "1", "+", "3", "*"};
        vector<string> tokens = {"4", "13", "5", "/", "+" , "100","*"};
        int x = s.evalRPN(tokens);


        cout<<x<<endl;
//        sprintf(x,"%s",str.c_str());

}
