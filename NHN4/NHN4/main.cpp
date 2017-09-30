//
//  main.cpp
//  NHN4
//
//  Created by Macbook Pro on 2017. 9. 29..
//  Copyright © 2017년 Eric Park. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <sstream>
#include <algorithm>

using namespace std;

typedef int inputType;

vector<vector<inputType>> inputs;
int n;
vector<int> sector;
bool** is_checked;

int findSector(int i, int j){
    int count = 1;
    is_checked[i][j] = true;
    
    // Right
    if (j < n - 1 && inputs[i][j + 1] && !is_checked[i][j + 1])
        count += findSector(i, j + 1);
    
    // Bottom
    if (i < n - 1 && inputs[i + 1][j] && !is_checked[i + 1][j])
        count += findSector(i + 1, j);
    
    // Left
    if (j > 0 && inputs[i][j - 1] && !is_checked[i][j - 1])
        count += findSector(i, j - 1);
    
    // Top
    if (i > 0 && inputs[i - 1][j] && !is_checked[i - 1][j])
        count += findSector(i - 1, j);
    
    return count;
}

void solution(){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            if (is_checked[i][j])
                continue;
            if (!inputs[i][j]){
                is_checked[i][j] = true;
                continue;
            }
            sector.push_back(findSector(i, j));
        }
    
    sort(sector.begin(), sector.end());
    
    cout << sector.size() << endl;
    for (auto it = sector.begin(); it != sector.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

void inputData(){
    string line;
    
    // Get size of N
    getline(cin, line);
    n = stoi(line);
    
    // Init Input Texts (array of inputType)
    for (int i = 0; i < n; i++){
        getline(cin, line);
        istringstream iss(line);
        
        inputs.push_back(vector<inputType>(istream_iterator<inputType>(iss), istream_iterator<inputType>()));
    }
    
    is_checked = (bool**)calloc(sizeof(bool*), n);
    for (int i = 0; i < n; i++)
        is_checked[i] = (bool*)calloc(sizeof(bool), n);
}

int main(int argc, const char * argv[]) {
    inputData();
    solution();
    return 0;
}
