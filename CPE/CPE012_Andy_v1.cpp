// Example program
#include <iostream>
using namespace std;
int main()
{
    int input,i=1;
    cin >> input;
    while(input > 0){
        if(i%2 != 0)
            input -= i;
        i++;
    }
    if(input == 0)
        cout << "true";
    else
        cout << "false";
    return 0;
}
