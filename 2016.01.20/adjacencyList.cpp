#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void DFS(vector<int> graph, int start, int N){
	stack<int> s;
	bool visited[N];
	s.push(start);
	while(!s.empty()){
		start = s.top();
		s.pop();
		for(int i=0 ; i<graph[start].size() ; i++){
			if(!visited[start][i]){
				s.push(graph[start][i]);
				visited[graph[start][i]] = true;
			}
		}
	}
}

int main(){
	int N, M;		// N = amount of vertex, M = amount of edge
	cin >> N >> M;

	vector<int> graph[N+1];
	for(int i=0 ; i<M ; i++){
		int start, end;
		cin >> start >> end;
		graph[start].push_back(end);
		// graph[end].push_back(start);
	}

}
