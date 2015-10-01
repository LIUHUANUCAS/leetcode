#include<iostream>
#include<vector>
#include <cstdlib>
#include<iterator>
#include<algorithm>
using namespace std;


/**
    doc
    Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

    108Convert Sorted Array to Binary Search Tree.cpp
*/

 struct TreeNode {
      int val;
     TreeNode *left;
     TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void printTree(TreeNode* root){
    if(root != NULL){

        printTree(root->left);
        cout<<"->"<<root->val<<" ";
        printTree(root->right);
    }
}

TreeNode* insert(TreeNode* root, int x)
{
    TreeNode* p = new TreeNode(x);
    if(root == NULL){
        root = p;
    }
    else if(x < root->val){
        root->left = insert(root->left, x);
    }
    else{
        root->right = insert(root->right, x);
    }
    return root;
}

TreeNode* createTree(vector<int>& nums){
      TreeNode* root = 0;
      for(auto& e:nums)
        root = insert(root,e);
      printTree(root);
      cout<<endl;
      return root;
}

void destoryTree(TreeNode* root){
    if(root == NULL )
        return ;
    destoryTree(root->left);
    destoryTree(root->right);
    delete root;
}

void printMatrix(vector<vector<int> > res){
     int size = res.size();
     for(int i=0;i<size;++i)
        cout<<"==";
     cout<<endl;
     for(auto& line:res){
            copy(line.begin(),line.end(),ostream_iterator<int>(cout," "));
            cout<<endl;
        }
}

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root=0;
        int begin = 0;
        int end = nums.size()-1;
        root = BST(nums,begin,end);
        return root;
    }

    TreeNode* BST(vector<int>& nums,int begin,int end){
            if(begin > end)
                return 0;
            int mid = (begin+end)>>1;
            TreeNode* tmp=new TreeNode(nums[mid]);
//            cout<<" eee"<<endl;
            if(begin == end){
                return tmp;
            }

            if(begin < mid)
                tmp->left = BST(nums,begin,mid-1);
            if(end > mid)
                tmp->right = BST(nums,mid+1,end);
            return tmp;
    }
};


int main(){
    vector<int> vals = {4,2,1,3,6,5,7};

    sort(vals.begin(),vals.end());
    for(auto& e:vals)
        cout<<e<<" ";
    cout<<endl;
    Solution s;
    TreeNode* root = s.sortedArrayToBST(vals);
    printTree(root);
    destoryTree(root);
//    cout<<endl<<res<<endl;
    return 0;

}
//
//void insertTreeNode(int val){
//     TreeNode* node = new TreeNode(val);
//     TreeNode* r=;
//     while(r->left && r->right){
//        if(r->val == val)
//                return ;
//        if(val < r->val)
//            r = r->left;
//        else
//            r = r->right;
//     }
//    if(r->left == NULL && val< r->val)
//        r->left = node;
//
//
//    if(r->right == NULL&&val > r->val)
//        r->right = node;
//    printTree(root);
//}
