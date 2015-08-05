#include<iostream>
#include<vector>
#include <cstdlib>
#include<iterator>
using namespace std;


/**
    doc
    Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

    For example, this binary tree is symmetric:

        1
       / \
      2   2
     / \ / \
    3  4 4  3
    But the following is not:
        1
       / \
      2   2
       \   \
       3    3
    Note:
    Bonus points if you could solve it both recursively and iteratively.

    101SymmetricTree.cpp
*/

/**
    Solutions:
        we can make a decision that the inorder traversal of root's left child from left to right is the same
        as the inorder traversal of root's right child from right to left.
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
             /**your solution...*/
        vector<int> left;
        vector<int> right;

        bool isSymmetric1(TreeNode* root) {
            if(root == NULL)
                return 1;
            inOrderLeftRight(root->left);
            inOrderLeftRight(root->right);
            size_t i = 0;
            if(left.size() != right.size())
                return 0;
            for(size_t i = 0;i<left.size() && i < right.size();++i)
                if(left[i] != right[i])
                    return 0;
            return 1;
        }

        bool isSymmetric(TreeNode* root) {
            if(root == NULL)
                return 1;
            return inorder(root->left,root->right);
        }

        bool inorder(TreeNode* left,TreeNode* right){
            if(left == NULL && right == NULL )
                return 1;
            if(left == NULL || right == NULL)
                return 0;
            bool flag1 = inorder(left->left,right->right);
            if(flag1 == 0)
                return 0;
            if(left->val != right ->val )
                return 0;
            bool flag2 = inorder(left->right,right->left);
            if(flag2 == 0)
                return 0;
            return 1;
        }

        void inOrderLeftRight(TreeNode* root){
            if(root == NULL)
                return ;
            inOrderLeftRight(root->left);
            left.push_back(root->val);
            inOrderLeftRight(root->right);
        }

        void inOrderRightLeft(TreeNode* root){
            if(root == NULL)
                return ;
            inOrderLeftRight(root->right);
            right.push_back(root->val);
            inOrderLeftRight(root->left);
        }

};

int main(){
    vector<int> vals = {4,2,1,3,5,8,7};
    TreeNode* root = createTree(vals);
    Solution s;
    /**your code...*/
    destoryTree(root);
    return 0;

}
