#include <iostream>

using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int x): val(x), next(NULL){}
};

Node* head= NULL , *tail = NULL;

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
    int valu, num;
    cin >> valu >> num;
    Node* cur = head;
    while(cur != NULL){
        if(cur -> val == valu){
            Node* new_node = new Node(num);
            new_node -> next = cur -> next;
            cur -> next = new_node;
            if(cur == tail) {
                tail = new_node;
            }
            break;
        }
        cur = cur -> next;
    }
    cur = head;
    while(cur != NULL){
        cout << cur -> val << " ";
        cur = cur -> next;
    }

    return 0;
}