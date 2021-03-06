#include<iostream>
#include<vector>
#include <cstdlib>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;


/**
    doc

    Implement pow(x, n).

    50pow(x, n).cpp
*/

class Solution {

       public:
        double myPow(double x, int n) {

                if(n==0)
                    return 1;
                if(n == 1)
                    return x;
                if(n < 0){
                    x = 1/x;
                    n = -n;
                }

                double tmp = myPow(x,n/2);
                if(n%2==1){
                    return x * tmp* tmp;
                }else
                {
                    return tmp*tmp;
                }
        }

};

int main(){
        Solution s;
        int n=-3;
        double x= 34.00515;
        double res = s.myPow(x,n);
        cout<<res<<endl;
//        for(int i = 1;i<31;++i)
//        cout<<s.myPow(2,i)<<endl;

}
