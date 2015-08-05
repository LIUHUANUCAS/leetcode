#include<iostream>
#include<vector>
#include <cstdlib>
#include<iterator>
#include<queue>
using namespace std;


/**
    doc
    Given a binary tree, return the level order traversal of its nodes' values.
    (ie, from left to right, level by level).

    For example:
    Given binary tree {3,9,20,#,#,15,7},

        3
       / \
      9  20
        /  \
       15   7

    return its level order traversal as:

    [
      [3],
      [9,20],
      [15,7]
    ]


    102BinaryTreeLevelOrderTraversal.cpp
*/

/**
    Solutions:
       we can use two queue to store the first level node and the next level node.Meanwhile,we use
       two queue pointers,one of which is pointed to the first level queue,and the other to the next
       level queue,when first level queue is empty ,which may demenstrate that one level nodes haved
       been visited,so we will exchange them to perform another travesal the tree.
*/


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void printTree(TreeNode* root)
{
    if(root != NULL)
    {

        printTree(root->left);
        \
        cout<<"->"<<root->val<<" ";
        printTree(root->right);
    }
}

TreeNode* insert(TreeNode* root, int x)
{
    TreeNode* p = new TreeNode(x);
    if(root == NULL)
    {
        root = p;
    }
    else if(x < root->val)
    {
        root->left = insert(root->left, x);
    }
    else
    {
        root->right = insert(root->right, x);
    }
    return root;
}

TreeNode* createTree(vector<int>& nums)
{
    TreeNode* root = 0;
    for(auto& e:nums)
        root = insert(root,e);
    printTree(root);
    cout<<endl;
    return root;
}

void destoryTree(TreeNode* root)
{
    if(root == NULL )
        return ;
    destoryTree(root->left);
    destoryTree(root->right);
    delete root;
}

class Solution
{
public:
    /**your solution...*/
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> level;
        if(root == NULL)
            return level;
        queue<TreeNode*> que;
        queue<TreeNode*> que2;
        queue<TreeNode*> * p = &que,*q = &que2;


        p->push(root);
        vector<int> vtmp;
        while(!p->empty())
        {
            TreeNode* node = p->front();
            p->pop();
            vtmp.push_back(node->val);
            if(node->left != NULL)
                q->push(node->left);
            if(node->right != NULL)
                q->push(node->right);
            if(p->empty())
            {
                queue<TreeNode * > * tmp = p;
                p = q;
                q =tmp;
                level.push_back(vtmp);
                vtmp.clear();
            }
        }
        return level;
    }

};

int main()
{
    vector<int> vals = {4,2,1,3,6,5,7,8,9};
    TreeNode* root = createTree(vals);
    Solution s;
    printTree(root);
    cout<<endl;
    vector<vector<int>> level;
    level = s.levelOrder(root);
    for(auto&e : level)
    {
        copy(e.begin(),e.end(),ostream_iterator<int>(cout," "));
        cout<<endl;
    }
    /**your code...*/
    destoryTree(root);
//    cout<<endl<<res<<endl;
    return 0;

}
