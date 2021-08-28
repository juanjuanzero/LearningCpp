# Learning C++

## Getting Started
Using Visual Studio 2019. Open up the C++ Console Application Template. You will be greeted with a standard HelloWorld application. The main file is the *LearningCpp.cpp* file. Inside the solution folder. 

> Using Visual Studio here because I am on a windows machine. 
> C++ can be cross platform, when you are developing in a different environment you may want to look at different compilers.

## Looking at the LearningCpp.cpp file.
### What is this project?
This project is just a simple console application that asks the user to guess the number *42*. Its very simple, but setup further learning down the road.

### The *main* method
Program execution begins and ends here. 

### What I've noticed so far
If you squint hard enough C++ has a few similarities to C# but with slight differences.

### Including Libraries
In this project we used the ```#include <iostream>``` to **include** the iostream library or the (Standard Input/ Output Streams Libary)[https://www.cplusplus.com/reference/iostream/]. In the library, there are the ```cout``` and ```cin``` objects that we work with in the project to write to (cout) and read from (cin) the console.

#### using the ```using``` statement
Just below the include statement we write the following:
```
using std::cout;
using std::cin;
```
The two usings are *using* statements (directives?) so that we don\'t have to repeat ```std::``` namespace reference. Where ever you want interact with the object.

#### Function Declarations in the Header File
Just below the usings statements is another ```#include "FunctionDec.h";```

C++ has Header files, in this case the *FunctionDec.h* that you can use to contain function declarations. 

**What is a declaration?** 

There is a pattern in C++, where you declare something before you use it. In our case, here we **declare** the function for the **checkGuess()** method. If we inspect the *FunctionDec.h* file you see the method signature for the **checkGuess()** method. Which states: ```bool checkGuess(int guess, int toGuess);```

**But, where is it defined?**

Ah, so the **checkGuess()** method is defined inside the *Functions.cpp* file. If you inspect this file it would contain the following code:

```
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
```

Visual Studio compiles the source files **.cpp** for you everytime you run the solution by when you are viewing the solution. Visual Studio uses its own built in compiler. In other environments you would need to compile both *LearningCpp.cpp* and *Functions.cpp*. You don\'t have to worry about the Header file.

