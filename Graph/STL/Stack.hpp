#ifndef STACK_H
#define STACK_H

class Stack {
private:
    int* arr;      
    int top;       
    int size;      

public:
    Stack(int size);
    ~Stack();

    bool isEmpty();
    bool isFull();
    void push(int value);
    int pop();
    int peek();
};

#endif
