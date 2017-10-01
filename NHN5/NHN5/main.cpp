//
//  main.cpp
//  NHN5
//
//  Created by Macbook Pro on 2017. 9. 30..
//  Copyright © 2017년 Eric Park. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <sstream>
#include <algorithm>


using namespace std;

typedef string inputType;

class Person {
public:
    vector<inputType> info;
    
    Person()=default;
    friend ostream& operator<<(ostream& out, const Person& person);
};

inline ostream& operator<<(ostream& out, const Person& person){
    if (person.info.size() == 3)
        return out << person.info[0] << " " << person.info[1] << " " << person.info[2];
    return out << person.info[0] << " " << person.info[1];
}

vector<vector<inputType>> inputs;
vector<Person> people;
int n;
int priority[3];

bool sortPerson(Person p1, Person p2){
    // Get age of person
    int p1a = stoi(p1.info[1]);
    int p2a = stoi(p2.info[1]);
    
    string p1c = "", p2c = "";
    if (p1.info.size() == 3)
        p1c = p1.info[2];
    if (p2.info.size() == 3)
        p2c = p2.info[2];
    
    for (int i = 0; i < n; i++){
        switch (priority[i]) {
                // Codition 1
            case 1:
                if (p1.info[0] != p2.info[1]){
                    if (p1.info[0] == "F")
                        return true;
                    else
                        return false;
                }
                break;
                // Condition 2
            case 2:
                // Person1 is a Child
                if (p1a <= 7){
                    // Person2 is also a Child
                    if (p2a <= 7)
                        return p1a < p2a;
                    // Person2 isn't a Child
                    else
                        return true;
                } else if (p2a <= 7)
                    // Only Person2 is Child
                    return false;
                
                // Both aren't Children
                if (p1a != p2a)
                    return p1a > p2a;
                break;
                // Condition 3
            case 3:
                if (p1c == p2c)
                    break;
                // PW DP P
                if (p1c == "PW"){
                    return true;
                } else if (p1c == "DP") {
                    if (p2c == "PW")
                        return false;
                    return true;
                } else if (p1c == "P") {
                    if (p2c == "")
                        return true;
                    return false;
                }
                return false;
                break;
            default:
                break;
        }
    }
    return true;
}

void sortPeople(){
    sort(people.begin(),people.end(), [](const Person& p1, const Person& p2){
        return sortPerson(p1, p2);
    });
}

void inputData(){
    string line;
    
    // Get Priorities
    for (int i = 0; i < 3; i++)
        cin >> priority[i];
    
    // Get size of N
    cin >> n;
    
    // Skip Newline after cin >> n;
    getline(cin, line);
    
    // Init Input Texts (array of inputType)
    for (int i = 0; i < n; i++){
        getline(cin, line);
        istringstream iss(line);
        
        inputs.push_back(vector<inputType>(istream_iterator<inputType>(iss), istream_iterator<inputType>()));
    }
    
    for (int i = 0; i < n; i++){
        Person p = Person();
        for (auto it = inputs[i].begin(); it != inputs[i].end(); ++it)
            p.info.push_back(*it);
        
        people.push_back(p);
    }
}

void solution(){
    sortPeople();
    
    for (auto i = people.begin(); i != people.end(); ++i){
        cout << *i << endl;
    }
    cout << endl;
}

void printData(){
    int a = 0;
    cout << endl << "data :" << endl;
    for (auto i = people.begin(); i != people.end(); ++i){
        cout << a++ << " : " << endl;
        for (auto j = i->info.begin(); j != i->info.end(); ++j){
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
