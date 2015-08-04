#include<iostream>
#include<vector>
#include <cstdlib>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<cstdio>
// #include<string.h>

using namespace std;


/**
    doc

    Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    getMin() -- Retrieve the minimum element in the stack.

    Hide Tags
     Stack Data Structure

    155minStack.cpp
*/

class MinStack {
private:

    int * array;
    int * minarray;
    int * arrayp;
    int * minarryp;
    size_t size;
    size_t STACKMAXSIZE=10;
public:
    MinStack(){
        array = new int[STACKMAXSIZE];
        // arrayp = array;
        size = 0;
        minarray = new int[STACKMAXSIZE];
        // minarrayp = minarray;
    }

    ~MinStack(){
        delete[] array;
        size = 0;
        delete[] minarray;
    }

    void push(int x) {
        if(size >= STACKMAXSIZE){
                cout<<"size:"<<size<<endl;

            int* tmparray = new int[STACKMAXSIZE *2];
            memcpy(tmparray,array,sizeof(int)*size);
            int* tmpminarray = new int[STACKMAXSIZE*2];
            STACKMAXSIZE*=2;
            memcpy(tmpminarray,minarray,sizeof(int)*size);
            delete [] array;
            delete [] minarray;
            array = tmparray;
            minarray = tmpminarray;
        }

        if(size == 0){
            array[0] = x;
            minarray[0] = x;
            size++;
        }else{
            array[size] = x;
            minarray[size] = min(x,minarray[size-1]);
            size++;
        }
    }

    void pop() {
        if(size > 0){
            size --;
        }
//        else{
//            cout<<"empty stack"<<endl;
//        }

    }

    int top() {
        if(size>0)
            return array[size-1];
//        else
//            cout<<"empty stack"<<endl;
    }

    int getMin() {
        if(size > 0)
            return minarray[size-1];
    }
    bool isEmpty(){
        return size <= 0;
    }
};

int main(){
        MinStack s;
        for(int i=1;i<60;++i){
            s.push(i);
            int x = s.getMin();
            cout<<"i="<<i<<" min is "<< x<<endl;
        }

        while(!s.isEmpty()){
            int x = s.top();
            int minx = s.getMin();

            cout<<"min is "<<minx<< " x: "<<x<<endl;
            s.pop();
        }
        return 0;

}
