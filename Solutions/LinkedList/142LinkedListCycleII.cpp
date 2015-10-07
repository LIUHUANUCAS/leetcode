#include<iostream>
#include<ctime>
#include <cstdlib>
using namespace std;


/**
    doc

    Given a linked list, return the node where the cycle begins.
    If there is no cycle, return null.
    
    Note: Do not modify the linked list.


    142Linked List CycleII.cpp
*/

/**
    Solutions:
    if there exist a cycle then,we can get two pointers which may be in the cycle at the same time.
    we can make a dession that one pointer can move one step at a time,while the other pointer can
    move two or more steps forward, that is to say the two pointers has diffient velocity ,the result of
    which will be that one pointer with higher velocity will come up with the slow pointer because both of
    them are on a cycle.
    so we can solve it!


    Complexity:
   
*/

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

 void printList(ListNode* head){
     int count = 0;
    cout<<endl<<"-------------begin-----------------"<<endl;
    if(head == NULL){
        cout<<"empty...."<<endl;
        cout<<endl<<"-------------over------------------"<<endl;
        return ;
    }
    ListNode* rh = head;
    while(rh!=NULL){
        cout<<rh->val<<" >> ";
        rh = rh->next;
        count++;
        if(count> 15)break;
    }
    cout<<endl<<"-------------over------------------"<<endl;
}

ListNode* getNthNode(ListNode* head,int n){
    if(head == NULL)
        return head;
    if(n == 1)return head;
    int m=1;
    ListNode* p = head;
    while(m<n){
        m++;
        p = p->next;
    }
    return p;
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

ListNode* getTail(ListNode* head){
    if(head == NULL)
        return head;

    ListNode* h = new ListNode(0);
    h ->next = head;
    ListNode* p = h;

    while(p->next){
        p = p ->next;
    }
    delete h;
    return p;
}


class Solution {
    public:
        ListNode* hasCycle(ListNode *head) {
            if(head == NULL)
                return 0;
            if(head->next == head)
                return head;
            ListNode* p = head,*q= head;
            q = q -> next;
            if(q == NULL)
                return 0;
            q = q ->next;

            while(p && q){
                if( p == q)
                    return q;
                p = p->next;
                q = q ->next;
                if(!q)
                    return 0;
                q = q->next;
            }
            return  0;
        }
        
        ListNode *detectCycle(ListNode *head) {
            
            if(head == NULL)
                return 0;
            ListNode* p = head,*q= head;
            while(p && p->next){
                p = p->next->next;
                q = q ->next;
                if( p == q)
                    break;
            }
            if(p == NULL || p->next == NULL)
                return 0;
            p = head;
            while(q != p){
                p = p->next;
                q = q->next;
            }
            
            return q;
        }
        
        
        ListNode * FindLoopPort(ListNode * head)
        {
            ListNode * slow = head, * fast = head;
        
            while ( fast && fast -> next )
            {
                slow = slow -> next;
                fast = fast -> next -> next;
                if ( slow == fast ) break ;
            }
            
            if (fast == NULL || fast -> next == NULL)
                return NULL;
            // cout<<"in cycle"<<slow->val<<endl;
            slow = head;
            while (slow != fast)
            {
                // cout<<slow->val<<"->" << fast->val<<endl;
                slow = slow -> next;
                fast = fast -> next;
            }
            // cout<<"enter of cycle->"<<slow->val<<endl;
            return slow;
        }
        
        
};

int main(){
        int array[] = {
            // 1
            1,2,3,4,5,6,7,8
            // 3,2,0,-4            
            };
        int size = sizeof(array)/sizeof(int);
        ListNode* head = createNodeList(array,array+size-1);
        printList(head);
        /*your code here..*/
        ListNode* tail = getTail(head);
        int kth=5;
        ListNode* mid = getNthNode(head,kth);
        tail->next = mid;
        // printList(mid);

        Solution s;
        ListNode* res1 = s.FindLoopPort(head);
        
        ListNode* res = s.detectCycle(head);

        // printList(res);
        tail->next = 0;
//        printList(head);
        freelistNode(head);
        return 0;
}
