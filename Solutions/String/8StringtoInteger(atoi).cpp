#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
/**
    doc
    Implement atoi to convert a string to an integer.

    Hint: Carefully consider all possible input cases.
    If you want a challenge, please do not see below and ask yourself what are the possible input cases.

    Notes: It is intended for this problem to be specified vaguely (ie, no given input specs).
    You are responsible to gather all the input requirements up front.

    Update (2015-02-10):
    The signature of the C++ function had been updated.
    If you still see your function signature accepts a const char * argument, please click the reload button
     to reset your code definition.

    spoilers alert... click to show requirements for atoi.

    Requirements for atoi:
    The function first discards as many whitespace characters as necessary until the first non-whitespace character is found.
     Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible,
     and interprets them as a numerical value.

    The string can contain additional characters after those that form the integral number,
    which are ignored and have no effect on the behavior of this function.

    If the first sequence of non-whitespace characters in str is not a valid integral number,
    or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

    If no valid conversion could be performed, a zero value is returned.
    If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

    Hide Tags Math String

    8StringtoInteger(atoi).cpp
*/
/**
    Solutions:
        what we should pay much attention to is wether  the characters on begin or end is valid.
        what's more, we should consider the overflow when the number is lager than 0x7FFFFFFF or less than 0x80000000.
        we can deal with this problem by using the largest positive number to minus the number that will be added.
*/
class Solution {
    public:
            string trim(string str){
                    if(str.size() == 0)
                        return "";
                   size_t size = str.size();
                   size_t i = 0,j = str.size() -1;
                   string::iterator bit = str.begin(),eit = str.end();
                   while(bit<eit){
                        if((*bit >='0' && *bit <='9') || *bit == '+' || *bit == '-')
                            break;
                        if( *bit > '9' || *bit < '0')
                            return "";
                        if(*bit == ' ')
                            bit++;
                   }
                   string::iterator bit2 = bit+1;
                   while(bit2 < eit){
                        if(*bit2 >= '0' && *bit2 <= '9')
                            bit2++;
                        else
                            break;
                   }
                   return string(bit,bit2);
            }

        int myAtoi(string str) {
            str = trim(str);
            size_t i=0,size = str.size();
            if(size == 0)
                return 0;
            int res = 0;
            int flag = 0;
            if(str[0] == '-'){
                i=1;
                flag = 1;
            }
            if(str[0] == '+')
                i++;
            while(i<size){
                int x = str[i]-'0';
                if(x>9 || x < 0)
                    return 0;
                if(res > 0x7FFFFFFF/10){
                    if(flag)
                        return 0x80000000;
                    return 0x7FFFFFFF;
                }

                res*=10;
                if(res > 0x7FFFFFFF - x){
                    if(flag)
                        return 0x80000000;
                    return 0x7FFFFFFF;
                }
                res+=x;
                i++;
            }
            if(flag)
                res= -res;
            return res;
        }
};

int main(){

    Solution s;
    string str = "   -000010";
    str = s.trim(str);
    int res = s.myAtoi(str);
    cout<<res<<endl;
//    int a = (0x80000000);
//    cout<<a<<endl;
    cout<<"hello c++11"<<endl;
    return 0;
}
