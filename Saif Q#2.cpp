//
//  main.cpp
//  Q#1
//
//  Created by Afaq Ahmed on 18/08/2020.
//  Copyright © 2020 Afaq Ahmed. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

class EncryptableString: public string {
public:
    EncryptableString();
    EncryptableString(string str);
    void encrypt();
    string getEncryptedString();
};

EncryptableString::EncryptableString ()
:string{""} { }

EncryptableString::EncryptableString(string str)
:string{str} { }

void EncryptableString::encrypt() {
    int i = 0;
    while (i < this->length()) {
        if (this->at(i) >= 'a' && this->at(i) <= 'z') {
            if (this->at(i) == 'z') {
                this->at(i) = 97;
            }else{
                this->at(i) = this->at(i) + 1;
            }
        }else if (this->at(i) >= 'A' && this->at(i) <= 'Z') {
            if (this->at(i) == 'z') {
                this->at(i) = 65;
            }else{
                this->at(i) = this->at(i) + 1;
            }
        }
        i++;
    }
    
}

string EncryptableString::getEncryptedString() {
    return *this;
}

int main() {
    
    string str;
    
    cout << "Enter string: "; cin >> str;
    EncryptableString str1{str};
    str1.encrypt();
    cout << "Encrypted string: " << str1.getEncryptedString() << endl;
    
    
    return 0;
}
