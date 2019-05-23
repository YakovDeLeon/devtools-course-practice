// Copyright 2019 Andronov Maxim

#ifndef MODULES_PRIORITY_QUEUE_INCLUDE_PRIORITY_QUEUE_H_
#define MODULES_PRIORITY_QUEUE_INCLUDE_PRIORITY_QUEUE_H_

class PriorityQueue {
 private:
    struct Link {
        int priority;
        int value;
        Link *next;
    };
    Link *first, *last;
    Link *Create(int prior, int val);
 public:
    PriorityQueue();
    ~PriorityQueue();
    void Push(int prior, int val);
    void Pop();
    int Top();
    bool Empty();
    int Size();
};

#endif  // MODULES_PRIORITY_QUEUE_INCLUDE_PRIORITY_QUEUE_H_
