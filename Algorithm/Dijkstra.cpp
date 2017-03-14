/* Ref by https://zh.wikipedia.org/wiki/戴克斯特拉算法 */
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
    start -= 1;
    int x,y,weight;
    while(cin >> x >> y >> weight){
        vec[x-1][y-1] = weight;
        vec[y-1][x-1] = weight;
    }
    Dijkstra(vec,start);
    return 0;
}

void Dijkstra(Array2D& v,int start=0){
    int N = v.size();
    vector<int> dis(N,10000);
    vector<bool> dot(N,false);
    queue<int> q;
    // initial algorithm status
    q.push(start);
    dot[start] = true;
    dis[start] = 0;
    // start travel by BFS
    int index;
    while(!q.empty()){
        index = q.front();
        cout << index << endl;
        q.pop();
        for(int i=0;i<v[index].size();i++){
            if(v[index][i]==0)continue;
            if(dot[i]==false){
                q.push(i);
                dot[i] = true;
                dis[i] = dis[index] + v[index][i];
            }else{ //check which path is shorter
                int tmp = dis[index] + v[index][i];
                if(dis[i]>tmp){
                    dis[i] = tmp;
                }
            }
        }
    }
    for (int i=0;i<N;i++)
        cout << dis[i] << ' ' ;
}

/* test data 
6 3
1 2 7
1 3 9
1 6 14
2 3 10
2 4 15
3 4 11
3 6 2
5 6 9
4 5 6
*/