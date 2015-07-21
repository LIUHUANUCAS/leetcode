#include<iostream>

/**
    Given a sorted linked list, delete all duplicates such that each element appear only once.

    For example,
    Given 1->1->2, return 1->2.
    Given 1->1->2->3->3, return 1->2->3.

*/

using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 void printList(ListNode* head){
    cout<<endl<<"-------------begin-----------------"<<endl;
    ListNode* rh = head;
    while(rh!=NULL){
        cout<<rh->val<<" ";
        rh = rh->next;
    }
    cout<<endl<<"-------------over------------------"<<endl;
}

ListNode* deleteDuplicates(ListNode* head) {
    if(head == NULL)
        return NULL;
    ListNode* p = head;
    ListNode* q = head->next;

    while(q){
        int a = p->val;
        int b = q->val;
        if(a == b)
            q = q->next;
        else
        {
            p->next = q;
            p = p->next;
//            p = q;
            q= q->next;
        }
    }
    p->next = 0;
//    printList(p);
    return head;
}
int main(){
    const int SIZE=10;
    struct ListNode *n[SIZE];


    for(int i=0;i<SIZE;++i){

            n[i] =  new ListNode(3);

    }
    n[SIZE-1]->val = 100;
    for(int i=0;i<SIZE;++i){
        if(i<SIZE-1)
            n[i]->next = n[i+1];
        else
            n[i]->next = NULL;
    }



    struct ListNode *p=n[0];
    printList(p);
    p = deleteDuplicates(p);
    printList(p);
    for(int i=0;i<SIZE;++i)
        delete n[i];

}
