#include<iostream>
using namespace std;
/**
    Sort a linked list using insertion sort.
    147insertSortLinkedList.cpp
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

ListNode* insertionSortList(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode* h1 = new ListNode(0);
        ListNode* q = head;
        ListNode * p = h1;
        h1->next = q;
        head = head ->next;
        q ->next = 0;
        q = head;
        while(q){
            int val = q->val;
            p = h1;
            while(p->next){
                int res = p->next->val;
                if(res > val)
                    break;
                p = p->next;
            }//find insert location

            ListNode* tmp = q->next;
            q->next = p->next;
            p->next = q;
            q = tmp;
        }
        head = h1->next;
        delete h1;
        return head;
}


int main(){
    int array[] = {1,4,3,2,5,2,3,2,1,1,2,3,2,1,2,1,3,5,7,4,8,9,0};

    ListNode* p = createNodeList(array,array+sizeof(array)/sizeof(int));
    printList(p);
    int k =3;
    p = insertionSortList(p);

    printList(p);

    freelistNode(p);

}
