#include<iostream>
#include<ctime>
#include <cstdlib>
using namespace std;


/**
    doc
    Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

    Hide Tags Depth-first Search Linked List



    109Convert Sorted List to Binary Search Tree.cpp
*/
/**
    Solutions:
        create BST tree recursive,we can make full use of the size of the Linkedlist.
        the middle of the Linkedlist will be the root of the BST,so the left part will
        be created recursively as the root's left child,Likeyly the right part of the Linkedlist
        will be the right child.
        as last we return the tree of root.
        the method can  reference for the Convert Sorted Array to Binary Search Tree,108th

    Complexity:
    the Complexity will be O(n),where n is the size of the Linkedlist,for we travesal all node of the Linkedlist.
*/

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


 void printList(ListNode* head){
    cout<<endl<<"-------------begin-----------------"<<endl;
    if(head == NULL){
        cout<<"empty...."<<endl;
        cout<<endl<<"-------------over------------------"<<endl;
        return ;
    }
    ListNode* rh = head;
    while(rh!=NULL){
        cout<<rh->val<<" ";
        rh = rh->next;
    }
    cout<<endl<<"-------------over------------------"<<endl;
}


 ListNode* reverseList(ListNode* head,int Nth) {
    if(head == NULL)
        return NULL;
    struct ListNode *p=head,*q=head,*rh=head;
    int count = 1;
    while(p&&p->next&&count<Nth){
        count ++;
        q = p->next;
        p->next = q->next;
        q->next = rh;
        rh = q;
    }
    return rh;
}
ListNode* createNodeList(int* begin,int *end){
    ListNode* head = new ListNode(0);
    ListNode* p = head;
    while(begin <= end){
        ListNode* tmp = new ListNode(*begin);
        tmp->next = 0;
        p->next = tmp;
        p = p->next;
        begin ++;
    }
    p = head;
    head = head->next;
    delete p;
    return head;
}
void freelistNode(ListNode*head){
    while(head){
        ListNode* p = head->next;
        delete head;
        head = p;
    }
}

void printTree(TreeNode* root){
    if(root == NULL)
        return ;
    printTree(root->left);
    cout<<root->val<<" ";
    printTree(root->right);
    return ;
}



class Solution {
    public:
            TreeNode* sortedListToBST(ListNode* head) {
                    if(head == NULL)
                        return NULL;
                    if(head->next == NULL){
                        TreeNode* root = new TreeNode(0);
                        root->val = head->val;
                        root->left = 0;
                        root->right =0;
                    }

                    int size = listSize(head);
                    return createBST(head,size);
            }

            TreeNode* createBST(ListNode* head,int size){
                if(size == 0)
                    return 0;
                TreeNode* root = new TreeNode(0);
                if(size == 1){
                        root->val = head->val;
                        root->left = 0;
                        root->right =0;
                        return root;
                }

                int mid = size /2;
                int left = mid,right = mid;

                if(size%2 == 1){
                    mid++;
                }else{
                    left --;
                }

                ListNode* midp = getNthNode(head,mid);

                root->val = midp->val;
                root->left = createBST(head,left);
                root->right = createBST(midp->next,right);
                return root;
            }

            ListNode* getNthNode(ListNode* head,int n){
                if(n <= 0)
                    return 0;
                if(head == NULL)
                    return head;
                if(n == 1)
                    return head;
                int m=1;
                ListNode* p = head;
                while(p&&m<n){
                    m++;
                    p = p->next;
                }
                return p;
            }

            int listSize(ListNode* head){
                if(head == NULL){
                    return 0;
                }
                int n=0;
                ListNode* p = head;
                while(p->next){
                    n++;
                    p = p->next;
                }
                return n+1;
            }

};

int main(){
        int array[] = {1,2,3,3,4,5,6};
        int size = sizeof(array)/sizeof(int);
        ListNode* head = createNodeList(array,array+size-1);
        printList(head);
        Solution s;
//        /*your code here..*/
//        head = s.deleteDuplicates(head);
//        int n=0;
//        ListNode* p = s.getNthNode(head,n);
        TreeNode* root = s.sortedListToBST(head);
        cout<<"print tree"<<endl;
        printTree(root);
        cout<<"tree over..."<<endl;
        printList(head);
        freelistNode(head);
        return 0;
}
