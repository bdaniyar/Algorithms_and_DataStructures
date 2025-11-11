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
        int x; cin >> x;
        Node* node = new Node(x);
        if(head==NULL){
            head = tail = node;
        }
        else{
            tail -> next = node;
            tail = node;
        }
    }
    int var, pos;
    cin >> var >> pos;
    Node* new_node = new Node(var);
    if(pos==0){
        new_node -> next = head;
        head = new_node;
    }
    else{
        int cnt = 0;
        Node* cur = head;
        while(cnt!=pos){
            cur = cur -> next;
        }
        new_node -> next = cur -> next; // new_node next = cur next 
        cur ->next = new_node; // cur next = new_node 
        // список: 3 -> 7 -> 9
        // вставить 100 в pos = 1
        // cur = [3]
        // new_node->next = [7]
        // cur->next = [100]
    }
    Node* cur = head;
    while( cur != NULL){
        cout << cur -> val << " ";
        cur = cur -> next;
    }

    return 0;
    
}
