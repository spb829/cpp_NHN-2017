//
//  main.cpp
//  NHN3_2
//
//  Created by Macbook Pro on 2017. 10. 1..
//  Copyright © 2017년 Eric Park. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>

using namespace std;
int n;
vector<vector<char>> inputs;

void solution(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            char c = inputs[i][j];
            
            // if j > 0 then put a space
            if (j)
                cout << " ";
            // if '0' then print -1 and skip
            if (c == '0'){
                cout << "-1";
                continue;
            }
            
            // top left right bottom
            unsigned short binaryIndex = 0b00000000;
            
            // if there is an adjacent tile exists (left, bottom, right, top direction)
            if (i && inputs[i-1][j] == c)
                binaryIndex |= 0b0001;
            if (j && inputs[i][j-1] == c)
                binaryIndex |= 0b0010;
            if (j < n-1 && inputs[i][j+1] == c)
                binaryIndex |= 0b0100;
            if (i < n-1 && inputs[i+1][j] == c)
                binaryIndex |= 0b1000;
            
            // Figure out the index of tile using binary number and group character
            int value = int(binaryIndex) + (c - 'A') * 16;
            
            // put a space if value only has 1 length
            if (to_string(value).length() == 1)
                cout << " ";
            
            cout << value;
        }
        cout << endl;
    }
}

void inputData(){
    string line;
    
    // Get size of N
    getline(cin, line);
    n = stoi(line);
    
    // Init Input Texts (array of char)
    for (int i = 0; i < n; i++){
        getline(cin, line);
        istringstream iss(line);
        
        inputs.push_back(vector<char>(istream_iterator<char>(iss), istream_iterator<char>()));
    }
}

void printData(){
    int a = 0;
    cout << endl << "data :" << endl;
    for (auto i = inputs.begin(); i != inputs.end(); ++i){
        cout << a++ << " : " << endl;
        for (auto j = i->begin(); j != i->end(); ++j){
            cout << *j << "\t";
        }
        cout << endl;
    }
}

int main(int argc, const char * argv[]) {
    inputData();
    solution();
    return 0;
}

