//
//  main.cpp
//  NHN
//
//  Created by Macbook Pro on 2017. 9. 23..
//  Copyright © 2017년 Eric Park. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <iterator>
#include <queue>

using namespace std;

#define MAX_ITEMS 3

int items[3];
int pos = 0;
list<int> myItems;
list<int> deletedItems;

void getItem(int item){
    // 가방이 꽉차지 않았으면
    if (myItems.size() < MAX_ITEMS){
        myItems.push_front(item);
    } else { // 꽉찼으면
        
        // 있는지 확인
        auto it = find(begin(myItems), end(myItems), item);
        // 있으면
        if (it != end(myItems)){
            myItems.erase(it);
        } else {
            // 없으면
            int d = *(--myItems.end());
            deletedItems.push_back(d);
            myItems.pop_back();
        }
        myItems.push_front(item);
    }
}

int main(int argc, const char * argv[]) {
    string line;
    vector<vector<int>> inputs;
    
    getline(cin, line);
    istringstream iss(line);
    inputs.push_back(vector<int>(istream_iterator<int>(iss),istream_iterator<int>()));
    
    for (auto iter = inputs.begin(); iter != inputs.end(); ++iter){
        for (auto iter2 = iter->begin(); iter2 != iter->end(); ++iter2){
            getItem(*iter2);
        }
    }
    
    if (deletedItems.size()){
        for (auto i = deletedItems.begin(); i != deletedItems.end(); i++){
            cout << *i << endl;
        }
    } else {
        cout << "0";
    }
    
    return 0;
}


