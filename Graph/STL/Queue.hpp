#ifndef QUEUE_H
#define QUEUE_H

class Queue {
protected:
    int* data;
    int front;
    int rear;
    int size;
    int capacity;

public:
    Queue(int capacity);
    virtual ~Queue();

    virtual void enqueue(int val);
    virtual int dequeue();
    bool isEmpty() const;
    bool isFull() const;
};

#endif
