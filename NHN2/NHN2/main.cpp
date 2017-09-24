//
//  main.cpp
//  NHN2
//
//  Created by Macbook Pro on 2017. 9. 24..
//  Copyright © 2017년 Eric Park. All rights reserved.
//

#include <iostream>
#include <vector>
#include <sstream>

#define NUMBER_OF_ALPHABET 26

using namespace std;

string rotateString(string origin, int count);
char encryptChar(char origin, char secretKey);
char decryptChar(char origin, char secretKey);
string encryptString(string origin, string secretKey);
string decryptString(string origin, string secretKey);
int convertOrder(char c);


string rotateString(string origin, int count){
    int n = count;
    int pos = int(origin.size());
    string result;
    
    pos += n;
    n = n % origin.size();
    
    for (int i = 0; i < origin.size(); i++){
        int realPos = (pos + i) % origin.size();
        result.push_back(origin[realPos]);
    }
    
    return result;
}

string encryptString(string origin, string secretKey){
    string encrypted;
    
    for (int i = 0; i < origin.size(); i++){
        char c = encryptChar(origin[i], secretKey[i]);
        encrypted.push_back(c);
    }
    
    return encrypted;
}

string decryptString(string origin, string secretKey){
    string decrypted;
    
    for (int i = 0; i < origin.size(); i++){
        char c = decryptChar(origin[i], secretKey[i]);
        decrypted.push_back(c);
    }
    
    return decrypted;
}

char encryptChar(char origin, char secretKey){
    //cout << origin << " : " << (convertOrder(origin) + convertOrder(secretKey)) % NUMBER_OF_ALPHABET << endl;
    return ((convertOrder(origin) + convertOrder(secretKey)) % NUMBER_OF_ALPHABET) + 97;
}

char decryptChar(char origin, char secretKey){
    int c = convertOrder(origin) - convertOrder(secretKey);
    //cout << char(c) << " : " << c << endl;
    if (c < 0)
        c += NUMBER_OF_ALPHABET;
    return c + 97;
}

int convertOrder(char c){
    //cout << c << " : " << int(c) - 97 << endl;
    return int(c) - 97;
}

int main(int argc, const char * argv[]) {
    string secretType, secretWord, message;
    int rotateCount;
    
    cin >> secretType >> secretWord >> rotateCount >> message;
    
    string converted = message;
    
    if (secretType == "encrypt"){
        converted = encryptString(converted, secretWord);
        converted = rotateString(converted, rotateCount);
    } else if (secretType == "decrypt"){
        converted = rotateString(converted, -rotateCount);
        converted = decryptString(converted, secretWord);
    }
    
    cout << converted;
    
    cout << endl;
    return 0;
}
