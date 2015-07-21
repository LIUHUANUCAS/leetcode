#include<iostream>
using namespace std;
/**
    Given a singly linked list L: L0¡úL1¡ú¡­¡úLn-1¡úLn,
    reorder it to: L0¡úLn¡úL1¡úLn-1¡úL2¡úLn-2¡ú¡­
    You must do this in-place without altering the nodes' values.
    For example,
    Given {1,2,3,4}, reorder it to {1,4,2,3}.
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
int listSize(ListNode* head){
    if(head == NULL)
        return 0;
    int n=0;
    ListNode* p = head;
    while(p){
        n++;
        p = p->next;
    }
    return n;
}


ListNode* mergeList(ListNode*h1,ListNode*h2){
        if(h1 == NULL || h2 == NULL)
            return NULL;
        ListNode* head=h1,*p=h1,*q,*tmp;
        h1 = h1->next;
        while(h2){
            q = h2->next;
            tmp = p->next;
            p->next = h2;
            h2->next = tmp;
            p = tmp;

            h2 = q;
        }
//        printList(head);
        return head;
}

void reorderList(ListNode* head) {
    int size = listSize(head);
//    cout<<size<<endl;
    if(size <=2)
        return ;
    ListNode *h1=head,*h2=0;
    ListNode *p=h1,*q=h2;
    int count=0;
    int stop = size / 2;
    if(size%2 == 1)
        stop++;
    while(count < stop){
        if(count == stop - 1){
//            cout<<p->val<<"over"<<endl;
            q = p->next;
            p->next = NULL;
            h2 = q;
            break;
        }
        count++;
        p = p->next;
    }
//    printList(h1);
    h2 = reverseList(h2);
//    printList(h2);

    head = mergeList(h1,h2);

}

int main(){
    const int SIZE=6;
    struct ListNode *n[SIZE];

    for(int i=0;i<SIZE;++i){
        n[i] =  new ListNode(i+1);
    }
    for(int i=0;i<SIZE;++i){
        if(i<SIZE-1)
            n[i]->next = n[i+1];
        else
            n[i]->next = NULL;
    }

    struct ListNode *p=n[0];
    reorderList(p);
    printList(p);
    for(int i=0;i<SIZE;++i)
        delete n[i];

}
