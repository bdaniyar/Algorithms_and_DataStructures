#include <iostream>

using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int x): val(x), next(NULL){}
};

Node * head = NULL, *tail = NULL;
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
            tail = node;
        }
    }
    int k; cin >> k;
    Node* new_node = new Node(k);
    tail -> next = new_node;
    tail = new_node;

    Node* cur = head;
    while(cur != NULL){
        cout << cur -> val << " ";
        cur = cur -> next;        
    }
    return 0;
}