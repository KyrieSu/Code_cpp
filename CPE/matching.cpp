#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef vector<vector<int> > Array2D;
int caldet(Array2D&,int);
Array2D getMinimo(Array2D&,int,int,int);


int main(){
    int timer , V , E;
    cin >> timer;
    while(timer--){
        cin >> V >> E; // V is even number
        Array2D vec(V/2);
        for(int i=0;i<vec.size();i++){
            for(int j=0;j<(V/2);j++)
                vec[i].push_back(0);
        }
        while(E--){
            int v1,v2;
            cin >> v1 >> v2;
            vec[v1-1][v2-V/2-1]=1;
        }
        int num = caldet(vec,V/2);
        if(num%2==0){ //even
            cout << "1" << endl;
        }else{
            cout << "0" << endl;
        }
    }
    return 0;
}

Array2D getMinimo(Array2D& src, int I, int J, int ordSrc ) {
  // Compute and return the minimum of the element I J
  // If the element is not in the Ith row or Jth column it will get copied to the minimum matrix
  Array2D minimo( ordSrc-1, vector<int> (ordSrc-1,0));

  int rowCont = 0;
  for( int i=0; i < ordSrc; i++)
  {
    int colCont = 0;
    if ( i != I ) { 

      for ( int j=0; j < ordSrc; j++)
      { 
        if ( j != J ) { 
          minimo[rowCont][colCont] = src[i][j];
          colCont++; }
      };

      rowCont++; }
  };
  return minimo;
}

int caldet(Array2D& src,int order){
    if ( order == 2 ) {
        return src[0][0]*src[1][1] - src[1][0]*src[0][1]; 
    }else{
        int det = 0;
        for( int j = 0; j < order; j++) {
            Array2D min = getMinimo( src, 0, j, order);
            if ( (j % 2) == 0 ) { 
                det += src[0][j] * caldet( min, order-1); 
            }else{ 
                det -= src[0][j] * caldet(min, order-1); 
            }
        }
        return det;
    }
}
