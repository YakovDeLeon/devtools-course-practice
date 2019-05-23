// Copyright 2019 Andronov Maxim

#include "include/priority_queue.h"

PriorityQueue::Link * PriorityQueue::Create(int prior, int val) {
    Link *tmp = new Link;

    tmp->priority = prior;
    tmp->value = val;
    tmp->next = nullptr;

    return tmp;
}

PriorityQueue::PriorityQueue() {
    first = last = nullptr;
}

PriorityQueue::~PriorityQueue() {
    while (first != nullptr) {
        Link *tmp = first;
        first = first->next;
        delete tmp;
    }
}

void PriorityQueue::Push(int prior, int val) {
    Link *element = Create(prior, val);
    if (Empty()) {
        first = last = element;
    } else if (first->priority >= prior) {
        element->next = first;
        first = element;
    } else if (last->priority < prior) {
        last->next = element;
        last = element;
    } else {
        Link *tmp = first;
        while ( (tmp->next != nullptr) && (tmp->next->priority < prior))
            tmp = tmp->next;
        element->next = tmp->next;
        tmp->next = element;
    }
}

void PriorityQueue::Pop() {
    if (Empty())
        throw "No elements";
    if (first == last) {
        delete last;
        first = last = nullptr;
    } else {
        Link *tmp = first;
        while (tmp->next != last)
            tmp = tmp->next;
        delete last;
        last = tmp;
        last->next = nullptr;
    }
}

int PriorityQueue::Top() {
    if (Empty())
        throw "No elements";
    return last->value;
}

bool PriorityQueue::Empty() {
    return first == nullptr;
}

int PriorityQueue::Size() {
    Link *tmp = first;
    int count = 0;
    while (tmp != nullptr) {
        count++;
        tmp = tmp->next;
    }
    return count;
}
