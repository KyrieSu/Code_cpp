#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

string alphas[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int char2Int(char ch){
    // '2' -> 2
    return ch - '0';
}

void _numToArr(string input, vector<string> currentArr){
    if(input.size() == 0){
        // output all nowArr string
        cout << "[";
        for(int i=0 ; i<currentArr.size() ; i++){
            if(i != 0)
                cout << ", ";
            cout << "\"" + currentArr[i] + "\"";
        }
        cout << "]\n";
        return;
    }
    // process the first char in input
    int index = char2Int(input[0]);
    vector<string> newArr;
    // use currentArr to make newArr
    for(int i=0 ; i<currentArr.size() ; i++){
        string currentStr = currentArr[i];
        for(int j=0 ; j<alphas[index].size() ; j++){
            string newStr = currentStr + alphas[index][j]; 
            newArr.push_back(newStr);
        }
    }
    // input[0] process finish
    // newInput = input[1..end]
    string newInput(input.begin() + 1, input.end());
    _numToArr(newInput, newArr);
}

void numToArr(string input){
    vector<string> vec;
    vec.push_back("");
    // make a empty vector
    _numToArr(input, vec);
}

int main(){
    string input;
    cin >> input;
    numToArr(input);
}

