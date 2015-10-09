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
	Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
	n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, 
	which together with x-axis forms a container, such that the container contains the most water.

	Note: You may not slant the container.


    11ContainerWithMostWater.cpp
*/
/**
	Solutions:
	we should understand that the quesiont is to find two lines from the n vertical lines and with the x-axis to forms a containter
	,whose area is min(height[i],height[j]) * abs(j-i).finally find the max area from the comparation with before area.
	we should pay attention to the terminator condition about the loop.
	if height[begin] < height[end]
	then 
		begin ++ to find a higher vertical line with the height[end] to form a container that has larger area.
	else
		have the same notation with the if condition.
	
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

void printmatrix(vector<vector<int>> res ){
    
    for(auto& line : res){
        copy(line.begin(),line.end(),ostream_iterator<int>(cout," "));
        cout<<endl;
    }
}
class Solution {

       public:

		int maxArea(vector<int>& height) {
			int begin =0;
			int size = height.size();
			if(size <= 1)
				return 0;
			int end = size-1;
			int area = 0;
			while(begin < end){
				int smallheight = min(height[begin] , height[end]);
				area = max(smallheight*(end - begin),area);
				if(height[begin] < height[end])
					begin ++;
				else
					end --;
			}
			
			return area;

		}
};

int main(){
        Solution s;
        vector<int> array ={1,2,3,4,5};
        copy(array.begin(),array.end(),ostream_iterator<int>(cout," "));
		cout<<endl;
        int area = s.maxArea(array);
		cout<<area<<endl;
        return 0;

}
