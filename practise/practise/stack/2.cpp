#include <iostream>

using namespace std;

class Stack{
    int* arr;
    int capacity;
    int topIndex;

public:
    Stack(int size = 100){
        capacity = size;
        arr = new int[capacity];
        topIndex = -1;
    }

    ~Stack() {delete[] arr;}

    void push(int x){
        if(topIndex + 1 == capacity){
            cout << "Stack overflow";
            return; // выход
        }
        arr[++topIndex] = x;
    }
    void pop(){
        if(empty()){
            cout << "Stack underflow";
            return; // выход
        }
        topIndex--;
    }
    int top(){
        if(empty()){
            cout << "Stack is empty";
            return -1; 
        }
        return arr[topIndex];
    }

    bool empty(){
        return topIndex == -1;
    }
    bool full(){
        return (topIndex+1 == capacity);
    }
    // Stack st(3);
    // st.push(10);
    // st.push(20);
    // st.push(30);

    // if (st.full()) {
    //     cout << "Стек заполнен!" << endl;
    // }
    

};