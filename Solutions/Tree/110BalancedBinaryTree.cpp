#include<iostream>
#include<vector>
#include <cstdlib>
#include<iterator>
using namespace std;


/**
    doc
    Given a binary tree, determine if it is height-balanced.

    For this problem, a height-balanced binary tree is defined as a binary tree
    in which the depth of the two subtrees of every node never differ by more than 1.



*/

 struct TreeNode {
      int val;
     TreeNode *left;
     TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void printTree(TreeNode* root){
    if(root != NULL){
        cout<<"->"<<root->val<<" ";
        printTree(root->left);
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
class Solution {

public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return 1;
        int ldepth = depth(root->left);
        int rdepth = depth(root->right);
        if(abs(ldepth-rdepth) <= 1)
            return isBalanced(root->left) && isBalanced(root->right);
        else
            return 0;
    }

    int depth(TreeNode* root){
        if(root == NULL)
            return 0;
        int ldepth = depth(root->left);
        int rdepth = depth (root->right);
        return max(ldepth,rdepth) + 1;
    }
};

int main(){
    vector<int> vals = {4,2,1,3,6,5,7};
    TreeNode* root = createTree(vals);
    Solution s;
    bool res = s.isBalanced(root);
    cout<<res<<endl;
    return 0;

}
