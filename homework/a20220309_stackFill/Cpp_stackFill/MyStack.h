//
// Created by Arnold on 2022/3/14.
//

#ifndef CPP_STACKFILL_MYSTACK_H
#define CPP_STACKFILL_MYSTACK_H

#include <iostream>
#include <windows.h>

using namespace std;

template<class T>class MyStack {
public:
    struct Node {
        T data;
        Node* next = nullptr;
    };

    Node *head;
    Node *topNode;
    int length;

    MyStack() {
        head = NULL;
        length = 0;
    }

    void push(T n) {
        Node* temp = new Node;
        temp->data = n;

        if (head == NULL) {
            temp->next = head;
            head = temp;
            topNode = temp;
        } else {
            temp->next = topNode;
            topNode = temp;
        }

        length++;
    }

    T pop() {
        if (length <= 0) {
            abort();
        }

        Node* q = topNode;
        T data = topNode->data;
        topNode = topNode->next;
        delete(q);
        length--;

        return data;
    }

    int size() {
        return length;
    }

    T top() {
        return topNode->data;
    }

    bool isEmpty() {
        if (length == 0) {
            return true;
        } else {
            return false;
        }
    }

    void clear() {
        while (length) {
            pop();
        }
    }
};


#endif //CPP_STACKFILL_MYSTACK_H
