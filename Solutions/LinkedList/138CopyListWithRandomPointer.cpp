#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
/**

    A linked list is given such that each node contains an additional random pointer
    which could point to any node in the list or null.

    Return a deep copy of the list.

    138Copy List with Random Pointer.cpp
*/
/**
    Solutions:
        firstly,we can copy the Linkedlist without copy the random pointer of the node.
        but at the copy node time,we can make a map that map the original node to the new node.
        so when we traval the map ,we can easily get the original node of the random pointer,after
        get known the random pointer which original node it should point,we can get the new node's
        random pointer,which new node should it point.
        so the process last until the end.copy finished.
        for e in map:
            originalNode = e.first
            newNode = e.second
            originalNodeRandomPointer = originalNode->random
            tempnewAddress = map[originalNodeRandomPointer]
            if tempnewAddress is not null:
                newNode->random = tempnewAddress
        return the copy list

    Complexity:
        all node of the Linkedlist will be travalled.
        so the Complexity will be O(n),where n is the size of Linkedlist

*/



struct RandomListNode {
    int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

typedef RandomListNode ListNode;

 void printList(ListNode* head){
    cout<<endl<<"-------------begin-----------------"<<endl;
    ListNode* rh = head;
    while(rh!=NULL){
        cout<<rh->label<<" ";
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

void freelistNode(ListNode*head){
    while(head){
        ListNode* p = head->next;
        delete head;
        head = p;
    }
}

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL)
            return head;
        if(head->next == NULL)
        {
            RandomListNode* root = new RandomListNode(head->label);
            if(head->random != NULL)
                root->random = root;
            return root;
        }

        RandomListNode* h2 = new RandomListNode(-2);
        RandomListNode* p = h2;
        RandomListNode* q = head;
        map<RandomListNode*,RandomListNode* > original2Copy;
        while(q){
                RandomListNode* copyNode = new RandomListNode(q->label);
                p->next = copyNode;
                p = p->next;
                original2Copy[q] = copyNode;
                q = q->next;
        }

        for(auto& e:original2Copy){
            RandomListNode* first = e.first;
            RandomListNode* second = e.second;
            q = first->random;
            if(q != NULL)
                second->random = original2Copy[q];
        }

        q = h2->next;
        delete h2;
        return q;
    }
};



int main(){
    int array[] = {1,4,3,2,5,2};

    ListNode* p = createNodeList(array,array+sizeof(array)/sizeof(int));
    printList(p);
    int k =3;
    Solution s;
    p = s.copyRandomList(p);
    printList(p);

    freelistNode(p);
    return 0;

}
