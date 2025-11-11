#include <iostream>
//FIFO 
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int x): val(x), next(NULL){}
};
Node* head = NULL, *tail = NULL;

void enqueue(int x){
    Node* node = new Node(x);
    if(head==NULL){
        head = tail = node;
    }
    else{
        tail -> next = node;
        tail = node;
    }
}

void dequeue(){
    if(head!=NULL){
        Node* temp = head;
        head = head -> next;
        if(head==NULL){
            tail = NULL;
        }
        delete temp;
    }
}

int front(){
    if(head==NULL){
        return -1;
    }
    return head -> val;
}

void print(){
    Node* cur = head;
    while(cur != NULL){
        cout << cur -> val << " ";
        cur = cur -> next;
    }
    cout << endl;
}