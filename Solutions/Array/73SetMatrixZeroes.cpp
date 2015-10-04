#include<iostream>
#include<vector>
#include<cstdlib>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>

using namespace std;


/**
    doc


    000cpptemplate.cpp
*/

class Solution {

       public:
            void setZeroes(vector<vector<int>>& matrix) {
                int m = matrix.size();
                if(m ==0)
                    return ;
                size_t n = matrix[0].size();
                if(n == 0)
                    return ;
                bool *row = new bool[m];
                bool *col = new bool[n];
                for(int i=0;i<m;++i)
                    row[i]=0;
                for(int i=0;i<n;++i)
                    col[i]=0;
                 
                    
                
               for(int i=0;i<m;++i){
                    for(int j=0;j<n;++j){
                        int e = matrix[i][j];
                        if(e == 0){
                            row[i]=1;
                            col[j]=1;
                        }//if
                    }//for 
                }//for 
                for(int i=0;i<m;++i){
                    for(int j=0;j<n;++j){
                        if(row[i] || col[j] )
                            matrix[i][j] = 0;
                    }//for 
                }//for 
                delete [] row;
                delete [] col;
            }

};

int main(){
        Solution s;
        vector<vector<int>> res = {
            {1,2,3,4},
            {1,2,0,4},
            {0,2,1,4}
        };
        s.setZeroes(res);
        for(auto& line : res){
            copy(line.begin(),line.end(),ostream_iterator<int>(cout," "));
            cout<<endl;
        }


}
