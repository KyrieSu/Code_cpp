#include <iostream>
#include <cmath>
using namespace std;
int main(){
  int input,result,lost;
  double num;
  cin >> input;
  num = sqrt(input * 2);
  if(num - floor(num) >= 0.5)
    num++;
  result = int(num);
  lost = (result * (result + 1)) / 2 - input;
  if(lost == 0) {
    result++;
    lost = result;
  }
  cout << lost << " " << result;
  return 0;
}
