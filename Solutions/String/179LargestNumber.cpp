#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
/**
    doc
    Given a list of non negative integers, arrange them such that they form the largest number.

    For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
    
    Note: The result may be very large, so you need to return a string instead of an integer.
    
     
    
    
    name.cpp
*/
/**
    Solutions:
    sort array,
    compare string a with b.we can compare a+b with b+a  
    
*/
int cmp(string s1,string s2){
   return s1+s2 > s2+s1;
}
class myfunction{
     bool operator()(string s1,string s2)
    {    
        int size1= s1.size();
        int size2= s2.size();
        if(s1 == s2){
            cout<<"s1==s2"<<endl;
            return 0;
        }
        int i=0;
        int j=0;
        while(i<size1 && j < size2){
            if(s1[i] < s2[j]){
                return 0;
            }else if(s1[i] > s2[j]){
                return 1;
            }else{
                j++;
                i++;
            }
        }
        
        if(i == size1){
            return s2[j] > s1[0]? 0:1;
        }
        
        if(j == size2){
            return s1[i] > s2[0]?1:0;
        }
        cout<<"end.."<<endl;
        return 0;
    }
};
// copy(svec.begin(),svec.end(),ostream_iterator<string>(cout," "));
// cout<<endl;
        
class Solution {
    public:
    string largestNumber(vector<int>& nums) {
        vector<string> svec;
        int size = nums.size();
        if(size == 0 )
            return "0";
        for(auto& e : nums){
            char ch[32];
            sprintf(ch,"%d",e);
            svec.push_back(string(ch));
        }   
        sort(svec.begin(),svec.end(),cmp);
        // copy(svec.begin(),svec.end(),ostream_iterator<string>(cout,"\n"));
        // cout<<endl;
        string res;
        for(auto&e:svec){
            // if(e[0] != '0')
                res+=e;
        }
        size = res.size();
        if(size == 0)
            return "0";
        int i=0;
        while(i<size){
            if(res[i] != '0')
                break;
            i++;
        }
        if(i == 0)
            return res;
        else if (i == size)
            return "0";
        else {
            return string(res.begin()+1,res.end());
        }
    }
    
    bool operator()(string s1,string s2)
    {   
        
        
        
        
         
        int size1= s1.size();
        int size2= s2.size();
        if(s1 == s2)
            return 0;
        int i=0,j=0;
        while(i<size1 && j < size2){
            if(s1[i] < s2[j]){
                return 0;
            }else if(s1[i] > s2[j]){
                return 1;
            }else{
                j++;
                i++;
            }
        }
        
        if(i == size1){
            return (*this)(s1,string(s2.begin()+j,s2.end()));
            while(j<size2 && s2[j] == s1[0])
                j++;
            if(j == size2 )
                return 0;
            return s2[j] > s1[0]? 0:1;
            
        }
        
        if(j == size2){
            return (*this)(string(s1.begin()+i,s1.end()),s2);
            while(i<size1 && s1[i] == s2[0])
                i++;
            
            if(i == size1 )
                return 0;
            return s1[i] > s2[0]?1:0;
        }
        return 0;
    }
};

int main(){

    vector<int> array = {
        // 3, 30, 34, 5, 9,341,343,345
        // 22,22221,123,213,231
        // 12,121
       4704,6306,9385,7536,3462,4798,5422,5529,8070,6241,9094,7846,663,6221,216,6758,8353,3650,3836,8183,3516,5909,6744,1548,5712,2281,3664,7100,6698,7321,4980,8937,3163,5784,3298,9890,1090,7605,1380,1147,1495,3699,9448,5208,9456,3846,3567,6856,2000,3575,7205,2697,5972,7471,1763,1143,1417,6038,2313,6554,9026,8107,9827,7982,9685,3905,8939,1048,282,7423,6327,2970,4453,5460,3399,9533,914,3932,192,3084,6806,273,4283,2060,5682,2,2362,4812,7032,810,2465,6511,213,2362,3021,2745,3636,6265,1518,8398
        };
    Solution s;
    string str = s.largestNumber(array);
    cout<<str<<endl;
    string resstr = "98909827968595339456944893859149094902689398937839883538183810810780707982784676057536747174237321720571007032685668066758674466986636554651163276306626562416221603859725909578457125682552954605422520849804812479847044453428339323905384638363699366436503636357535673516346233993298316330843021297028227452732697246523622362231322812216213206020001921763154815181495141713801147114310901048";
    
    cout<<resstr<<endl;
    cout<<(resstr==str)<<endl;
    return 0;
    
    
    string s1,s2;
    while(cin>>s1>>s2){
        cout<<s1<<"----"<<s2<<endl;
        int res = cmp(s1,s2);
        if(res == -1){
            cout<<"s1 < s2"<<endl;
        }else if (res == 1){
            cout<<"s1 > s2"<<endl;
        }else{
            cout <<"s1 == s2"<<endl;
        }
    }
    cout<<"hello c++11"<<endl;
    return 0;
}
