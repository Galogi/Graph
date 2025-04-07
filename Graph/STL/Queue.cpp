// File: Queue.cpp
// Author: galogimaymon@gmail.com
// Description: Implementation of a basic circular queue using a dynamic array.

#include "Queue.hpp"
#include <stdexcept>

/**
 * @brief Constructs a new Queue with a given capacity.
 * @param capacity The maximum number of elements the queue can hold.
 */
Queue::Queue(int capacity)
    : front(0), rear(0), size(0), capacity(capacity)
{
    data = new int[capacity];
}

/**
 * @brief Destructor that frees the dynamically allocated array.
 */
Queue::~Queue() {
    delete[] data;
}

/**
 * @brief Adds a value to the end of the queue.
 * @param val The value to enqueue.
 * @throws std::overflow_error If the queue is full.
 */
void Queue::enqueue(int val) {
    if (size == capacity) {
        throw std::overflow_error("Queue overflow");
    }
    data[rear] = val;
    rear = (rear + 1) % capacity;
    size++;
}

/**
 * @brief Removes and returns the front value from the queue.
 * @return int The dequeued value.
 * @throws std::underflow_error If the queue is empty.
 */
int Queue::dequeue() {
    if (isEmpty()) {
        throw std::underflow_error("Queue underflow");
    }
    int val = data[front];
    front = (front + 1) % capacity;
    size--;
    return val;
}

/**
 * @brief Checks if the queue is empty.
 * @return true If the queue is empty.
 * @return false Otherwise.
 */
bool Queue::isEmpty() const {
    return size == 0;
}

/**
 * @brief Checks if the queue is full.
 * @return true If the queue is full.
 * @return false Otherwise.
 */
bool Queue::isFull() const {
    return size == capacity;
}

