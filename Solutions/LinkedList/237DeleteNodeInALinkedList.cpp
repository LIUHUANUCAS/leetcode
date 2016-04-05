#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string.h>
using namespace std;


/**
   doc
   Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

   Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function

   237DeleteNodeInALinkedList.cpp
*/
/**
    Solutions:
1st:
	we should know that the node should be freed when the node is deleted from the LinkedList.
	if the node is a static memory then we should do nothing when deleting the node,however,we should 
	call the function delete in c++ or free in c to free the memory that the node occupied.
	we can have the idea that we can only access the delete node but can not access its previous node
	so we should modify the node value that is
	tmpnode = node->next;
	node->val = tmpnode->val;
	node->next = tmpnode->next;
	delete tmpnode;// free(tmpnode);

2th:
	we can draw conclusion that node to be deleted is the same as node->next if we can modify the previous node points to the node->next,
	so we can copy the node->next to node,that is
	memcpy(node,node->next,sizeof(ListNode));
	but the memory that the node occupies could not be released.so the method is discouraged,should not be in real project.

    Complexity:
	O(1)
*/

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
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
ListNode* getNthNode(ListNode* head,int n){
    if(head == NULL)
        return head;
    if(n == 1)return head;
    int m=1;
    ListNode* p = head;
    while(m<n-1){
        m++;
        p = p->next;
    }
    return p;
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


class Solution {
    public:
		void deleteNode(ListNode* node){
			if(!node || !node->next)
				return ;
		//	memcpy(node,node->next,sizeof(ListNode));
			ListNode* tmp = node->next;
			node->val = tmp->val;
			node->next = tmp->next;
			delete tmp;//release the node
		}

};

int main(){
        int array[] = {1,2,3,4,5,6,7,8};
        int size = sizeof(array)/sizeof(int);
        ListNode* head = createNodeList(array,array+size-1);
        printList(head);
        Solution s;
        /*your code here..*/
		s.deleteNode(head->next->next);
        printList(head);
        freelistNode(head);
        return 0;
}
