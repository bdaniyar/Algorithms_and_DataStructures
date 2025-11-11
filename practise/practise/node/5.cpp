#include <iostream>
#include <climits>
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
        int x;  cin >> x;
        Node* node = new Node(x);
        if(head == NULL){
            head = tail = node;
        }
        else{
            tail -> next = node;
            tail = node;
        }
    }
    Node* cur = head;
    int mx = INT_MIN;
    while(cur != NULL){
        if(cur -> val > mx){
            mx = cur -> val;
        }
        cur = cur -> next;
    }
    cout << mx << endl;

    return 0;
}