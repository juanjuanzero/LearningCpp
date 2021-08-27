#include <iostream>

bool checkGuess(int guess, int toGuess) {
    if (guess == toGuess)
    {
        std::cout << "\nWell done!\n";
        return false;
    }
    else {
        std::cout << "\nNope! lol. Keep guessing!\n";
        return true;
    }
}