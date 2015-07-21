#include<iostream>
using namespace std;
/**
    Reverse a singly linked list.
    click to show more hints.
    Hint:
    A linked list can be reversed either iteratively or recursively. Could you implement both?
*/
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* reverseList(ListNode* head) {
    if(head == NULL)
        return NULL;
    struct ListNode *p=head,*q=head,*rh=head;
    while(p&&p->next){
        q = p->next;
        p->next = q->next;
        q->next = rh;
        rh = q;
    }
    return rh;
}

int main(){
    const int SIZE=1000;
    struct ListNode *n[SIZE];

    for(int i=0;i<SIZE;++i){
        n[i] =  new ListNode(i);
    }
    for(int i=0;i<SIZE;++i){
        if(i<SIZE-1)
            n[i]->next = n[i+1];
        else
            n[i]->next = NULL;
    }

    struct ListNode *p=n[0];
    struct ListNode *rh = reverseList(p);
        while(rh!=NULL){
        cout<<rh->val<<endl;
        rh = rh->next;
    }
    for(int i=0;i<SIZE;++i)
        delete n[i];

}
