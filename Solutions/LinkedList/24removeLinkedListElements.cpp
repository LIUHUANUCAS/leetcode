#include<iostream>
using namespace std;
/**
    Remove all elements from a linked list of integers that have value val.

    Example
    Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
    Return: 1 --> 2 --> 3 --> 4 --> 5
    237DeleteNodeLinkedList.cpp
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

ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
            return head;
        ListNode* p = head,*q=0;
        ListNode* h = new ListNode(0);
        h->next = head;
        q = h;
        while(q->next){
            int res = q->next->val;
            if(res == val){
                ListNode* tmp = q->next;
                q->next = tmp->next;
                delete tmp;
            }
            else
                q = q->next;
        }
        q = h;
        head = h->next;
        delete q;
        return head;
}


int main(){
    int array[] = {1,2,6,3,4,5,6,2,2,2,2,2};

    ListNode* p = createNodeList(array,array+sizeof(array)/sizeof(int));
    printList(p);
    int k =1;
    p = removeElements(p,k);

    printList(p);

    freelistNode(p);

}
