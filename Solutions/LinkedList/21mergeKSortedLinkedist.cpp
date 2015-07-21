#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<iterator>
using namespace std;
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

void printListSize(ListNode* head){
    cout<<endl<<"-------------begin-----------------"<<endl;
    ListNode* rh = head;
    int size=0;
    while(rh!=NULL){
//        cout<<rh->val<<" ";
        size ++;
        rh = rh->next;
    }
    cout <<size;
    cout<<endl<<"-------------over------------------"<<endl;
}
void printKlist(vector<ListNode* > & list){
    for(vector<ListNode*>::iterator it = list.begin();it != list.end();++it){
        printListSize(*it);
//        printList(*it);
    }

}


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode*h1=l1,*h2 = l2;
        if(h1 == NULL)
            return h2;
        if(h2 == NULL)
            return h1;

        ListNode* head=new ListNode(0);
        ListNode *p = head;
        while(h1&&h2){
            int val1 = h1->val;
            int val2 = h2->val;
            if(val1 < val2){
                p->next = h1;
                h1 = h1->next;
            }
            else{
                p->next = h2;
                h2 = h2->next;
            }

            p = p->next;

        }

        if(h1!=NULL)
            p->next = h1;
        if(h2!= NULL)
            p->next = h2;
        p = head->next;
        delete head;
        return p;
}
ListNode* mergeKLists(vector< ListNode * > & lists) {
    vector< ListNode * > second;
    vector< ListNode* > *ptr[2] = {&lists,&second};
    int size = lists.size();
    cout <<"begin ...."<<endl;
    while(size != 1){

    if(ptr[0]->size() % 2 == 1 )
        ptr[1]->push_back(lists[lists.size()-1]);
    for(int i=0;i<ptr[0]->size()-1;i+=2){
        cout<<i<<endl;
        ListNode* tmp = mergeTwoLists((*ptr[0])[i],(*ptr[0])[i+1]);
        ptr[1]->push_back(tmp);
//        i++;
    }
        ptr[0]->clear();

        size = ptr[1]->size();

        swap(ptr[0],ptr[1]);
//    vector<ListNode* > *t = ptr[0];
//    ptr[0] = ptr[1];
//    ptr[1] = t;

    }


    printKlist(*ptr[1]);
    return NULL;
}

ListNode* createList(vector<int>& num){
    ListNode* head = new ListNode(num[0]);
    ListNode* p = head,*q = 0;
    for(size_t i = 1;i<num.size();++i){
        q = new ListNode(num[i]);
        q ->next = NULL;
        p ->next = q;
        p = p->next;
    }
    return head;
}

void freeNode(ListNode* head){
    ListNode* p=head;
    while(head){
        p = p->next;

        delete head;
        head = p;

    }
}
void freeNodeList(vector<ListNode * >& list){
    for(vector<ListNode*>::iterator it = list.begin();it != list.end();++it){
        freeNode(*it);
//        printList(*it);
    }

}

vector< ListNode *> createKsortedList(vector<vector<int> > & nums){
    vector< ListNode *> Nodelist;
    ListNode * p=0;
    for(vector<vector<int> >::iterator it = nums.begin();it != nums.end();++it){
        p = createList(*it);
        Nodelist.push_back(p);
    }

    return Nodelist;
}

vector<int> createData(int size){
    vector<int> num;
    for(int i = 0;i<size;++i){
        num.push_back((int)rand()%100);
    }

    sort(num.begin(),num.end());
//    copy(num.begin(),num.end(),ostream_iterator<int>(cout," ") );
    cout<<num.size();
    cout<<endl;
    return num;
}

int main(){
    const int SIZE=10;
    vector<vector<int> > nums;
//    srand(time(0));
    for(int i=0;i<SIZE;++i){
        int size = (int)rand() % 20 + 2;
        vector<int> nl = createData(size);
        nums.push_back(nl);
    }

    vector<ListNode* > list = createKsortedList(nums);
    ListNode* head = mergeKLists(list);
    freeNode(head);
//    printKlist(list);


//    printList(p);


}
