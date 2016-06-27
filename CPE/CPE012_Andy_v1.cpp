// Example program
#include <iostream>
using namespace std;
int main()
{
    int input,i=1;
    cin >> input;
    while(input > 0){
        input -= i;
        i += 2;
    }
    if(input == 0)
        cout << "true";
    else
        cout << "false";
    return 0;
}
