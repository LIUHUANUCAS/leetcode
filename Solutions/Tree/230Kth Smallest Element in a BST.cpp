#include<iostream>
#include<vector>
#include <cstdlib>
#include<iterator>
#include<algorithm>
using namespace std;


/**
    doc
    Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

    230Kth Smallest Element in a BST.cpp
*/
/**
    Solutions:
        in a BST,we can get the property that the inorder traversal the number will be a sorted array.
    so we can get the kth from the inorder traversal..
    Complexity:
        the Complexity will be the height of the BST ,for the kth number will be from the sorted array.
    that is to say,we will from the left most of the BST to traval to the kth number.
*/

 struct TreeNode {
      int val;
     TreeNode *left;
     TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void printTree(TreeNode* root){
    if(root != NULL){

        printTree(root->left);
        cout<<"->"<<root->val<<" ";
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
            int count = 0;
            int val=0;
            int kthSmallest(TreeNode* root, int k) {
                if(root == NULL)
                    return 0;
                bool res = inorderTraval(root,k);
                if(res == 0)
                    return 0;
                return val;
            }

            bool inorderTraval(TreeNode* root,int k){
                if(root == NULL)
                    return 0;
                bool left = inorderTraval(root->left,k);
                if(left)
                    return 1;
                count ++;
                if(count == k){
                    val = root->val;
                    return 1;
                }
                bool right = inorderTraval(root->right,k);
                if(right)
                    return 1;
                return 0;
            }
};


int main(){
    vector<int> vals = {8};
    sort(vals.begin(),vals.end());
    Solution s;

    TreeNode* root = createTree(vals);
    int k = 4;
    int res = s.kthSmallest(root,k);
    cout<<"res->"<<res<<endl;
//    printTree(root);
    destoryTree(root);
    return 0;

}

