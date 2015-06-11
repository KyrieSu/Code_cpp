#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
using namespace std ;

// use stack to do DFS
void DFS(int N, int start, vector<int> road[]){
	bool visited[N] ;
	memset(visited, false, N) ; // all unvisited
	stack<int> s ;
	s.push(start) ;
	visited[start] = true ;
	while(!s.empty()){
		start = s.top() ;
		s.pop() ;
		cout << start << " -> " ; 
		for(int i=0 ; i<road[start].size() ; i++){
			int dest = road[start][i] ;  // destination
			if(!visited[dest]){	// if unvisited
				s.push(dest) ;
				visited[dest] = true ;
			}
		}
	}
	cout << "FINISH " ;

	for(int i=0 ; i<N ; i++){  // check if all visited
		if(!visited[i]){
			cout << "(Not All Visited)" << endl ;
			return ;
		}
	}
	cout << "(All Visited)" << endl ;
}

// use queue to do BFS
void BFS(int N, int start, vector<int> road[]){
	bool visited[N] ;
	memset(visited, false, N) ; // all unvisited
	queue<int> q ;
	q.push(start) ;
	visited[start] = true ;
	while(!q.empty()){
		start = q.front() ;
		q.pop() ;
		cout << start << " -> " ; 
		for(int i=0 ; i<road[start].size() ; i++){
			int dest = road[start][i] ;  // destination
			if(!visited[dest]){	// if unvisited
				q.push(dest) ;
				visited[dest] = true ;
			}
		}
	}
	cout << "FINISH " ;

	for(int i=0 ; i<N ; i++){  // check if all visited
		if(!visited[i]){
			cout << "(Not All Visited)" << endl ;
			return ;
		}
	}
	cout << "(All Visited)" << endl ;
}

int main(){
	int N, start ;  // amount of dots && where to start
	cin >> N >> start ;
	vector<int> *road = new vector<int>[N] ;  // build graph
	int x, y ;
	while(cin >> x >> y){  // road from x to y
		road[y].push_back(x) ;	// no direction road 
		road[x].push_back(y) ;  // link x with y 
	}
	DFS(N, start, road) ;
	BFS(N, start, road) ;
}

/*

***** Sample Input && Output *****

9 3
0 4
2 5
7 5
3 7
0 1
2 2
2 4
4 4
4 7
8 5
7 5
5 2
0 7
7 5
8 8
4 7
6 3
0 1
4 4
8 7
3 4
0 6

3 -> 4 -> 2 -> 5 -> 8 -> 0 -> 1 -> 6 -> 7 -> FINISH (All Visited)
3 -> 7 -> 6 -> 4 -> 5 -> 0 -> 8 -> 2 -> 1 -> FINISH (All Visited)

***** Sample Input && Output *****

*/
