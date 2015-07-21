#include<iostream>
#include<ctime>
#include <cstdlib>
using namespace std;


/**
    You are given two linked lists representing two non-negative numbers.
    The digits are stored in reverse order and each of their nodes contain a single digit.
    Add the two numbers and return it as a linked list.

    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 0 -> 8
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
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode*h1=l1,*h2 = l2;
        if(h1 == NULL)
            return h2;
        if(h2 == NULL)
            return h1;

        ListNode* head=new ListNode(0);
        ListNode *p = head;
        int flag = 0;
        while(h1&&h2){
            int val1 = h1->val;
            int val2 = h2->val;
            int sum = val1 + val2;
            if(flag ){
                sum +=1;
                flag = 0;
            }

            if(sum >= 10){
                sum -= 10;
                flag = 1;
            }

            h1->val = sum;
            p->next = h1;
            h1 = h1 ->next;
            h2 = h2->next;
            p = p->next;

        }

        while(h1!=NULL){
            if(flag){
                h1->val+=1;
                flag = 0;
            }

            if(h1->val >= 10){
                h1->val -= 10;
                flag = 1;
            }

            p->next = h1;
            h1 = h1->next;
            p = p->next;
        }

          while(h2!=NULL){
            if(flag){
                flag = 0;
                h2->val+=1;
            }
            if(h2->val >= 10){
                h2->val -= 10;
                flag = 1;
            }

            p->next = h2;
            h2 = h2->next;
            p = p->next;
        }

        if(flag){
            head->val = 1;
            p->next = head;
            p =head->next;
            head->next = 0;

        }else{
            p =head->next;
            delete head;
        }
        return p;
}
 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return mergeTwoLists(l1,l2);
}

int main(){
    const int SIZE=10;
    struct ListNode *n[SIZE];
    srand(unsigned(time(0)));
    int start = 3;//(int)rand()%10;
    const int n1 = 1;
    ListNode* num1[n1];
    for(int i=0;i<n1;++i){
        num1[i] =  new ListNode(9);
//        num1[i] =  new ListNode((int)rand()%10);
        num1[i]->next = NULL;
    }
    const int n2 = 1;
    ListNode* num2[n2];
    for(int i=0;i<n2;++i){
        num2[i] =  new ListNode(1);
//        num2[i] =  new ListNode((int)rand()%10);
        num2[i]->next = NULL;
    }
    int i=0;
    while(i<n1-1){
         num1[i]->next = num1[i+1];
         i++;
    }
    num1[i]->next = NULL;
    i = 0;
    while(i<n2-1){
         num2[i]->next = num2[i+1];
         i++;
    }
    num2[i]->next = NULL;


    struct ListNode *p=NULL;
    printList(num1[0]);
    printList(num2[0]);

    p = mergeTwoLists(num1[0],num2[0]);
    printList(p);
    for(int i=0;i<n1;++i)
        delete num1[i];

    for(int i=0;i<n2;++i)
        delete num2[i];
}
