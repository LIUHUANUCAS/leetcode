#include<iostream>
#include<vector>
#include <cstdlib>
#include<iterator>
using namespace std;


/**
    doc
    Given a binary tree and a sum, determine if the tree has a root-to-leaf path
    such that adding up all the values along the path equals the given sum.

    For example:
    Given the below binary tree and sum = 22,
                  5
                 / \
                4   8
               /   / \
              11  13  4
             /  \      \
            7    2      1
    return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

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
    int total = 0;
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return 0;
//        total+= root->val;
//        cout<<"total1:"<<total<<endl;
        if(root->left == NULL && root->right == NULL && sum == root->val)
            return 1;
        bool l = hasPathSum(root->left,sum-root->val);
        if(l)
            return 1;
//        total -= root->val;
//        cout<<"total2:"<<total<<endl;
        bool r = hasPathSum(root->right,sum-root->val);
        if(r)
            return 1;

        return 0;

    }
};

int main(){
    vector<int> vals = {4,2,1,3,5,8,7};
    TreeNode* root = createTree(vals);
    Solution s;
    int sum = 15+9;
    bool res = s.hasPathSum(root,sum);
    destoryTree(root);
    cout<<endl<<res<<endl;
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
