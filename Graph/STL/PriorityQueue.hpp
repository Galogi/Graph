#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

#include "Queue.hpp"

class PriorityQueue : public Queue {
public:
    PriorityQueue(int capacity);

   
    void enqueue(int val) override;

    
    void enqueue(int val, int priority);

    int dequeue() override;
};

#endif
