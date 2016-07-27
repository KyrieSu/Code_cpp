#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;
void subY(vector<int> vec,int y,int z){
  int sub;
  for(int i=0;i<vec.size();i++){
    sub = abs(y-vec[i]);
    if(sub == z){
      cout << "true";
      break;
    }
    if(i == vec.size()-1)
      cout << "false";
  }
}
void subX(vector<int> vec,int x,int y,int z){
  int sub;
  vector<int>::iterator it;
  for(int i=0;i<vec.size();i++){
    sub = abs(x-vec[i]);
    if(sub == z){
      cout << "true";
      break;
    }
    else{
      it = find(vec.begin(),vec.end(),sub);
      if(it != vec.end()){
        subY(vec,y,z);
        break;
      }
      else
        vec.push_back(sub);
    }
  }
}
int main(){
  int x,y,z;
  cin >> x >> y >> z;
  if(z == x || z == y || z == 0)
    cout << "true\n";
  else{
    if(z > x && z > y)
      cout << "false\n";
    else{
      vector<int> vec;
      vec.push_back(abs(x-y));
      subX(vec,x,y,z);
    }
  }
  return 0;
}
