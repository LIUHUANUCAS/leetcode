#include<iostream>
#include<vector>
#include <cstdlib>
#include<iterator>
#include<algorithm>
#include<cstring>

using namespace std;


/**
    doc



    name.cpp
*/

class MinStack {
private:

    int * array;
    int * minarray;
    size_t size;
    const size_t STACKSIZE=30;
public:
    MinStack(){
        array = new int[STACKSIZE];
        size = 0;
        minarray = new int[STACKSIZE];
    }

    ~MinStack(){
        delete[] array;
        size = 0;
        delete[] minarray;
    }

    void push(int x) {
        if(size >= sizeof(array)/sizeof(int)){

            array = new int[STACKSIZE + size];
            minarray = new int[STACKSIZE + size];
        }
        if(size == 0){
            array[0] = x;
            minarray[0] = x;
            size++;
        }else{
            array[size] = x;
            minarray[size] = min(x,minarray[size-1]);
        }
    }

    void pop() {
        if(size >=0){
            size --;
        }

    }

    int top() {
        if(size>=0)
            return array[size];
    }

    int getMin() {
        if(size >=0)
            return minarray[size];
    }
};

int main(){
        MinStack s;

}
