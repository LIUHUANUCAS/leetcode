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
        Given numRows, generate the first numRows of Pascal's triangle.

        For example, given numRows = 5,
        Return

        [
             [1],
            [1,1],
           [1,2,1],
          [1,3,3,1],
         [1,4,6,4,1]
        ]

    118Pascal's Triangle.cpp
*/

class Solution {

       public:
           vector<vector<int>> generate(int numRows) {
               if(numRows == 0)
                return vector<vector<int>> ();


                vector<int> vec1(1,1);
                if(numRows == 1){
                    vector<vector<int> > res;
                    res.push_back(vec1);
                    return res;
                }
                vector<int> vec2(2,1);
                vector<vector<int> > vec={vec1,vec2};
                for(int i=2;i<numRows;++i){
                        vector<int> tmp(1,1);
                        vector<int> front = vec[i-1];
                    for(int j= 1;j<i;++j){
                        int v = front[j-1]+front[j];
                        tmp.push_back(v);
                    }
                    tmp.push_back(1);
                    vec.push_back(tmp);
                }

//                for(auto& v:vec){
//                    copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));
//                    cout<<endl;
//                }
                return vec;
            }

};

int main(){
        Solution s;
        int array[]={1,2,3,4,5};
        int a[] = {8,7,6};
        s.generate(1);
//        vector<int> res (array,array+ sizeof(array)/sizeof(int));
//        copy(res.begin(),res.end(),ostream_iterator<int>(cout," "));


}
