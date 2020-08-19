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

class Pstring: public string {
public:
    Pstring();
    Pstring(string str);
    bool isPalindrome();
};

Pstring::Pstring ()
:string{""} { }

Pstring::Pstring(string str)
:string{str} { }

bool Pstring::isPalindrome() {
     int start = 0, end = this->length() - 1;

//     for (int i = 0; i < end; i++)
//         this[i] = tolower(this[i]);

     while (start <= end) {

     //checking from the left side of the sentence
         if (!(this->at(start) >= 'a' && this->at(start) <= 'z'))
             start++;

     //checking from the right side of the sentence
         else if (!(this->at(end) >= 'a' && this->at(end) <= 'z'))
             end--;


         else if (this->at(start) == this->at(end))
             start++, end--;

         else
             return false;
     }
    return true;
}

int main() {
    
    string str;
      
    cout << "Enter string: "; cin >> str;
    
    Pstring str1{str};
    if (str1.isPalindrome()) {
        cout << str << " is palindrome." << endl;
    }else {
        cout << str << " is not palindrome." << endl;
    }
    return 0;
}
