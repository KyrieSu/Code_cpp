#include <iostream>
using namespace std;
int main(){
  int input;
  cin >> input;
  int n = 0x55555555;
  if(!(input&(input-1)) && input&n)
    cout << "true";
  else
    cout << "false";
  return 0;
}
