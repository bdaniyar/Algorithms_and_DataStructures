#include <iostream>

using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int x): val(x), next(NULL){}
};
Node* head = NULL, *tail = NULL;

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
    int cnt = 0;
    Node* cur = head;
    while(cur != NULL){
        cnt += cur -> val;
        cur = cur -> next;
    }
    cout << cnt << endl;

    return 0;
}