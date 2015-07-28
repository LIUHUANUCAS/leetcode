#include<iostream>
#include<vector>
#include <cstdlib>
#include<iterator>
using namespace std;


/**
    doc
    Given a non-negative number represented as an array of digits, plus one to the number.

    The digits are stored such that the most significant digit is at the head of the list.

    66PlusOne.cpp
*/

class Solution {

       public:
           vector<int> plusOne(vector<int>& digits) {
                int i= digits.size()-1;
                digits[i]++;
                int flag = 0;
                if(digits[i] >=10){
                    flag = 1;
                    digits[i]-=10;
                }
                for(i--;i>=0 && flag;--i){
                    if(++digits[i]>=10){
                            digits[i] -=10;
                            flag = 1;
                    }else{
                        flag = 0;
                    }
                }
                vector<int>
                    res(digits.begin(),digits.end());
                if(flag == 1){
                    res.insert(res.begin(),1);
                }
            return res;
           }
};

int main(){
        Solution s;
        int array[]={1,2,3,4,5};
        int a[] = {8,7,6};
        vector<int> res (array,array+ sizeof(array)/sizeof(int));
//        vector<int> res = s.plusOne(dig);
        vector<int>::iterator it = res.end();
        res.insert(it,a,a+sizeof(a)/sizeof(int));
        copy(res.begin(),res.end(),ostream_iterator<int>(cout," "));


}
