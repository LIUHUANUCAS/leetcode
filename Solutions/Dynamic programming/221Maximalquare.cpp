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
    Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.

    For example, given the following matrix:

    1 0 1 0 0
    1 0 1 1 1
    1 1 1 1 1
    1 0 0 1 0
    Return 4.
    Credits:
    Special thanks to @Freezen for adding this problem and creating all test cases.

    Hide Tags Dynamic Programming


    221Maximalquare.cpp
*/
void printMatrix(vector<vector<int>>& matrix){
    cout<<"============begin=============="<<endl;
    for(auto& rows:matrix){
        copy(rows.begin(),rows.end(),ostream_iterator<int>(cout," "));
        cout<<endl;
    }
    cout<<"============over==============="<<endl;

}
class Solution {

        public:
            int maximalSquare(vector<vector<char>>& matrix) {

                size_t rows = matrix.size();
                if(rows == 0)
                    return 0;

                size_t cols = matrix[0].size();
                if(cols == 0)
                    return 0;
                vector<vector<int> > d(rows,vector<int>(cols,0));
                d[0][0] = matrix[0][0]-'0';
                size_t i,j;
                for( i=1;i<rows;++i){
                    d[i][0] = max(d[i-1][0],matrix[i][0]-'0');
                }
                for(j=1;j<cols;++j){
                    d[0][j] = max(d[0][j-1],matrix[0][j]-'0');
                }
//                printMatrix(matrix);
//                printMatrix(d);
//                int edge = 1;
                for(i=1;i<rows;++i){
                    for(j=1;j<cols;++j){
                        if(matrix[i][j] == '1' && matrix[i-1][j-1]=='1' && matrix[i][j-1] == '1' && matrix[i-1][j] == '1'){
                            int t = sqrt(d[i-1][j-1]) + 1;
                            d[i][j]=t*t;
                        }
                        else{
                            d[i][j] = matrix[i][j]-'0';
                        }

                    }
                }
                printMatrix(d);
                int maxt = 0;
                for(auto&e:d){
                    int tm = *max_element(e.begin(),e.end());
                    if(tm > maxt)
                        maxt = tm;
                }
//                cout<<maxt<<endl;
                return maxt;
            }

};

int main(){
        Solution s;
        vector<vector<char>> matrix = {
             {'1', '1', '0', '0', '0'},
             {'1', '1', '1', '0', '0'},
             {'1', '1', '1', '1', '1'},
             {'0', '1', '0', '1', '1'}
        };
        for(auto&rows:matrix){
            copy(rows.begin(),rows.end(),ostream_iterator<char>(cout," "));
            cout<<endl;
        }
        cout<<"=============================="<<endl;
        int res = s.maximalSquare(matrix);
        cout<<res<<endl;
        cout<<"Dynamic programming"<<endl;
        return 0;

}
