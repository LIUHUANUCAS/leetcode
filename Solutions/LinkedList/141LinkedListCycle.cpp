#include<iostream>
#include<ctime>
#include <cstdlib>
using namespace std;


/**
    doc

    Given a linked list, determine if it has a cycle in it.

    Follow up:
    Can you solve it without using extra space?

    Hide Tags Linked List Two Pointers


    141Linked List Cycle.cpp
*/

/**
    Solutions:
    if there exist a cycle then,we can get two pointers which may be in the cycle at the same time.
    we can make a dession that one pointer can move one step at a time,while the other pointer can
    move two or more steps forward, that is to say the two pointers has diffient velocity ,the result of
    which will be that one pointer with higher velocity will come up with the slow pointer because both of
    them are on a cycle.
    so we can solve it!


    Complexity:
    with the traversal of all node of the Linkedlist and the two pointers are on cycle.
    so the complexity will be made up of two component that is the size of Linkedlist an the size of the Cycle.
    finally the Complexity will be O(n) where n is the size of Linkedlist.

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

ListNode* getTail(ListNode* head){
    if(head == NULL)
        return head;

    ListNode* h = new ListNode(0);
    h ->next = head;
    ListNode* p = h;

    while(p->next){
        p = p ->next;
    }
    delete h;
    return p;
}


class Solution {
    public:
        bool hasCycle(ListNode *head) {
            if(head == NULL)
                return 0;
            if(head->next == head)
                return 1;
            ListNode* p = head,*q= head;
            q = q -> next;
            if(q == NULL)
                return 0;
            q = q ->next;

            while(p && q){
                if( p == q)
                    return 1;
                p = p->next;
                q =q ->next;
                if(!q)
                    return 0;
                q = q->next;
            }
            return  0;
        }
};

int main(){
        int array[] = {1,2,3,4,5,6,7,8};
        int size = sizeof(array)/sizeof(int);
        ListNode* head = createNodeList(array,array+size-1);
        printList(head);
        /*your code here..*/
        ListNode* tail = getTail(head);
        ListNode* mid = getNthNode(head,6);
        tail->next = mid;
//        printList(mid);
//        printList(tail);
        Solution s;
        bool res = s.hasCycle(head);
        cout<<res<<endl;
        tail->next = 0;
        printList(head);
        freelistNode(head);
        return 0;
}
