// File: PriorityQueue.cpp
// Author: galogimaymon@gmail.com
// Description: Implementation of a circular-array-based priority queue,
//              extending a basic queue with support for inserting by priority.

#include "PriorityQueue.hpp"
#include "Queue.hpp"
#include <stdexcept>

/**
 * @brief Constructs a priority queue with a given capacity.
 * @param capacity The maximum number of elements in the queue.
 */
PriorityQueue::PriorityQueue(int capacity) : Queue(capacity) {}

/**
 * @brief Enqueues a value to the end of the queue (regular FIFO).
 * @param val The value to enqueue.
 * @throws std::overflow_error if the queue is full.
 */
void PriorityQueue::enqueue(int val) {
    if (isFull()) {
        throw std::overflow_error("Queue overflow");
    }

    data[rear] = val;
    rear = (rear + 1) % capacity;
    size++;
}

/**
 * @brief Enqueues a value based on its priority (lower value = higher priority).
 *        Maintains sorted order within the circular array.
 *
 * @param val The value to enqueue.
 * @param priority The priority of the value.
 * @throws std::overflow_error if the queue is full.
 */
void PriorityQueue::enqueue(int val, int priority) {
    if (isFull()) {
        throw std::overflow_error("Queue overflow");
    }

    // Insert while maintaining priority order (lowest priority number first)
    int i = rear;
    while (i != front && data[(i - 1 + capacity) % capacity] > priority) {
        data[i] = data[(i - 1 + capacity) % capacity];
        i = (i - 1 + capacity) % capacity;
    }
    data[i] = val;
    rear = (rear + 1) % capacity;
    size++;
}

/**
 * @brief Removes and returns the front value from the queue.
 * @return int The dequeued value.
 * @throws std::underflow_error if the queue is empty.
 */
int PriorityQueue::dequeue() {
    if (isEmpty()) {
        throw std::underflow_error("Queue underflow");
    }

    int val = data[front];
    front = (front + 1) % capacity;
    size--;
    return val;
}
