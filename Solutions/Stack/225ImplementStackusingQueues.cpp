#include<iostream>
#include<vector>
#include <cstdlib>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include <queue>

using namespace std;


/**
    doc

    Implement the following operations of a stack using queues.
    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    empty() -- Return whether the stack is empty.

    Notes:
    You must use only standard operations of a queue -- which means only push to back,
    peek/pop from front, size, and is empty operations are valid.
    Depending on your language, queue may not be supported natively.
     You may simulate a queue by using a list or deque (double-ended queue),
     as long as you use only standard operations of a queue.
    You may assume that all operations are valid
    (for example, no pop or top operations will be called on an empty stack).


    225ImplementStackusingQueues.cpp
*/
/**
    Solutions:
        we can use two queue to implement the stack ,one queue is use to store the element
        and the other is used to imitate the stack operations such as pop ,top and so on
        the later queue should be only one element when we perform the pop, top operation,
        so the first queue will be pop all elements except the last one,which is also the
        element on the top of stack.the two queue will exchange with each other for their role.

*/
class Stack {
    queue<int> q1;
    queue<int> q2;
    int flag = 1;
public:
    // Push element x onto stack.
    void push(int x) {
        if(flag == 1)
            q1.push(x);
        else
            q2.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        int x;
         if(flag == 1 && !q1.empty()){
            while(q1.size() != 1){
                x = q1.front();
                q1.pop();
                q2.push(x);
            }
            flag = 2;

            q1.pop();
            return ;
        }
        if(flag == 2 && !q2.empty()){
             while(q2.size() != 1){
                int x = q2.front();
                q2.pop();
                q1.push(x);
            }
            flag = 1;
            //x = q2.front();
            q2.pop();
            return ;
            //return x;
        }
    }

    // Get the top element.
    int top() {
        if(flag == 1&& !q1.empty()){
            while(q1.size() != 1){
                int x = q1.front();
                q1.pop();
                q2.push(x);
            }
//            flag = 2;
            return q1.front();
        }
        if(flag == 2 && !q2.empty()) {
             while(q2.size() != 1){
                int x = q2.front();
                q2.pop();
                q1.push(x);
            }
//            flag = 1;
            return q2.front();
        }


    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty() && q2.empty();

    }
};

int main(){
        Stack s;
        for(int i=10;i<25;++i)
            s.push(i);
        while(!s.empty()){
            int x = s.top();
            s.pop();
            cout<<"x "<<x<<endl;
        }
        return 0;

}
