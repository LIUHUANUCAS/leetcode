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

class Stack {
    queue<int> q1;
    queue<int> q2;
public:
    // Push element x onto stack.
    void push(int x) {
        if(!q1.empty())
            q1.push(x);
        else
            q2.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {

    }

    // Get the top element.
    int top() {

    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty() && q2.empty();

    }
};

int main(){

        return 0;

}
