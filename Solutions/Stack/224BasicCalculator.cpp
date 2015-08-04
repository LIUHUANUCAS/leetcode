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
        stack<char> operate;

       public:
           string trim(string str){
               if(str.size() == 0)
                return "";
//                string::iterator sitb = str.begin();
//                size_t i = 0;
//                size_t j = str.size()-1;
//                cout<<str<<endl;
//                while(str[i] == ' ')
//                    i++;
//
//                while(str[j] == ' ')
//                    j--;
//                string s = string(sitb+i,sitb+j+1);
                stringstream sst;
                for(auto& e:str){
                    if(e!= ' ')
                        sst<<e;
                }

                return sst.str();

           }
           vector<string> getNumberOperator(string str){
                string sst1="";
                vector<string> vecs;
                if(str.size() == 0)
                    return vecs;
                string s = trim(str);


                for(size_t i = 0;i<s.size();++i){
                    char e = s[i];

                    bool flag = (e == '+' || e == '-' || e == '(' || e == ')') ;
                    if(flag){

                        vecs.push_back(sst1);
                        sst1="";
                        char tmp[3]="";
                        tmp[0] = e;
                        vecs.push_back(string(tmp));
                    }
                    else
                        sst1+=e;
                }

                vecs.push_back(sst1);

                return vecs;
           }

            int calculate(string s) {
                if(s.empty())
                    return 0;
                stringstream sst;
                sst<<s[0];
                for(size_t i = 1;i<s.size();++i){

                    char e = s[i];
//                    if()
                    if(e == ' ')
                        continue;
//                    cout<<"===================e:"<<e<<endl;
                    bool flag = (e == '+' || e == '-' || e == '(');
                    if(e == ')'){

                        while(operate.top() != '(')
                            performOperate();
                        operate.pop();
                        while(!operate.empty()&&operate.top() != '(')
                            performOperate();
//                        cout<<"pop ("<<endl;
                    }else if(flag)
                        operate.push(e);
                    else{
                        stringstream ss;
                        ss<<e;
//                        cout<<"ss->"<<ss.str()<<endl;
                        int x=1;
                        ss>>x;
//                        cout<<"x "<<x<<endl;
                        nums.push(x);
                        if(!operate.empty()&&operate.top() != '(')
                            performOperate();
//                        while(operate.top()!= '(' && !operate.empty()){
//                                performOperate();
//                            }
                    }

                }


//                cout<<"hello"<<endl;
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
                char ch = operate.top();
                operate.pop();
//                char ch = e[0];
//                cout<<"x1="<<x1<<" x2= "<<x2<< " -> "<< x1<<ch<<x2<<endl;
                switch(ch){
                        case '+': x1+=x2;break;
                        case '-': x1-=x2;break;
                        default:break;
                    }
//                cout<<"res x1 "<<x1<<endl;
                nums.push(x1);
            }

};

int main(){
        Solution s;
//        vector<string> tokens = {"2", "1", "+", "3", "*"};
        string tokens = "123+1 +1+(1 +2 -3 )";
        vector<string> vecs = s.getNumberOperator(tokens);
        copy(vecs.begin(),vecs.end(),ostream_iterator<string>(cout,""));
        cout<<endl;
//        stringstream sst;
//        int x = 123;
//        sst<<"321";
//        sst>>x;
//        int y =1;
//        sst>>y;
//        sst<<x;
//        x = 100;
//        sst<<x;
//        string str;
//        sst>>str;
//        cout<<x<<" "<<y<<endl;
//        sprintf(x,"%s",str.c_str());

}
