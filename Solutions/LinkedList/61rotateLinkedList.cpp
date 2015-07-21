#include<iostream>
using namespace std;
/**
    Given a list, rotate the list to the right by k places, where k is non-negative.
    For example:
    Given 1->2->3->4->5->NULL and k = 2,
    return 4->5->1->2->3->NULL.
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
int listSize(ListNode* head,ListNode** end ){
    if(head == NULL){
        end = 0;
        return 0;
    }
    int n=0;
    ListNode* p = head;
    while(p->next){
        n++;
        p = p->next;
    }
    *end = p;
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
ListNode* rotateRight(ListNode* head, int k) {
    if(k<=0)
        return head;
    if(head == NULL)
        return head;
    int size = 0;
    ListNode* endNode=0,*newhead=0;
    size = listSize(head,&endNode);
    k = k % size;
//    k = 2;
    if(k%size == 0)
        return head;

    int nthNode = size - k + 1;
    if(k==1)
        nthNode = size;
//    cout<<nthNode%size<<endl;
    ListNode* newend = getNthNode(head,nthNode);
//    printList(newend);
    newhead = newend->next;
    newend->next = 0;
    endNode->next = head;
    head = newhead;
//    printList(head);
    return head;
}


int main(){
    const int SIZE=5;
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
//    printList(p);
    int k=5;
//    cout<<k<<endl;
//    printList(p);
    p = rotateRight(p,k);
    printList(p);
    for(int i=0;i<SIZE;++i)
        delete n[i];

}
