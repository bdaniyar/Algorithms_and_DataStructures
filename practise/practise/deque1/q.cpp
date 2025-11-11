#include <iostream>

using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int x): val(x), next(NULL){}
};

Node* head = NULL, *tail = NULL;
int sz = 0;

void push(int x){
    Node* node = new Node(x);
    if(head==NULL){
        head = tail = node;
    }
    else{
        tail -> next = node;
        tail = node;
    }
    sz++;
}

void pop(){
    if(head !=NULL){
        Node* temp = head;
        head = head -> next;
        if(head==NULL) tail = NULL;
        delete temp;
    }
    sz--;
}

int front(){
    if(head==NULL) return -1;
    return head -> val;
}

int size(){
    return sz;
}

bool empty(){
    return(sz==0);
}

void print(){
    Node* cur = head;
    while( cur != NULL){
        cout << cur -> val << " ";
        cur = cur -> next;
    }
    cout << endl;
}