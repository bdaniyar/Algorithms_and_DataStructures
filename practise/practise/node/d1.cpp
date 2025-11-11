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
        node -> next = head; // нодадан кейын хед значение
        head = node; // хед теперь нода
    }
}

void pop(){
    if(head!=NULL){
        Node* temp = head;
        head = temp -> next;
        delete temp;
    }
}
void top(){
    if(head!=NULL){
        cout << head -> val << endl;
    }
}