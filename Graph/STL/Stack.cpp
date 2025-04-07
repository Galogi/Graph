// File: Stack.cpp
// Author: galogimaymon@gmail.com
// Description: Implementation of a basic stack data structure using a dynamic array.

#include "Stack.hpp"
#include <iostream>

/**
 * @brief Constructs a stack with a specified size.
 * @param size The maximum number of elements the stack can hold.
 */
Stack::Stack(int size) {
    this->size = size;
    arr = new int[size];
    top = -1;
}

/**
 * @brief Destructor to free allocated memory.
 */
Stack::~Stack() {
    delete[] arr;
}

/**
 * @brief Checks if the stack is empty.
 * @return true If the stack is empty, false otherwise.
 */
bool Stack::isEmpty() {
    return top == -1;
}

/**
 * @brief Checks if the stack is full.
 * @return true If the stack is full, false otherwise.
 */
bool Stack::isFull() {
    return top == size - 1;
}

/**
 * @brief Pushes a new value onto the stack.
 * @param value The value to push.
 * @note If the stack is full, prints an error message and does nothing.
 */
void Stack::push(int value) {
    if (isFull()) {
        std::cerr << "Stack overflow!" << std::endl;
        return;
    }
    arr[++top] = value;
}

/**
 * @brief Pops the top value from the stack.
 * @return The popped value, or -1 if the stack is empty.
 * @note Prints an error message on underflow.
 */
int Stack::pop() {
    if (isEmpty()) {
        std::cerr << "Stack underflow!" << std::endl;
        return -1;
    }
    return arr[top--];
}

/**
 * @brief Returns the top value without removing it.
 * @return The value at the top of the stack, or -1 if the stack is empty.
 */
int Stack::peek() {
    if (isEmpty()) {
        std::cerr << "Stack is empty!" << std::endl;
        return -1;
    }
    return arr[top];
}
