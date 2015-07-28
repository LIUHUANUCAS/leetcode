#include<iostream>
#include<vector>
#include<cstdlib>
#include<iterator>
#include<algorithm>
#include<string>
#include<cmath>

using namespace std;


/**
    doc
    You are given an n x n 2D matrix representing an image.

    Rotate the image by 90 degrees (clockwise).

    Follow up:
    Could you do this in-place?

    48RotateImage.cpp
    *-------*------*
    |      |       |
    |  1   |   2   |
    |______|_______|=============>>>>>>>>>>
    |      |       |
    |  3   |   4   |
    |______|_______|

      *-------*
      |\     /|
      | \ 4 / |
      |  \ /  |
      | 1 \ 3 |
      |  / \  |
      | / 2 \ |
      |/_____\|
        ======>>>>>>>>>>
      *-------*
      |\     /|
      | \ 1 / |
      |  \ /  |
      | 4 \ 2 |
      |  / \  |
      | / 3 \ |
      |/_____\|
      ======>>>>>>>>>>
      *-------*
      |\     /|
      | \ 1 / |
      |  \ /  |
      | 2 \ 4 |
      |  / \  |
      | / 3 \ |
      |/_____\|

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
        void rotate(vector<vector<int>>& matrix) {
                rotateSystric(matrix);
                printMatrix(matrix);
                rotateyline(matrix);
                printMatrix(matrix);
        }
        void rotateSystric(vector<vector<int>>& matrix) {
            int row = matrix.size();
            int col = row;
            for(int i=0;i<row;++i)
                for(int j=i+1;j<col;++j){
                        int tmp = matrix[i][j];
                        matrix[i][j] = matrix[j][i];
                        matrix[j][i] = tmp;
                }
        }

    void rotateyline(vector<vector<int> >& matrix) {
            int row = matrix.size();
            int col = row;

            for(int i=0;i<row/2;++i)
                for(int j=i;j<=col - i ;++j){
                        int tmp = matrix[i][j];
                        int index = row - j-1;
                            cout<<"k"<<index<<endl;
                        matrix[i][j] = matrix[index][i];

                        matrix[index][i] = tmp;
                }
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
//        vector< vector<int> >
//                res={
//                    {1,2,3},
//                    {4,5,6},
//                    {7,8,9 }
//                    };
        vector< vector<int> >
                res={
                    {1,2},
                    {4,5}
                    };

        for(auto& line:res){
            copy(line.begin(),line.end(),ostream_iterator<int>(cout," "));
            cout<<endl;
        }
        cout<<"====================="<<endl;

        s.rotate(res);
//        for(auto& line:res){
//            copy(line.begin(),line.end(),ostream_iterator<int>(cout," "));
//            cout<<endl;
//        }


//        vector<int> res (array,array+ sizeof(array)/sizeof(int));
//        copy(res.begin(),res.end(),ostream_iterator<int>(cout," "));


}
