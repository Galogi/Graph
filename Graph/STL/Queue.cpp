#include "Queue.hpp"
#include <stdexcept>

Queue::Queue(int capacity)
    : front(0), rear(0), size(0), capacity(capacity)
{
    data = new int[capacity];
}

Queue::~Queue() {
    delete[] data;
}

void Queue::enqueue(int val) {
    if (size == capacity) {
        throw std::overflow_error("Queue overflow");
    }
    data[rear] = val;
    rear = (rear + 1) % capacity;
    size++;
}

int Queue::dequeue() {
    if (isEmpty()) {
        throw std::underflow_error("Queue underflow");
    }
    int val = data[front];
    front = (front + 1) % capacity;
    size--;
    return val;
}

bool Queue::isEmpty() const {
    return size == 0;
}
bool Queue::isFull() const {
    return size == capacity;  
}
