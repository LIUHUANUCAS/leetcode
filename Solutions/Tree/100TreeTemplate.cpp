#include<iostream>
#include<vector>
#include <cstdlib>
#include<iterator>
using namespace std;


/**
    doc


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

};

int main(){
    vector<int> vals = {4,2,1,3,5,8,7};
    TreeNode* root = createTree(vals);
    Solution s;
    /**your code...*/
    destoryTree(root);
    cout<<endl<<res<<endl;
    return 0;

}
