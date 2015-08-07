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
/**
    Solutions:
        the first problem,UniquePaths,we can solve the problem with the method that the unique path will be
        the C(m+n-2,n-1),where C(x,y) donate the combination of x,y that is the combination number from x to
        pick up y numbers.Besides we can solve the problem using dynamic programming method,main idea as follows:

        we can create a two dimension array to store the number of path,where array[i][j] stands for the number
        of path from start point(0,0) to the point (i,j),from the description of the question,we can draw conclusion
        that the point (i,j) can arrive either from point(i-1,j) or point(i,j-1) so the number of path from point(0,0)
        to point(i,j)  is equal to the number of path from point(0,0) to point(i,j-1) plus the number of path from
        point(0,0) to point(i-1,j).that is array[i][j] = array[i][j-1] + array[i-1][j]. the figure following illustrates
        the meaning of the equation.
        array----------------------->j
             |
             |
             |                (i-1,j)
             |                  \|/
             |       (i,j-1)-> (i,j)
             |
         i '\|/

        ps:C(m,n) = C(m-1,n) + C(m-1,n-1)
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
        return 0;
}
