#include<iostream>
#include<vector>
#include <cstdlib>
#include<iterator>
#include<algorithm>
using namespace std;


/**
    doc
    Given a binary tree, determine if it is a valid binary search tree (BST).

    Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.
    confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

    Hide Tags Tree Depth-first Search
    Show Similar Problems


    98Validate Binary Search Tree.cpp
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
void inorderTree(TreeNode* root){
    if(root != NULL){
        inorderTree(root->left);
        cout<<"->"<<root->val<<" ";
        inorderTree(root->right);
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
    vector<int> res;
    bool isValidBST(TreeNode* root) {
        if(root == NULL)
            return 1;
        InorderAscend(root);
        return validBST(root->left) && validBST(root->right) && isAscend();
    }
    void InorderAscend(TreeNode* root){
        if(root == NULL)
            return ;
        InorderAscend(root->left);
        res.push_back(root->val);
        InorderAscend(root->right);
    }

    bool isAscend(){
        if(res.empty() || res.size() == 1)
            return 1;
        for(int i=1;i<res.size();++i)
            if(res[i] <= res[i-1])
                return 0;
        return 1;
    }

    bool validBST(TreeNode* root){
        if(root == NULL)
            return 1;
//        cout<<"ee"<<endl;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        int lflag = validBST(left);
        if(!lflag)
            return 0;
        int rflag = validBST(right);
        if(!rflag)
            return 0;

        return  lflag && rflag;

    }
};


int main(){
    vector<int> vals = {4,2,1,3,6,5,7};
    Solution s;
    TreeNode* root = createTree(vals);
    printTree(root);
    cout<<endl;

    inorderTree(root);
    cout<<endl;
    bool res =  s.isValidBST(root);
    cout<<"res:"<<res<<endl;

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
