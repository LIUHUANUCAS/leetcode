#include<iostream>
#include<vector>
#include <cstdlib>
#include<iterator>
using namespace std;


/**
    doc
    Given a binary tree, find its maximum depth.

    The maximum depth is the number of nodes along the longest path
    from the root node down to the farthest leaf node.

    Tags :Tree Depth-first Search


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
    int minDepth(TreeNode* root) {
        return depth(root);
    }

    int depth(TreeNode* root){
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right == NULL)
            return 1;

        int ldepth = depth(root->left);
        int rdepth = depth (root->right);
        if(root->left == NULL && root->right != NULL)
            return rdepth + 1;
        if(root->right == NULL && root->left != NULL)
            return ldepth + 1;

        return min(ldepth,rdepth) + 1;
    }
};

int main(){
    vector<int> vals = {4,2,1,3,6,5,7,8,9,10,11,12};
    TreeNode* root = createTree(vals);
    Solution s;
    int res = s.minDepth(root);
    cout<<res<<endl;
    return 0;

}
