#include <iostream>

using namespace std;


struct Node{
    int val;
    Node* next;
    Node* prev;
    Node(int x): val(x), next(NULL), prev(NULL) {}
};
Node* head = NULL , *tail = NULL;

void push_front(int x){
    Node* node = new Node(x);
    if(head==NULL){
        head = tail = node;
    }
    else{
        node -> next = head;
        head -> prev = node;
        head = node; // всегда обратно указываем назад
    }
}

void push_back(int x){
    Node* node = new Node(x);
    if(tail==NULL){
        head = tail = node;
    }
    else{
        tail -> next = node;
        node -> prev = tail;
        tail = node; // так же
    }
}

void pop_front() {
    if (head != NULL) {
        Node* temp = head;
        head = head->next;
        if (head != NULL) head->prev = NULL;
        else tail = NULL;
        delete temp;
    }
}

void pop_back() {
    if (tail != NULL) {
        Node* temp = tail;
        tail = tail->prev;
        if (tail != NULL) tail->next = NULL;
        else head = NULL;
        delete temp;
    }
}

void front(){
    if(head != NULL){
        cout << head -> val << endl;
    }
}

void back(){
    if(tail != NULL){
        cout << tail -> val << endl;
    }
}