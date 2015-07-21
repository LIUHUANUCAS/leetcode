#include<iostream>
using namespace std;
/**
    Reverse a linked list from position m to n. Do it in-place and in one-pass.

    For example:
    Given 1->2->3->4->5->NULL, m = 2 and n = 4,
    return 1->4->3->2->5->NULL.

    Note:
    Given m, n satisfy the following condition:
    1 ¡Ü m ¡Ü n ¡Ü length of list.
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

ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m<=1){
//            cout<<"head == start"<<endl;
            ListNode* rh = reverseList(head,n-m+1);
            return rh;
        }
        else{
             ListNode* start = getNthNode(head,m);
             ListNode* rh = reverseList(start->next,n-m+1);
             start->next = rh;
             return head;
        }

}

ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * p = head;
        int size = listSize(head);
        int a=1,b=k;
        while(a<=size&&b<=size){
            p = reverseBetween(p,a,b);
            a+=k;
            b+=k;
        }
        return p;
}

ListNode* swapPairs(ListNode* head) {
    return reverseKGroup(head,2);
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
    printList(p);
    int k=3;
    p = swapPairs(p);

    printList(p);
    for(int i=0;i<SIZE;++i)
        delete n[i];

}
