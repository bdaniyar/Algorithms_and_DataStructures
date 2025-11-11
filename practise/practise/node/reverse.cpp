#include <iostream>

using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int x): val(x), next(NULL){}
};

Node* head = NULL;

void reverse(){
    Node* prev = NULL;
    Node* cur = head;
    Node* next = NULL;
    //Создаются три указателя:
	//•	prev — будет хранить предыдущий узел (изначально NULL, так как у новой головы не будет следующего).
	//•	cur — текущий узел, с которого идёт обход.
	//•	next — временно хранит адрес следующего узла, чтобы не потерять цепочку.
    while(cur != NULL){
        next = cur -> next;
        cur -> next = prev;
        prev =  cur;
        cur = next;
    }
    head = prev;
}


