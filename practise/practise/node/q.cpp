#include <iostream>

using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int x): val(x), next(NULL){}
};
Node* head = NULL , *tail = NULL;

void enqueue(int x){
    Node* node = new Node(x);
    if(head == NULL){
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
        delete temp;
    }
}
void front(){
   if(head!=NULL){
        cout << head -> val << endl;
   }
}