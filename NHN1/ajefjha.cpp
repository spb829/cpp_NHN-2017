//
//  ajefjha.cpp
//  NHN
//
//  Created by Macbook Pro on 2017. 9. 23..
//  Copyright © 2017년 Eric Park. All rights reserved.
//

#include "ajefjha.hpp"
//
//  main.cpp
//  NHN2
//
//  Created by Sohn on 23/09/2017.
//  Copyright © 2017 Sohn. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

string rotateLeft(string text, int count) {
    queue<char> q;
    
    for(int i = 0; i < text.length(); i++) {
        q.push(text[i]);
    }
    
    for(int i = 0; i < count; i++) {
        char c = q.front();
        q.pop();
        q.push(c);
    }
    
    string result = "";
    
    int qSize = int(q.size());
    
    for(int i = 0; i < qSize; i++) {
        char c = q.front();
        result = result + c;
        q.pop();
    }
    
    return result;
}

string rotateRight(string text, int count) {
    queue<char> q;
    
    for(int i = 0; i < text.length(); i++) {
        q.push(text[i]);
    }
    
    int realcount = count % text.length();
    int count2 = int(text.length()) - realcount;
    
    for(int i = 0; i < count2; i++) {
        char c = q.front();
        q.pop();
        q.push(c);
    }
    
    string result = "";
    
    int qSize = int(q.size());
    
    for(int i = 0; i < qSize; i++) {
        char c = q.front();
        result = result + c;
        q.pop();
    }
    
    return result;
}

char encryptChar(char c, char key) {
    int n = c - 'a';
    
    n += (key-'a');
    n = n % 26;
    char result = n + 'a';
    
    return result;
}

char decryptChar(char c, char key) {
    int n = c - 'a';
    n -= (key-'a');
    
    if(n < 0) {
        n += 26;
    }
    
    n = n % 26;
    char result = n + 'a';
    
    return result;
}

string encrypt(string secretKey, string text, int count) {
    int secretKeySize = int(secretKey.size()) - 1;
    
    string result = "";
    
    for(int i = 0; i < text.size(); i++) {
        char c = text[i];
        
        result = result + encryptChar(c, secretKey[i % secretKeySize]);
    }
    
    result = rotateLeft(result, count);
    
    return result;
}

string decrypt(string secretKey, string secretText, int Count) {
    int secretKeySize = int(secretKey.size());
    
    string result = "";
    
    result = rotateRight(secretText, count);
    
    for(int i = 0; i < result.size(); i++) {
        char c = result[i];
        
        result[i] = decryptChar(c, secretKey[i % secretKeySize]);
    }
    
    return result;
}

int main(int argc, const char * argv[]) {
    string type;
    string secretKey;
    int count;
    string text;
    
    cin >> type >> secretKey >> count >> text;
    
    string result;
    
    if(type == "encrypt") {
        result = encrypt(secretKey, text, count);
    } else {
        result = decrypt(secretKey, text, count);
    }
    
    cout << result;
    
    return 0;
}
