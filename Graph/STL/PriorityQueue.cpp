#include "PriorityQueue.hpp"
#include "Queue.hpp"
#include <stdexcept>

PriorityQueue::PriorityQueue(int capacity) : Queue(capacity) {}

void PriorityQueue::enqueue(int val) {
    if (isFull()) {
        throw std::overflow_error("Queue overflow");
    }

    
    data[rear] = val;
    rear = (rear + 1) % capacity;
    size++;
}

void PriorityQueue::enqueue(int val, int priority) {
    if (isFull()) {
        throw std::overflow_error("Queue overflow");
    }

    
    int i = rear;
    while (i != front && data[(i - 1 + capacity) % capacity] > priority) {
        data[i] = data[(i - 1 + capacity) % capacity];
        i = (i - 1 + capacity) % capacity;
    }
    data[i] = val;
    rear = (rear + 1) % capacity;
    size++;
}

int PriorityQueue::dequeue() {
    if (isEmpty()) {
        throw std::underflow_error("Queue underflow");
    }

    
    int val = data[front];  
    front = (front + 1) % capacity;
    size--;
    return val;
}
