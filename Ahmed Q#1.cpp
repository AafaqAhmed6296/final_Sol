//
//  main.cpp
//  Q#1
//
//  Created by Afaq Ahmed on 18/08/2020.
//  Copyright © 2020 Afaq Ahmed. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int squareRoot(int);

int main() {
    
    int num;

    cout << "Enter the number you want the square root of: ";
    cin >> num;
    try
    {
        
        squareRoot(num);
        cout << "The square root is " << sqrt(num) << endl;

    }
    catch (string ex)
    {
        cout << ex << endl;
    }

    return 0;
}

int squareRoot(int num)
{
    int value = sqrt(num);
    cout << value << endl;
    if ((value*value) != num ) {
        throw string("Input number is not perfect square");
    }
    return value;
}

