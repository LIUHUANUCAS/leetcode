#include<iostream>
#include<vector>
#include<cstdlib>
#include<iterator>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstdio>
#include<sstream>
#include<strstream>

using namespace std;


/**
    doc
    Given a sorted integer array without duplicates,
    return the summary of its ranges.

    For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].

    228Summary Ranges.cpp
*/

class Solution {

       public:
            vector<string> summaryRanges(vector<int>& nums) {
                    int n = nums.size();
                    vector<string> range;
                    if(n == 0)
                        return range;
                    char tmps[33];
                    if(n == 1){
                        sprintf(tmps,"%d",nums[0]);
                        string s(tmps);
                        range.push_back(s);
                        return range;
                    }

                    int start = nums[0];
                    int single = 1;
                    for(int i= 1;i<n;++i){
                        if(nums[i] - nums[i-1] == 1){
                            single = 0;
                            continue;
                        }
                        else{
                                int end = nums[i-1];
                                stringstream sst;
                                sst<<start;
                                sprintf(tmps,"%d",start);
                                string str(tmps);
                                if(single == 1){
                                    start = nums[i];
                                    range.push_back(sst.str());
//                                    range.push_back(str);
                                    continue;
                                }
                                single = 1;
                                sst<<"->";
                                sst<<end;
//                                str+="->";
//                                sprintf(tmps,"%d",end);
//                                str+= string(tmps);
//                                range.push_back(str);
                                range.push_back(sst.str());
                                start = nums[i];
                            }

//                        }//end else

                    }//end for
                    sprintf(tmps,"%d",start);
                    string str(tmps);
                    if(single == 1){
                        range.push_back(str);
                        return range;
                    }

                    str+="->";
                    sprintf(tmps,"%d",nums[n-1]);
                    str+= string(tmps);
                    range.push_back(str);
                    return range;
            }
};

int main(){
        Solution s;
        vector<int> array={1,3,5,6,7,8,9};

        copy(array.begin(),array.end(),ostream_iterator<int>(cout," "));
        cout<<endl;
        vector<string> res = s.summaryRanges(array);


        copy(res.begin(),res.end(),ostream_iterator<string>(cout," "));
        cout<<endl;
//        stringstream ss;
//        string st = "afasdf";
//        ss<< array[0];
//        ss<<st;
//        string str = ss.str();
//        cout<<str<<endl;


}
