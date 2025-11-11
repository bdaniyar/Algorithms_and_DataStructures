#include <iostream>

using namespace std;

struct Node{
    int val;
    Node* next;

    Node(int x): val(x), next(NULL){}
};

Node * head = NULL, *tail = NULL;

void reverse(){
    Node* prev = NULL;
    Node* next = NULL;
    Node* cur = head;
    while(cur!=NULL){
        next = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
}

void reverse2(){
    Node* prev = NULL;
    Node* cur = head;
    Node* next = NULL;
    while(cur != NULL){
        next = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
}




void reverse3(){
    Node* prev = NULL;
    Node* cur = head;
    Node* next = NULL;

    while(cur!=NULL){
        next = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
}