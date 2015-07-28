#include<iostream>
#include<vector>
#include <cstdlib>
#include<iterator>
using namespace std;


/**
    doc

    Given two binary trees, write a function to check if they are equal or not.

    Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

    SameTree.cpp
*/

/**
 * Definition for a binary tree node.
 */
 struct TreeNode {
      int val;
     TreeNode *left;
     TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

Treenode* createTree(vector<int>& nums){
        TreeNode* root = new TreeNode(0);

        return root;
}

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
            return true;
        if(q == NULL || p == NULL)
            return false;
        return q->val== p->val && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};

int main(){
        Solution s;

}
