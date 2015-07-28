#include<iostream>
#include<vector>
#include <cstdlib>
#include<iterator>
using namespace std;


/**
    doc
    Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

    For example:
    Given the below binary tree and sum = 22,
                  5
                 / \
                4   8
               /   / \
              11  13  4
             /  \    / \
            7    2  5   1
    return
    [
       [5,4,11,2],
       [5,8,4,5]
    ]

    113Path SumII.cpp
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
    vector<vector<int> > res;
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        pathSum1(root,sum);
        return res;
    }
     bool pathSum1(TreeNode* root, int sum) {
        if(root == NULL)
            return 0;
        path.push_back(root->val);
//        cout<<"\npath"<<endl;
//        copy(path.begin(),path.end(),ostream_iterator<int>(cout," "));
//        cout<<endl;
        if(root->left == NULL && root->right == NULL && sum == root->val){
            res.push_back(path);
            path.pop_back();
            return 1;
        }

        pathSum1(root->left,sum-root->val);
        pathSum1(root->right,sum-root->val);
        path.pop_back();

        return 0;
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
    int sum = 15;
    vector<vector<int>> res = s.pathSum(root,sum);
    printMatrix(res);
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
