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
    A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

    The robot can only move either down or right at any point in time.
    The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

    How many possible unique paths are there?

    Note: m and n will be at most 100.

    62UniquePaths.cpp
*/

class Solution {

       public:
           const static int size = 101;
           int   array[size*2][size]={{0}};


        int uniquePaths(int m, int n) {
            for(int i=0;i<size*2;++i){
                for(auto&e : array[i])
                    e = 0;
            }

            m--;
            n--;
            return CombineNumber(m+n,n);
        }

        int CombineNumber(int m,int n){
            if(m == 0 || n == 0 || m== n){
                array[m][n] = 1;
                return 1;
            }
            else if(n == 1){
                array[m][n] = m;
                return m;
            }
            if(array[m][n] != 0)
                return array[m][n];
            else{
                if(array[m-1][n] ==0 && array[m-1][n-1] ==0){
                    return CombineNumber(m-1,n)+CombineNumber(m-1,n-1);
                }


                if(array[m-1][n] !=0 && array[m-1][n-1] !=0){
                    array[m][n] = array[m-1][n-1] + array[m-1][n];

                }else if(array[m-1][n] != 0 ){

                    array[m][n] = array[m-1][n] + CombineNumber(m-1,n-1);

                }else if(array[m-1][n-1] != 0 ){
                    array[m][n] = CombineNumber(m-1,n) + array[m-1][n-1];
                }else{
                    array[m][n] = CombineNumber(m-1,n) + CombineNumber(m-1,n-1);
                }

                return array[m][n];
            }

        }

};

int main(){
        Solution s;
        int m=30,n=15;
        while(1){
            cin>>m>>n;
            int res = s.uniquePaths(m,n);
            cout<<res<<endl;
        }

//        int a =  2310789600;
//        cout<<a<<endl;
        return 0;
}
