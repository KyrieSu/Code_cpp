#include <iostream>
using namespace std;
int gcd(int x,int y){
  return y==0 ? x : gcd(y,x%y);
}
int main(){
  int x,y,z;
  cin >> x >> y >> z;
  int ans;
  ans = gcd(x,y);
  if(z % ans == 0)
    cout << "true";
  else
    cout << "false";
  return 0;
}
