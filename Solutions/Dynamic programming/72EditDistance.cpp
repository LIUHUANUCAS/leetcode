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
    Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

    You have the following 3 operations permitted on a word:

    a) Insert a character
    b) Delete a character
    c) Replace a character


    72EditDistance.cpp
*/
/**
    Solutions:
        As the edit distance defined,we can draw conclusion that there are two main key points.
        assume that there are two strings,x[0,m],y[0,n],we will construct a 2D array-ds[0,m][0,n] to denote
        the edit distance,where ds[i][j] stands for the edit distance of x[0,i],y[0][j].
        Two key points:

        1st,if x[s] == y[t] that is to say,we will compute the distance of x[0,s-1],y[0,t-1],which is ds[s-1][t-1]
        a subproblem.
        2nd,if x[s] != y[t],we will get the ds[s][t] from the distance of x[s-1] with y[t],a subproble of
        the initial problem ! ds[s-1][t]
        or the distance of x[s] with y[t-1],another subproblem of the initial problem! ds[s][t-1]!
        but which one the ds[s][t] depends on ? we should pay attention to the definition of
        the 2D array ds. ds[i][j] stands for the minimum operator to transfer word x[0,i] to y[0,j] so we will
        choose the min value of ds[s-1][t],ds[s][t-1]

        formulation:
            ds[i][j] = min(ds[i-1][j] + 1,ds[i][j-1] + 1,ds[i-1][j-1] + distance of x[i],y[j])

        from other perspective,we can draw conclusion that ds[i][j] will come from three aspects,one is the left of location
        (i,j)--(i,j-1) ,other is up of location of (i,j)--(i-1,j) and last one is left-up -- (i-1,j-1).


*/

void printMatrix(vector<vector<int>> matrix){
    for(auto&row:matrix){
        copy(row.begin(),row.end(),ostream_iterator<int>(cout," "));
        cout<<endl;
    }
    cout<<endl;
}

class Solution {

       public:
            int minDistance(string word1 , string word2) {
                size_t cols = word2.size();
                size_t rows = word1.size();
                if(cols ==0 && rows == 0)
                    return 0;
                if(rows == 0)
                    return word2.size();
                if(cols == 0)
                    return word1.size();
                vector<vector<int>> ds(rows+1,vector<int>(cols+1,0));
                size_t i,j;
                for(i=0;i<=rows;++i)
                    ds[i][0] = i;

                for(j=0;j<=cols;++j)
                    ds[0][j] = j;

                for(i=0;i< rows;++i){
                    for(j=0;j< cols;++j){
                        size_t jj = j+1;
                        size_t ii = i+1;
                        int tmin = min(ds[ii-1][jj],ds[ii][jj-1])+1;
                        int dsd = ds[ii-1][jj-1] + score(word1[i],word2[j]);
                        ds[ii][jj] = min(tmin,dsd);//*min_element(array,sizeof(array)/sizeof(int) + array);
                    }
                }

                return ds[rows][cols];
            }

            int score(char ch1,char ch2){
                if(ch1 == ch2)
                    return 0;
                return 1;
            }

};

int main(){
        Solution s;
        string word1="EXPONENTIAL";//EXPONENTIAL
        string word2="POLYNOMIAL";//POLYNOMIAL
        int dis = s.minDistance(word1,word2);
        cout<<dis<<endl;
        cout<<"Dynamic programming"<<endl;
        return 0;

}
