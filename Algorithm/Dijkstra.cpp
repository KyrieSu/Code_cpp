#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef vector<vector<int> > Array2D;
void Dijkstra(Array2D&,int);

int main(){
    int N; //number of dots
    cin >> N;
    Array2D vec(N);
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<N;j++){
            vec[i].push_back(0);
        }
    }
    int start;
    cout << "Enter start : " ; 
    cin >> start;
    int x,y,weight;
    while(cin >> x >> y >> weight){
        vec[x][y] = weight;
        vec[y][x] = weight;
    }
    Dijkstra(vec,start);
    return 0;
}

void Dijkstra(Array2D& v,int start =0){
    int N = v.size();
    vector<int> dis(N,-1);
    vector<bool> dot(N,false);
}