#include<iostream>
using namespace std;
/**
    Given a linked list, remove the nth node from the end of list and return its head.
    For example,
    Given linked list: 1->2->3->4->5, and n = 2.
    After removing the second node from the end, the linked list becomes 1->2->3->5.
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
ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n<=0)return head;
        if(head == NULL)
            return head;
        if(head->next == NULL)
            return NULL;
        ListNode* p = head,*q=head,*tmp=0;
        int t=n;
        while(n){
            n--;
            q = q ->next;
        }

        if(q ==NULL){//n == 1 or
            return head->next;
        }
        p = p->next;
        q = q->next;
        ListNode*h = head;
        while(q){
            p = p->next;
            q = q->next;
            h = h->next;
        }

        if(p == head)
            head = head->next;
        else
            h->next = p->next;
        return head;
}

int main(){
    const int SIZE=1;
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
    printList(p);
    int k=1;
    p = removeNthFromEnd(p,k);

    printList(p);

    for(int i=0;i<SIZE;++i)
        delete n[i];

}
