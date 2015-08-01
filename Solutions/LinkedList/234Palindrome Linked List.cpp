#include<iostream>
#include<ctime>
#include <cstdlib>
using namespace std;


/**
    doc

    Given a singly linked list, determine if it is a palindrome.

    Follow up:
    Could you do it in O(n) time and O(1) space?

    Hide Tags Linked List Two Pointers


   234Palindrome Linked List.cpp
*/
/**
    Solutions:
        as the definition of palindrome,that is str=ab,while reverse str is the same as str
    so we can draw conclusion that if str length is odd than the str will be symmetry as the center of the str
    we will reverse the linkedlist from start to the middle.
    and there are two pointers ,one of which will pointer the start and the other will pointer the middle one
    pass the middle if the size is odd.otherwise the pointer will pointer the exact middle.
    and two pointers move one step at the same time,and compare the value of the pointer....
    finally we will determined wether the linkedlist is a palindrome or not

    Complexity:
        we will reverse half of the linkedlist and traval the whole linkedlist at the worest situation
    so the Complexity will be O(n) where n is the size of Linkedlist

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
    printList(p->next);
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
    public:
            bool isPalindrome(ListNode* head) {
                if(head == NULL)
                    return 1;
                int size = listSize(head);
                if(size == 1)
                    return 1;
                struct ListNode *p=head,*q=head,*rh=head;
                int count = 1;
                int Nth = size/2;
                while(p&&p->next&&count<Nth){
                    count ++;
                    q = p->next;
                    p->next = q->next;
                    q->next = rh;
                    rh = q;
                }
                head = rh;
                if(size % 2== 1)
                    p = p ->next;
                ListNode* tmp = p->next;
                if(!tmp)
                    return 0;
                while(tmp){
                    int hval = rh->val;
                    int qval = tmp->val;
                    if(qval != hval)
                        return 0;
                    tmp = tmp->next;
                    rh = rh ->next;
                }
                return 1;
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
