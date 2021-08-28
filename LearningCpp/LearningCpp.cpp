// LearningCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//just like in C# the using statement can be used here to take away the shorten your code
using std::cout; //stud out for outputting to the console
using std::cin; //stud in, for reading from the console

#include <vector>
using std::vector;

#include <algorithm>
using std::sort;
using std::begin;
using std::end;

#include "FunctionDec.h";

int main()
{
    cout << "Hello World!\n";
    int numberToGuess = 42;
    int userGuess;
    bool keepGuessing = true;
    vector<int> tries;

    while (keepGuessing) 
    {
        cout << "\nPlease guess a number.\nYour guess :";
        cin >> userGuess;

        keepGuessing = checkGuess(userGuess, numberToGuess);
        if (keepGuessing) 
        {
            tries.push_back(userGuess);
        }
    }

    cout << "\nHere are were your failed attempts order by value:\n";
    sort(begin(tries), end(tries)); //sorting

    for (auto item : tries) {
        cout << item << " ";
    }
    cout << "\n";
}