#include <iostream>
#include <cmath>
using namespace std;
int main(){
  int input,result,lost;
  double num;
  cin >> input;
  num = sqrt(input * 2) + 0.5;
  result = static_cast<int>(num);
  lost = (result * (result + 1)) / 2 - input;
  if(lost == 0) {
    result++;
    lost = result;
  }
  cout << lost << " " << result;
  return 0;
}
