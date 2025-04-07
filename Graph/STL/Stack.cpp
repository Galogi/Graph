#include "Stack.hpp"
#include <iostream>

Stack::Stack(int size) {
    this->size = size;
    arr = new int[size];
    top = -1;
}

Stack::~Stack() {
    delete[] arr;  
}

bool Stack::isEmpty() {
    return top == -1;
}

bool Stack::isFull() {
    return top == size - 1;
}

void Stack::push(int value) {
    if (isFull()) {
        std::cerr << "Stack overflow!" << std::endl;
        return;
    }
    arr[++top] = value;
}

int Stack::pop() {
    if (isEmpty()) {
        std::cerr << "Stack underflow!" << std::endl;
        return -1;  
    }
    return arr[top--];
}

int Stack::peek() {
    if (isEmpty()) {
        std::cerr << "Stack is empty!" << std::endl;
        return -1;  
    }
    return arr[top];
}
