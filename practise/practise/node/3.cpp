#include <iostream>

using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int x): val(x), next(NULL){}
};
Node* head = NULL , *tail = NULL;
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
    int k; cin >> k;
    if(head != NULL && head -> val==k){
        Node* temp = head;
        head = head -> next;
        if(temp = tail) tail = NULL;
        delete temp;
    }
    else{
        Node* cur = head;
        while( cur -> next != NULL && cur -> next -> val != k){
            cur = cur -> next;
        }
        if(cur -> next !=NULL){
            Node* temp = cur -> next;
            cur -> next = cur -> next -> next;
            if(temp==tail) tail = cur;
            delete temp;
        }
    
    }
    Node* cur = head;
    while(cur!=NULL){
        cout << cur -> val << " ";
        cur = cur -> next;
    }
    return 0;
}