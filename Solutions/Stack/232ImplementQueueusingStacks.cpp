#include<iostream>
#include<vector>
#include <cstdlib>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include <stack>          // std::stack
//#include <deque>


using namespace std;


/**
    doc
    Implement the following operations of a queue using stacks.
    push(x) -- Push element x to the back of queue.
    pop() -- Removes the element from in front of queue.
    peek() -- Get the front element.
    empty() -- Return whether the queue is empty.

    Notes:
    You must use only standard operations of a stack -- which means only push to top,
    peek/pop from top, size, and is empty operations are valid.
    Depending on your language, stack may not be supported natively.
    You may simulate a stack by using a list or deque (double-ended queue),
    as long as you use only standard operations of a stack.
    You may assume that all operations are valid
    (for example, no pop or peek operations will be called on an empty queue).

    232ImplementQueueusingStacks.cpp
*/
/**
    Solutions:
      using two standard stack:s1,s2 ,one is to enqueue element ,and one is pop to get the front element of the queue.
      when we get the front of the queue,we firstly judge wether the stack s2 is empty. if s2 is empty we will pop
      all the elements of stack s1 and push them to the stack s2 finally we will get pop from the stack s2 and we will
      get the front of the queue.otherwise, we just pop from the s2 to get the front of the queue.
*/
class Queue {
private:
    stack<int> s1;
    stack<int> s2;
//    size_t STACKSIZE = 20;
public:
    // Push element x to the back of queue.
    void push(int x) {
        s1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(!s2.empty())
            return s2.pop();
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            if(!s2.empty())
                return s2.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        if(!s2.empty())
            return s2.top();
        else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            if(!s2.empty())
                return s2.top();
        }
    }
    // Return whether the queue is empty.
    bool empty(void) {
        return s1.empty() && s2.empty();
    }
};


int main(){
    Queue queue;
    for(int i=1;i<20;++i)
        queue.push(i);
    cout<<"enque over..."<<endl;
    cout<<queue.empty()<<endl;
    while(!queue.empty()){
        int x = queue.peek();
        queue.pop();
        cout<<"dequeue "<< x<<endl;
    }
    return 0;

}
