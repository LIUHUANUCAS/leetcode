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


    000cpptemplate.cpp
*/
void printmatrix(vector<vector<int>> res ){
    
    for(auto& line : res){
        copy(line.begin(),line.end(),ostream_iterator<int>(cout," "));
        cout<<endl;
    }
}
class Solution {

       public:

};

int main(){
        Solution s;
        vector<int> array ={1,2,3,4,5};
        copy(array.begin(),array.end(),ostream_iterator<int>(cout," "));
        
        return 0;

}
