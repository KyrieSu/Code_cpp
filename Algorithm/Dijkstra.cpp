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
    cin >> start;
    int x,y,weight;
    while(cin >> x >> y >> weight){
        vec[x][y] = weight;
    }
    Dijkstra(vec,start);
    return 0;
}

void Dijkstra(Array2D& v,int start =0){
    int N = v.size();
    vector<int> dis(N,0);
    dis[start] = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<v[i].size();j++){
            if(v[i][j]==0){
                continue;
            }else{
                if(dis[j]==0){
                    dis[j] = v[i][j];
                }else{
                    if( (dis[j]+v[i][j])<dis[j] ){
                        dis[j] = dis[j]+v[i][j];
                    }
                }
            }
        }
    }
    for (int i=0;i<N;i++)
        cout << dis[i] <<endl;
}

/* 
test data 
5 0
0 1 6
0 2 7
1 3 5
1 2 8
2 4 9
3 1 -2
2 3 -3
4 3 7
4 0 2
*/