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

class Solution {

       public:

};

int main(){
        Solution s;
        vector<int>nums = {1,2,3,4,5};

        return 0;
//        vector<int> res (array,array+ sizeof(array)/sizeof(int));
//        copy(res.begin(),res.end(),ostream_iterator<int>(cout," "));


}
