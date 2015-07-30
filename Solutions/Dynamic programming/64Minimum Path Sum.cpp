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
    Given a m x n grid filled with non-negative numbers,
    find a path from top left to bottom right which minimizes the sum of all numbers along its path.

    Note: You can only move either down or right at any point in time.

    64Minimum Path Sum.cpp
*/

void printMatrix(vector<vector<int> > res){
     int size = res.size();
     for(int i=0;i<size;++i)
        cout<<"==";
     cout<<endl;
     for(auto& line:res){
            copy(line.begin(),line.end(),ostream_iterator<int>(cout," "));
            cout<<endl;
        }

}
class Solution {

       public:
        int minPathSum(vector<vector<int>>& grid) {
            int m=grid.size();
            int n = grid[0].size();
            vector<vector<int> > dis;
            for(int i=0;i<m;++i){
                vector<int> col(n,0);
                dis.push_back(col);
            }
            dis[0][0] = grid[0][0];
            for(int i=1;i<n;++i)
                dis[0][i] = dis[0][i-1] + grid[0][i];
//            copy(grid[0].begin(),grid[0].end(),dis[0].begin());
            for(int i=1;i<m;++i){
                dis[i][0] = dis[i-1][0] + grid[i][0];
            }
//            printMatrix(grid);
//            cout<<endl;
//            printMatrix(dis);

            for(int i=1;i<m;++i){
                for(int j=1;j<n;++j){
                    dis[i][j] = grid[i][j] + min(dis[i-1][j],dis[i][j-1]);
//                     printMatrix(dis);
                }
            }

//            printMatrix(dis);

            return dis[m-1][n-1];

        }

};

int main(){
        Solution s;
        //        vector< vector<int> >
//                res={
//                    {1,2,3,4,-1},
//                    {4,5,6,7,-2},
//                    {8,9,10,11,-3},
//                    {12,13,14,15,-4},
//                    {16,17,18,19,-5}
//                    };
        vector< vector<int> >
                res={
                    {1,2,3},
                    {4,5,6},
                    {7,8,9 }
                    };
//        vector< vector<int> >
//                res={
//                    {1,2},
//                    {4,5}
//                    };

        int d  = s.minPathSum(res);
        cout<<d<<endl;
}
