#include<iostream>
#include<vector>
#include <cstdlib>
#include<iterator>
using namespace std;


/**
    doc
        Given a binary tree, flatten it to a linked list in-place.

        For example,
        Given

                 1
                / \
               2   5
              / \   \
             3   4   6
        The flattened tree should look like:
           1
            \
             2
              \
               3
                \
                 4
                  \
                   5
                    \
                     6
        click to show hints.

        Hints:
        If you notice carefully in the flattened tree,
        each node's right child points to the next node of a pre-order traversal.

    114FlattenBinaryTreetoLinkedList.cpp
*/
/**
    Solutions:
     we can travasal the tree recursive to solve the problem.we should linear the left if the root's left childe
     is not null,then we will linear the root's right child, and the root's left will be the linear left,the right
     most of the linear left should hava a right child,which is the linear right.
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
void printTreeRight(TreeNode* root){
    while(root){
        cout<<"->"<<root->val;
        root = root->right;
    }
    cout<<endl;
}

class Solution {
public:
    TreeNode* getRightMost(TreeNode* root){
        if(root == NULL)
            return root;
        TreeNode* p = root;
        while(p->right){
            p = p->right;
        }
        return p;
    }

    void flatten(TreeNode* root) {
        preOrderTravasal(root);
    }

    TreeNode* preOrderTravasal(TreeNode* root){
        if(root == NULL)
            return NULL;
        if(root->left == NULL && root->right == NULL){
            return root;
        }
            TreeNode* left = preOrderTravasal(root->left);
            root->left = NULL;

            if(left != NULL){
                TreeNode* tmpleft = getRightMost(left);
                if(left != NULL){
                    TreeNode* rootright = root->right;
                    tmpleft->right = preOrderTravasal(root->right);
                    tmpleft->left = 0;
                    root->right = left;
                    return root;
                }
            }else{
                root->right = preOrderTravasal(root->right);
                return root;
            }
    }
};



int main(){
    vector<int> vals = {10,7,6,8,15,12,13,11};

    TreeNode* root = createTree(vals);
//    printTree(root);
    Solution s;
    s.preOrderTravasal(root);
//    TreeNode* p = s.getRightMost(root);
//    if(p)
//    cout<<p->val<<endl;
    printTreeRight(root);
    destoryTree(root);
    return 0;

}

