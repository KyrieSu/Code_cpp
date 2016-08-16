#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
  int input,counter = 0;
  cin >> input;
  for(int i = 1 ;; i++){
    if(input < 0)
      break;
    input -= i;
    counter++;
  }
  cout << abs(input) << " " << counter;
  return 0;
}
