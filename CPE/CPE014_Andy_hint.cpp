#include <iostream>
#include <vector>
using namespace std;
void sol(int input,vector<int> vec){
  if(input == 0){
    for(int i = vec.size() - 1 ; i >= 0 ; i--)
      cout << vec[i];
  }
  else{
    vec.push_back(input);
    return sol(input-1,vec);
  }

}
int main(){
  int input;
  vector<int> vec;
  cin >> input;
  sol(input,vec);
  return 0;
}
