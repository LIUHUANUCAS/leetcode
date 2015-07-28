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

class Solution {

       public:

};

int main(){
        Solution s;
        int array[]={1,2,3,4,5};
        int a[] = {8,7,6};
        vector<int> res (array,array+ sizeof(array)/sizeof(int));
        copy(res.begin(),res.end(),ostream_iterator<int>(cout," "));


}
