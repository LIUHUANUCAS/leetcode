#include<iostream>
#include<vector>
#include <cstdlib>
#include<iterator>
#include<queue>
using namespace std;


/**
    doc
    Given a binary tree

        struct TreeLinkNode {
          TreeLinkNode *left;
          TreeLinkNode *right;
          TreeLinkNode *next;
        }
    Populate each next pointer to point to its next right node.
    If there is no next right node, the next pointer should be set to NULL.

    Initially, all next pointers are set to NULL.

    Note:

    You may only use constant extra space.
    You may assume that it is a perfect binary tree
    (ie, all leaves are at the same level, and every parent has two children).

    For example,
    Given the following perfect binary tree,
             1
           /  \
          2    3
         / \  / \
        4  5  6  7
    After calling your function, the tree should look like:
             1 -> NULL
           /  \
          2 -> 3 -> NULL
         / \  / \
        4->5->6->7 -> NULL


    116PopulatingNextRightPointersinEachNode.cpp
*/

/**
    Solutions:
       we can use two queue to store the first level node and the next level node.Meanwhile,we use
       two queue pointers,one of which is pointed to the first level queue,and the other to the next
       level queue,when first level queue is empty ,which may demenstrate that one level nodes haved
       been visited,so we will exchange them to perform another travesal the tree.
*/


 struct TreeLinkNode {
     int val;
     TreeLinkNode *left, *right, *next;
     TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };
 typedef TreeLinkNode TreeNode;

void printTree(TreeNode* root)
{
    if(root != NULL)
    {

    cout<<"->"<<root->val<<" ";
        printTree(root->left);
        printTree(root->right);
    }
}

TreeNode* insert(TreeNode* root, int x)
{
    TreeLinkNode* p = new TreeLinkNode(x);
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

    void connect(TreeLinkNode *root) {
        levelOrder(root);
    }


    void levelOrder(TreeLinkNode* root)
    {

        if(root == NULL)
            return ;
        queue<TreeLinkNode*> que;
        queue<TreeLinkNode*> que2;
        queue<TreeLinkNode*> * p = &que,*q = &que2;
        p->push(root);
        while(!p->empty())
        {
            TreeLinkNode* node = p->front();
            p->pop();
            if(node->left != NULL)
                q->push(node->left);
            if(node->right != NULL)
                q->push(node->right);
            while(!p->empty()){
                TreeLinkNode* next = p->front();
                p->pop();
                if(next->left != NULL)
                    q->push(next->left);
                if(next->right != NULL)
                    q->push(next->right);
                node->next = next;
                node = node->next;
            }
            node->next = NULL;
            if(p->empty())
            {
                queue<TreeLinkNode * > * tmp = p;
                p = q;
                q =tmp;
            }
        }
    }

};

int main()
{
    vector<int> vals = {10,7,6,5,8,9,15,12,13,17,16};
    TreeLinkNode* root = createTree(vals);
    Solution s;
    cout<<endl;
    vector<vector<int>> level;
    s.connect(root);
    for(auto&e : level)

    /**your code...*/
    destoryTree(root);
    return 0;

}
