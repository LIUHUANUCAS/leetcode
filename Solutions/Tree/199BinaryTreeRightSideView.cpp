#include<iostream>
#include<vector>
#include <cstdlib>
#include<iterator>
#include<queue>
using namespace std;


/**
    doc
    Given a binary tree, imagine yourself standing on the right side of it,
    return the values of the nodes you can see ordered from top to bottom.

    For example:
    Given the following binary tree,
       1            <---
     /   \
    2     3         <---
     \     \
      5     4       <---
    You should return [1, 3, 4].


    199BinaryTreeRightSideView.cpp
*/

/**
    Solutions:
       we can use two queue to store the first level node and the next level node.Meanwhile,we use
       two queue pointers,one of which is pointed to the first level queue,and the other to the next
       level queue,when first level queue is empty ,which may demonstrate that one level nodes have
       been visited,besides,we will have a temporary variable to store the right most element on that
       level ,last we will exchange them to perform another travesal the tree.
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

    cout<<"->"<<root->val<<" ";
        printTree(root->left);
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

    vector<int> rightSideView(TreeNode* root) {
        return levelOrder(root);
    }


    vector<int> levelOrder(TreeNode* root)
    {
        vector<int> rightmost;
        if(root == NULL)
            return rightmost;
        queue<TreeNode*> que;
        queue<TreeNode*> que2;
        queue<TreeNode*> * p = &que,*q = &que2;
        p->push(root);

        while(!p->empty())
        {
            TreeNode* node = p->front();
            p->pop();
            if(node->left != NULL)
                q->push(node->left);
            if(node->right != NULL)
                q->push(node->right);
            while(!p->empty()){
                TreeNode* next = p->front();
                p->pop();
                if(next->left != NULL)
                    q->push(next->left);
                if(next->right != NULL)
                    q->push(next->right);
                node = next;
            }
            rightmost.push_back(node->val);
            if(p->empty())
            {
                queue<TreeNode * > * tmp = p;
                p = q;
                q =tmp;
            }
        }
        return rightmost;
    }

};

int main()
{
    vector<int> vals = {10,7,6,5,8,9};//,16,13
    TreeNode* root = createTree(vals);
    Solution s;
    cout<<endl;
    vector<int> level;
    level = s.rightSideView(root);
    copy(level.begin(),level.end(),ostream_iterator<int>(cout," "));

    /**your code...*/
    destoryTree(root);
    return 0;

}
