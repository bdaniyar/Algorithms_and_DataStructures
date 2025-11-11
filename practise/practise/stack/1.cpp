#include <iostream>
using namespace std;

// Last in , First out

class Stack {
    int* arr;
    int capacity;
    int topIndex;

public:
    Stack(int size = 100) {
        capacity = size;
        arr = new int[capacity];
        topIndex = -1; // стек изначально пуст
    }

    ~Stack() { delete[] arr; }

    void push(int x) {
        if (topIndex + 1 == capacity) {
            cout << "Stack overflow!\n";
            return;
        }
        arr[++topIndex] = x;
    }

    void pop() {
        if (empty()) {
            cout << "Stack underflow!\n";
            return;
        }
        topIndex--;
    }

    int top() {
        if (empty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return arr[topIndex];
    }

    bool empty() { return topIndex == -1; }
};