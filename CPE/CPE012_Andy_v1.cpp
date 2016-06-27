// Example program
#include <iostream>
using namespace std;
int main()
{
    int input;
    cin >> input;
    for(int i = 1 ; input > 0 ; i+=2)
		input -= i;
    if(input == 0)
        cout << "true";
    else
        cout << "false";
    return 0;
}
