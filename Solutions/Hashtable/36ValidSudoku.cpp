#include<iostream>
#include<vector>
#include <cstdlib>
#include<iterator>
using namespace std;


/**
    Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
    The Sudoku board could be partially filled, where empty cells are filled with the character '.'

    Note:
    A valid Sudoku board (partially filled) is not necessarily solvable.
    Only the filled cells need to be validated.

    36ValidSudoku.cpp
*/
const static int size=9;
//int arr[size+1];
//{
//{'.', '.', '4', '.', '.', '.', '6', '3', '.'},
//{'.', '.', '.', '.', '.', '.', '.', '.', '.'},
//{'5', '.', '.', '.', '.', '.', '.', '9', '.'},
//{'.', '.', '.', '5', '6', '.', '.', '.', '.'},
//{'4', '.', '3', '.', '.', '.', '.', '.', '1'},
//{'.', '.', '.', '7', '.', '.', '.', '.', '.'},
//{'.', '.', '.', '5', '.', '.', '.', '.', '.'},
//{'.', '.', '.', '.', '.', '.', '.', '.', '.'},
//{'.', '.', '.', '.', '.', '.', '.', '.', '.'}
//}
char array[][size]={
//    {'5','3','.','.', '7','.','.','.','.'},
//    {'6','.','.','1', '9','5','.','.','.'},
//    {'.','9','8','.', '.','.','.','6','.'},
//    {'8','.','.','.', '6','.','.','.','3'},
//    {'4','.','.','8', '.','3','.','.','1'},
//    {'7','.','.','.', '2','.','.','.','6'},
//    {'.','6','.','.', '.','.','2','8','.'},
//    {'.','.','.','4', '1','9','.','.','5'},
//    {'.','.','.','.', '8','.','.','7','9'}
{'.', '.', '4', '.', '.', '.', '6', '3', '.'},
{'.', '.', '.', '.', '.', '.', '.', '.', '.'},
{'5', '.', '.', '.', '.', '.', '.', '9', '.'},
{'.', '.', '.', '5', '6', '.', '.', '.', '.'},
{'4', '.', '3', '.', '.', '.', '.', '.', '1'},
{'.', '.', '.', '7', '.', '.', '.', '.', '.'},
{'.', '.', '.', '5', '.', '.', '.', '.', '.'},
{'.', '.', '.', '.', '.', '.', '.', '.', '.'},
{'.', '.', '.', '.', '.', '.', '.', '.', '.'}

};
bool validLine(vector<char>& line){
    const int size1 = 9;
    int arr[size1+1];
    fill(arr,arr+size1+1,0);

//    cout<<"=============================="<<endl;
    for(vector<char>::iterator it=line.begin();it != line.end();++it){
//        cout<<*it<<" ";
        if(*it != '.')
             arr[*it - '0']++;

        else
            arr[0]++;
    }
//    cout<<endl;
//    copy(arr,arr+size+1,ostream_iterator<int>(cout," "));
//    cout<<endl;
    for(int i=1;i<size+1;++i){
        if(arr[i] > 1){
//            cout<<"i"<<i<<endl;
            return false;
        }

    }

    return true;
}

bool isValidSudoku(vector<vector<char> >& board) {
     for(int i=0;i<size;++i){
        bool flag = validLine(board[i]);
        if(flag == false)
        {
//            cout<<"flag"<<i<<endl;
            return false;
        }

     }

     for(int i=0;i<size;++i){
        vector<char> tmp;
        for(int j=0;j<size;++j)
            tmp.push_back(board[i][j]);
        copy(tmp.begin(),tmp.end(),ostream_iterator<char>(cout," "));
        cout<<endl;
        if(validLine(tmp) == false){
//                cout<<"tmp"<<endl;
            return false;
        }
     }

     for(int i=1;i<size;i+=3){
        for(int j=1;j<size;j+=3){
                vector<char> line2;
            for(int k=0;k<3;++k){
                for(int m=0;m<3;++m){
                        line2.push_back(board[i-1+k][j-1+m]);
                }//k
            }//m
            if(validLine(line2) == false)
                return false;
        }//j

     }//i
    return true;
}

class Solution {

public:
    const static  int size=9;

    bool validLine(vector<char>& line){
    int arr[size +1 ];
    fill(arr,arr+size+1,0);
    for(vector<char>::iterator it=line.begin();it != line.end();++it){
        if(*it != '.')
             arr[*it - '0']++;
        else
            arr[0]++;
    }
    for(int i=1;i<size+1;++i){
        if(arr[i] > 1)
            return false;
    }
    return true;
}


bool isValidSudoku(vector<vector<char> >& board) {
    //line
     for(int i=0;i<size;++i){
        bool flag = validLine(board[i]);
        if(flag == false)
            return false;
     }
    //column
     for(int i=0;i<size;++i){
        vector<char> tmp;
        for(int j=0;j<size;++j)
            tmp.push_back(board[j][i]);
//        cout<<"=================================="<<endl;
//        copy(tmp.begin(),tmp.end(),ostream_iterator<char>(cout," "));
//        cout<<endl;
//        cout<<"=================================="<<endl;

        if(validLine(tmp) == false)
            return false;
     }
     for(int i=1;i<size;i+=3){
        for(int j=1;j<size;j+=3){
                vector<char> line2;
            for(int k=0;k<3;++k){
                for(int m=0;m<3;++m)
                    line2.push_back(board[i-1+k][j-1+m]);
                //k
            }//m
            if(validLine(line2) == false)
                return false;
        }//j
     }//i
    return true;
}
};




int main(){

        vector<vector<char> > board;
        for(int i=0;i<size;++i){
            vector<char> line(*(array+i),*(array+i) +size);
            board.push_back(line);
        }

        for(int i=0;i<size;++i){
            copy(board[i].begin(),board[i].end(),ostream_iterator<char>(cout," "));
            cout<<endl;
        }
        Solution s;

        bool flag = s.isValidSudoku(board);
        cout<<flag<<endl;

}
