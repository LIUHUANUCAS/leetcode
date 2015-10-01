#include<iostream>
#include<ctime>
#include <cstdlib>
using namespace std;


/**
   doc

   name.cpp
*/
/**
    Solutions:

    Complexity:
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
        ListNode* deleteDuplicates(ListNode* head) {
            if(head == NULL)
                return head;
            if(head->next == NULL)
                return head;
            ListNode* h1 = new ListNode(0);
            ListNode* h2 = head->next;
            ListNode* preh2 = head;
            ListNode* p = h1,*q=0;
            //h2->next = head;
//            int preval;
            while(preh2){

                int val = preh2->val;
                h2 = preh2->next;
                while(h2&& h2->val == val){
                    ListNode* tmp = h2;
                    h2 = h2->next;
                    delete tmp;
                }

//                cout<<"h2:"<<h2->val<<endl;
                if(h2 == preh2->next){
//                    cout<<"add one node "<<preh2->val<<endl;
                    p->next = preh2;

                    preh2 = preh2->next;

                    p = p->next;
                    p->next = 0;
                    preh2 = h2;
                }else{
//                    cout<<"end "<<endl;
                    q = preh2;
                    preh2 = h2;
//                    cout<<"delete q preline"<<endl;
                    if(!q)
                    delete q;
//                    cout<<"delete q success..."<<endl;
                }

            }//while
//            printList(h1);
            p = h1->next;
            delete h1;
            return p;
        }


};

int main(){
        int array[] = {1,2,2};
        int size = sizeof(array)/sizeof(int);
        ListNode* head = createNodeList(array,array+size-1);
        printList(head);
        Solution s;
        /*your code here..*/
        head = s.deleteDuplicates(head);
        printList(head);
        freelistNode(head);
        return 0;
}
