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
		   int canCompleteCircuit(vector<int>& gas,vector<int> & cost){
			   int n = gas.size();
			   int total=0;
			   for(int turn=0;turn<n;++turn){
					total = gas[turn];
					int costi=turn;
					int next= (turn+1) % n;
					while(next != turn){
						total-=cost[costi];
						if(total<0)
							break;
						next = (next+1) % n;
						costi=(++costi) % n;
					}
					if(next == turn)
						return turn;
			   }
			   return -1; 
		   }

};

int main(){
        Solution s;
		vector<int> gas= {4};
		vector<int> cost = {5};
		cout<<s.canCompleteCircuit(gas,cost)<<endl;
        cout<<"Dynamic programming"<<endl;
        return 0;

}
