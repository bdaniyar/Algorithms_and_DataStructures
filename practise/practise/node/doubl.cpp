#include <iostream>

using namespace std;

struct Node{
    int val;
    Node* next;
    Node* prev;
    Node(int x): val(x), next(NULL), prev(NULL) {}
};
Node* head = NULL , *tail = NULL;

int main(){
    int n; cin >> n;
    for(int i=0;i<n;i++){
        int x ; cin >> x;
        Node* node = new Node(x);
        if(head==NULL){
            head = tail = node;
        }
        else{
            tail -> next = node;
            node -> prev = tail;
            tail = node;
        }
    }
    int k, val;
    cin >> k >> val;
    Node* cur = head;
    while(cur != NULL){
        if(cur-> val == k){
            int x;
            Node* new_node = new Node(x);
            new_node -> next = cur -> next;
            new_node -> prev = cur ;
            if(cur -> next != NULL){
                cur -> next -> prev = new_node;
            }
            cur->next = new_node;

        }
        cur = cur -> next;
    }
}