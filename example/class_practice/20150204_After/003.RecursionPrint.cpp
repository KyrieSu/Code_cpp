#include<iostream>
using namespace std ;
using namespace twoD ;

struct Node{
	int data ;
	Node *next ;
} ;

void print(Node *head){
    if(head == NULL)
        return ;
    print(head -> next) ;
    cout << head->data ;
}

Node* set(){
	Node *a = new Node ;
	Node *b = new Node ;
	Node *c = new Node ;
	Node *d = new Node ;

	a -> data = 1 ;
	b -> data = 2 ;
	c -> data = 3 ;
	d -> data = 4 ;

	a -> next = b ;
	b -> next = c ;
	c -> next = d ;
	d -> next = NULL ;

	return a ;
}

int main(){
	Node *head = set() ;
	print(head) ;

	return 0 ;
}
