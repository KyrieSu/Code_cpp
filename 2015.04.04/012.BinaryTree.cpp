#include<iostream>
#include<cstdlib>
#include<ctime>
#include<stack>
#include<queue>
using namespace std ;

struct Node{
	int data ;
	Node *left ;
	Node *right ;
} ;

// O(log(n))
Node* add(Node *tree, int val){
	if(!tree){
		Node *tmp = new Node ;
		tmp -> data = val ;
		tmp -> left = NULL ;
		tmp -> right = NULL ;
		return tmp ;
	}
	if(val < tree -> data)	
		tree -> left = add(tree -> left, val) ;
	else	
		tree -> right = add(tree -> right, val) ;
	return tree ;
}

// level-order trversal
// O(n)
void bfs(Node *root){
	queue<Node*> q ;
	q.push(root) ;
	while(!q.empty()){
		Node *p = q.front() ;
		cout << p -> data << " " ;
		q.pop() ;
		if(p -> left)	q.push(p -> left) ;
		if(p -> right)	q.push(p -> right) ;
	}
	cout << endl ;
}

// DFS
// O(n)
void dfs(Node *root){
	stack<Node*> s ;
	s.push(root) ;
	while(!s.empty()){
		Node *p = s.top() ;
		cout << p -> data << " " ;
		s.pop() ;
		if(p -> left)	s.push(p -> left) ;
		if(p -> right)	s.push(p -> right) ;
	}
	cout << endl ;
}

// O(n)
void inorder(Node *root){  // from small to big
	if(root -> left)	inorder(root -> left) ;
	cout << root -> data << " " ;
	if(root -> right)	inorder(root -> right) ;
}

int main(){
	Node *myTree = NULL ;

	srand(time(0)) ;
	for(int i=0 ; i<10 ; i++)
		myTree = add(myTree, rand() % 100) ;
	
	inorder(myTree) ;	cout << endl ;
	dfs(myTree) ;
	bfs(myTree) ;
}


