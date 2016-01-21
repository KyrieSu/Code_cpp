#include <iostream>
#include <cstring>
#include <utility>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

typedef vector<pair<int,int> > Graph;

//int set[100];
void BFS(int,Graph*,int);
void DFS(int,Graph*,int);

int main(){
    int N; // amount of dots
    cin >> N;
    /*for(int i=0;i<N;i++)
        set[i]=i;*/
    Graph *G = new Graph [N]; // weight , vertex
    int begin,end,weight;
    while(cin>>begin>>end>>weight)
        G[begin].push_back(make_pair(weight,end));
    cout << "The BFS spanning tree is " ; BFS(N,G,0);
    cout << "The DFS spanning tree is " ; DFS(N,G,0);
    delete [] G ;
    return 0;
}

void BFS(int num,Graph *G,int start){
    bool visited[num];
    memset(visited,false,num);
    visited[start]=true;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        start = q.front();
        cout << start << " -> ";
        q.pop();
        for(int i=0;i<G[start].size();i++){
            int dot = G[start][i].second;
            if(visited[dot]==false){
                q.push(dot);
                visited[dot] = true;
            }
        }
    }
    cout << "Finish !! ";
    for(int i=0;i<num;i++)
        if(visited[i]==false){
            cout << "( Not all visited )" <<endl;
            return;
        }
    cout << "( All visited )" << endl;
}

void DFS(int num,Graph *G,int start){
    bool visited[num];
    memset(visited,false,num);
    visited[start]=true;
    stack<int> s;
    s.push(start);
    while(!s.empty()){
        start = s.top();
        cout << start << " -> ";
        s.pop();
        for(int i=0;i<G[start].size();i++){
            int dot = G[start][i].second;
            if(visited[dot]==false){
                s.push(dot);
                visited[dot]=true;
            }
        }
    }
    cout << "Finish !! ";
    for(int i=0;i<num;i++)
        if(visited[i]==false){
            cout << "( Not all visited )" <<endl;
            return;
        }
    cout << "( All visited )" << endl;
}
