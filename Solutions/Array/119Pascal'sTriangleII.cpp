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
    Given an index k, return the kth row of the Pascal's triangle.

    For example, given k = 3,
    Return [1,3,3,1].

    Note:
    Could you optimize your algorithm to use only O(k) extra space?

        [
             [1],           1
            [1,1],          2
           [1,2,1],         3
          [1,3,3,1],        4
         [1,4,6,4,1]        5
        ]

    119Pascal's TriangleII.cpp
*/

class Solution {

    public:
           vector<int> getRow(int rowIndex) {
               rowIndex++;
               if(rowIndex == 1)
                    return vector<int>(1,1);
                if(rowIndex < 0 )
                    return vector<int>();
                vector<int> res(rowIndex,1);
                for(int i=2;i<rowIndex;++i){
                        int val = res[0];
                    for(int j=0;j<i-1;++j){
                        int tmp = res[j+1];
                        res[j+1] = tmp + val;
                        val = tmp;
                    }
                }
                return res;
           }

};

int main(){
        Solution s;
        int array[]={1,2,3,4,5};
        int a[] = {8,7,6};
        vector<int > res = s.getRow(3);
        copy(res.begin(),res.end(),ostream_iterator<int>(cout," "));
        cout<<endl;
//        vector<int> res (array,array+ sizeof(array)/sizeof(int));
//        copy(res.begin(),res.end(),ostream_iterator<int>(cout," "));


}
