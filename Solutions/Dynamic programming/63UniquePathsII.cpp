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
    62UniquePaths
    A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

    The robot can only move either down or right at any point in time.
    The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

    How many possible unique paths are there?

    63UniquePathsII
    Follow up for "Unique Paths":

    Now consider if some obstacles are added to the grids. How many unique paths would there be?

    An obstacle and empty space is marked as 1 and 0 respectively in the grid.

    For example,
    There is one obstacle in the middle of a 3x3 grid as illustrated below.

    [
        [0,0,0],
        [0,1,0],
        [0,0,0]
    ]
    The total number of unique paths is 2.

    Note: m and n will be at most 100.

    63UniquePathsII.cpp
*/
/**
    Solutions:
        the first problem,UniquePaths,we can solve the problem with the method that the unique path will be
        the C(m+n-2,n-1),where C(x,y) donate the combination of x,y that is the combination number from x to
        pick up y numbers.but we can solve the problem using dynamic programming method,main idea as follows:

        we can create a two dimension array to store the number of path,where array[i][j] stands for the number
        of path from start point(0,0) to the point (i,j),from the description of the question  we can draw conclusion
        that the point (i,j) can arrive eithor from point(i-1,j) or point(i,j-1) so the

*/
void printVector2D(vector<vector<int>>& dp){
     for(auto& e : dp){
                copy(e.begin(),e.end(),ostream_iterator<int>(cout," "));
                cout<<endl;
    }
    cout<<endl;
}
class Solution {
       public:
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            size_t rows = obstacleGrid.size();
            if(rows == 0)
                return 0;
            size_t cols = obstacleGrid[0].size();
            if(cols == 0 )
                return 0;
            if(obstacleGrid[rows-1][cols-1] == 1)
                return 0;
            vector<vector<int>> dp(rows,vector<int>(cols,0));
            size_t i,j;
            dp[0][0] = obstacleGrid[0][0]==0 ? 1:0;
            for(i=1;i<cols;++i){
                if(obstacleGrid[0][i] == 0)
                    dp[0][i] = dp[0][i-1];
            }
            for(i=1;i<rows;++i){
                if(obstacleGrid[i][0] == 0)
                    dp[i][0] = dp[i-1][0];
            }
            for(i=1;i<rows;++i){
                for(j=1;j<cols;++j){
                    if(obstacleGrid[i][j] == 1)
                        dp[i][j] = 0;
                    else
                        dp[i][j] = dp[i][j-1] + dp[i-1][j];
                }
            }
            return dp[rows-1][cols-1];
        }


};

int main(){
        Solution s;
        vector<vector<int>> array={
        {0},
        {0},
        {0},
        {1},
        {0}
//            {0,0,0,0,1,0,0}
//                {0,0,0,0},
//                {0,1,1,1},
//                {0,0,1,0}
        };
        int a = s.uniquePathsWithObstacles(array);
        cout<<"res:"<<a<<endl;
        return 0;
}
