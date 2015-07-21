#include<iostream>
using namespace std;
/**
   Given a linked list and a value x,
   partition it such that all nodes less than x come before nodes greater than or equal to x.

    You should preserve the original relative order of the nodes in each of the two partitions.
    For example,
    Given 1->4->3->2->5->2 and x = 3,
    return 1->2->2->4->3->5.

    86PartitionLinkedList .cpp
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


int main(){
    int array[] = {1,4,3,2,5,2};

    ListNode* p = createNodeList(array,array+sizeof(array)/sizeof(int));
    printList(p);
    int k =3;
    p = partition(NULL,k);

    printList(p);

    freelistNode(p);

}
