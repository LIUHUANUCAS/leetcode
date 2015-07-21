#include<iostream>
using namespace std;
/**
    Merge two sorted linked lists and return it as a new list.
    The new list should be made by splicing together the nodes of the first two lists.
*/
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


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode*h1=l1,*h2 = l2;
        if(h1 == NULL)
            return h2;
        if(h2 == NULL)
            return h1;

        ListNode* head=new ListNode(0);
        ListNode *p = head;
        while(h1&&h2){
            int val1 = h1->val;
            int val2 = h2->val;
            if(val1 < val2){
                p->next = h1;
                h1 = h1->next;

            }
            else{
                p->next = h2;
                h2 = h2->next;
            }

            p = p->next;

        }

        if(h1!=NULL)
            p->next = h1;
        if(h2!= NULL)
            p->next = h2;
        p = head->next;
        delete head;
        return p;
}


int main(){
    const int SIZE=10;
    struct ListNode *n[SIZE];

    for(int i=0;i<SIZE/2;++i){
        n[i] =  new ListNode(i*2);
        n[i]->next = NULL;
    }

    for(int i=SIZE/2;i<SIZE;++i){
        n[i] =  new ListNode((i-SIZE/2)*2+1);
        n[i]->next = NULL;
    }

    for(int i=0;i<SIZE/2;++i){
        if(i<SIZE/2-1)
            n[i]->next = n[i+1];
        else
            n[i]->next = NULL;
    }

   for(int i=SIZE/2;i<SIZE;++i){
        if(i<SIZE-1)
            n[i]->next = n[i+1];
        else
            n[i]->next = NULL;
    }

    struct ListNode *p=n[0];

    printList(p);
    printList(n[SIZE/2]);
    p = mergeTwoLists(p,n[SIZE/2]);
    printList(p);
    for(int i=0;i<SIZE;++i)
        delete n[i];

}
