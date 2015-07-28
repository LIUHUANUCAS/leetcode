#include<iostream>
#include<vector>
#include <cstdlib>
#include<iterator>
using namespace std;


/**
    doc
    Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

    An example is the root-to-leaf path 1->2->3 which represents the number 123.

    Find the total sum of all root-to-leaf numbers.

    For example,

        1
       / \
      2   3
    The root-to-leaf path 1->2 represents the number 12.
    The root-to-leaf path 1->3 represents the number 13.

    Return the sum = 12 + 13 = 25.

    129Sum Root to Leaf Numbers.cpp
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
    int sum=0;
    int sumNumbers(TreeNode* root) {
        pathToLeaf(root);
        return sum;
    }
    int vectorToNumber(vector<int> &nums ){
        int sum = 0;
        for(auto& e : nums){
            sum*=10;
            sum+= e;
        }
        return sum;
    }

     bool pathToLeaf(TreeNode* root) {
        if(root == NULL)
            return 0;
        path.push_back(root->val);
        if(root->left == NULL && root->right == NULL){
                int tmpsum = vectorToNumber(path);
                sum+= tmpsum;
            path.pop_back();
            return 1;
        }
        pathToLeaf(root->left);
        pathToLeaf(root->right);
        path.pop_back();
        return 0;
    }
};


int main(){
    vector<int> vals = {4,2,1,3,6,5,7};

    TreeNode* root = createTree(vals);
    printTree(root);
    Solution s;
//    int sum = 15;
//    vector<vector<int>> res = s.pathSum(root,sum);
//    printMatrix(res);
//    destoryTree(root);
//    cout<<endl<<res<<endl;
    int sum = s.sumNumbers(root);
    cout<<endl<<sum<<endl;
    return 0;

}

