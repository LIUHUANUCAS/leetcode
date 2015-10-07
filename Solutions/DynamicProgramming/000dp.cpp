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



    name.cpp
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

};

int main(){
        Solution s;

        cout<<"Dynamic programming"<<endl;
        return 0;

}
