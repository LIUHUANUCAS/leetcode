#include<iostream>
using namespace std;
/**
   Given a linked list and a value x,
   Sort a linked list in O(n log n) time using constant space complexity.

    Hide Tags Linked List Sort



    148Sort List.cpp
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
ListNode* createNodeList(int* begin,int *end){
    ListNode* head = new ListNode(0);
    ListNode* p = head;
    while(begin < end){
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
void freelistNode(ListNode *head){
    while(head){
        ListNode* p = head->next;
        delete head;
        head = p;
    }

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
    printList(p->next);
    return rh;
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
ListNode* partition(ListNode* head, int x) {
        if(head == NULL)
            return head;
        ListNode* h1 = new ListNode(0);
        ListNode* h2 = new ListNode(0);
        ListNode* p =h1,*q= h2;
        while(head){
            int val = head->val;
            if(val < x){
                p->next = head;
                p= p->next;
            }else{
                q ->next = head;
                q = q->next;
            }
            head = head->next;
        }
        p->next = h2->next;
        q->next = NULL;
        head = h1->next;
        delete h1;
        delete h2;
        return head;
}


class Solution {
        public:
            ListNode* sortList(ListNode* head) {

            }
};




int main(){
        int array[] = {1,2,3,3,3,2,1};
        int size = sizeof(array)/sizeof(int);
        ListNode* head = createNodeList(array,array+size-1);
        Solution s;
        /*your code here..*/
        bool res = s.isPalindrome(head);
        cout<<res<<endl;
        freelistNode(head);
        return 0;
}
