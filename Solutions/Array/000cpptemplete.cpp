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
<<<<<<< HEAD
void printMatrix(vector<vector<int>>& matrix){
    for(auto&res:matrix){
        copy(res.begin(),res.end(),ostream_iterator<int>(cout," "));
        cout<<endl;
    }
    cout<<endl;
}

void printVector(vector<int>& res){
        copy(res.begin(),res.end(),ostream_iterator<int>(cout," "));
        cout<<endl;

}

=======
void printmatrix(vector<vector<int>> res ){
    
    for(auto& line : res){
        copy(line.begin(),line.end(),ostream_iterator<int>(cout," "));
        cout<<endl;
    }
}
>>>>>>> 5a32aa3401b50119f7710923fe1810ae5a72d16d
class Solution {

       public:

};

int main(){
        Solution s;
<<<<<<< HEAD
        vector<int>nums = {1,2,3,4,5};

        return 0;
//        vector<int> res (array,array+ sizeof(array)/sizeof(int));
//        copy(res.begin(),res.end(),ostream_iterator<int>(cout," "));

=======
        vector<int> array ={1,2,3,4,5};
        copy(array.begin(),array.end(),ostream_iterator<int>(cout," "));
        
        return 0;
>>>>>>> 5a32aa3401b50119f7710923fe1810ae5a72d16d

}
