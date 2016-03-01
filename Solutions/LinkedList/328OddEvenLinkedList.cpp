#include<iostream>
#include<ctime>
#include <cstdlib>
using namespace std;


/**
   doc
	Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

	You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

    Example:
    Given 1->2->3->4->5->NULL,
    return 1->3->5->2->4->NULL.
    
    Note:
    The relative order inside both the even and odd groups should remain as it was in the input. 
    The first node is considered odd, the second node even and so on ...
    
    Credits:
    Special thanks to @DjangoUnchained for adding this problem and creating all test cases.
    
    Subscribe to see which companies asked this question

   328OddEvenLinkedList.cpp
*/
/**
    Solutions:

    Complexity:
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
        public :
        ListNode* oddEvenList(ListNode* head) {
            
            if(head == NULL)
                return NULL;
            ListNode* phead1 = new ListNode(1);
            ListNode* phead2 = head;
            ListNode* ph1 = phead1,*ph2 = phead2,*p=head->next;
            int n=1;
            while(p){
                if(n % 2 == 1){
                    ph1->next = p;
                    ph1 = p;
                }
                else{
                    ph2->next = p;
                    ph2 = p;
                }
                p=p->next;
                n++;
            }
            ph1->next=NULL;
            ph2->next = phead1->next; 
            delete phead1;
            head = phead2;
            return head;
        }


};

int main(){
        // int array[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
        int array[] = {1,2,3};
        int size = sizeof(array)/sizeof(int);
        ListNode* head = createNodeList(array,array+size-1);
        printList(head);
        Solution s;
        /*your code here..*/
        head = s.oddEvenList(head);

        printList(head);
        freelistNode(head);
        return 0;
}
