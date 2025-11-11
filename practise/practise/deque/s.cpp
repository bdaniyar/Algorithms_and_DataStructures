#include <iostream>

using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int x): val(x), next(NULL){}
};

Node* head = NULL;

void push(int x){
    Node* node = new Node(x);
    if(head==NULL){
        head = node;
    }
    else{
        node -> next = head;
        head = node;
    }
}

void pop(){
    if(head!=NULL){
        Node* temp = head;
        head = head -> next;
        delete temp;
    }
}

int top(){
    if(head==NULL) return -1;
    return head -> val;
}

void print(){
    Node* cur = head;
    while( cur != NULL){
        cout << cur -> val << " ";
        cur = cur -> next;
    }
    cout << endl;
}