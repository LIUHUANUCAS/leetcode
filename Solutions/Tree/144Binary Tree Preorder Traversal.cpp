#include<iostream>
#include<vector>
#include <cstdlib>
#include<iterator>
using namespace std;


/**
    doc
    Given a binary tree, return the preorder traversal of its nodes' values.

    For example:
    Given binary tree {1,#,2,3},
       1
        \
         2
        /
       3
    return [1,2,3].

    Note: Recursive solution is trivial, could you do it iteratively?

    144Binary Tree Preorder Traversal.cpp
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
    vector<int> path;
    vector<int> inorderTraversal(TreeNode* root) {
        preorder(root);
        return path;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        return inorderTraversal(root);
    }
    void preorder(TreeNode* root){
        if(root == NULL)
            return ;
        path.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
};


int main(){
    vector<int> vals = {4,2,1,3,6,5,7};
//    vector<int> vals = {0,1,1};
//    TreeNode*root = new TreeNode(0);
//    root->left = new TreeNode(1);
//    root->right = new TreeNode(1);
    TreeNode* root = createTree(vals);
    printTree(root);
    Solution s;
    vector<int> res = s.preorderTraversal(root);
    copy(res.begin(),res.end(),ostream_iterator<int>(cout," "));
    cout<<endl;
//    printMatrix(res);
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
