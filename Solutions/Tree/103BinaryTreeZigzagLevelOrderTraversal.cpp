#include<iostream>
#include<vector>
#include <cstdlib>
#include<iterator>
#include<queue>
#include<stack>
using namespace std;


/**
    doc
    Given a binary tree, return the zigzag level order traversal of its nodes' values.
    (ie, from left to right, then right to left for the next level and alternate between).

    For example:
    Given binary tree {3,9,20,#,#,15,7},
        3
       / \
      9  20
        /  \
       15   7
    return its zigzag level order traversal as:
    [
      [3],
      [20,9],
      [15,7]
    ]


    103BinaryTreeZigzagLevelOrderTraversal.cpp
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

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        return levelOrder(root);
    }

    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> level;
        if(root == NULL)
            return level;
        queue<TreeNode*> que;
        queue<TreeNode*> que2;
        queue<TreeNode*> * p = &que,*q = &que2;
        stack<TreeNode*> sta;
        p->push(root);
        while(!p->empty())
        {
                vector<int> left2right;
                while(!p->empty()){
                    TreeNode* node1 = p->front();
                    left2right.push_back(node1->val);
                    if(node1->left != NULL){
                        sta.push(node1->left);
                        q->push(node1->left);
                    }
                    if(node1->right != NULL){
                        sta.push(node1->right);
                        q->push(node1->right);
                    }
                    p->pop();
                }
                if(!left2right.empty())
                    level.push_back(left2right);
                vector<int> stavec;
                while(!sta.empty()){
                    TreeNode* tmp = sta.top();
                    sta.pop();
                    stavec.push_back(tmp->val);
                }
                if(!stavec.empty())
                    level.push_back(stavec);
                while(!q->empty()){
                    TreeNode* t = q->front();
                    q->pop();
                    if(t->left != NULL)
                        p->push(t->left);
                    if(t->right != NULL)
                        p->push(t->right);
                }
        }
        return level;
    }

};

int main()
{
    vector<int> vals = {10,7,6,8,15,12,13};
    TreeNode* root = createTree(vals);
    Solution s;
//    printTree(root);
    cout<<endl;
    vector<vector<int>> level;
    level = s.levelOrder(root);
    for(auto&e : level)
    {
        cout<<"========================b"<<endl;

        copy(e.begin(),e.end(),ostream_iterator<int>(cout," "));
        cout<<endl;
        cout<<"========================e"<<endl;

    }
    /**your code...*/
    destoryTree(root);
//    cout<<endl<<res<<endl;
    return 0;

}
