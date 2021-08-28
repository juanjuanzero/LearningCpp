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
In this project we used the ```#include <iostream>``` to **include** the iostream library or the [Standard Input/ Output Streams Libary](https://www.cplusplus.com/reference/iostream/). In the library, there are the ```cout``` and ```cin``` objects that we work with in the project to write to (cout) and read from (cin) the console.

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

##### What is a declaration?

There is a pattern in C++, where you declare something before you use it. In our case, here we **declare** the function for the **checkGuess()** method. If we inspect the *FunctionDec.h* file you see the method signature for the **checkGuess()** method. Which states: ```bool checkGuess(int guess, int toGuess);```

##### But, where is it defined?

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

Visual Studio compiles the source files **.cpp** for you everytime you run the solution by when you are viewing the solution. Visual Studio uses its own built in compiler. In other environments you would need to compile both *LearningCpp.cpp* and *Functions.cpp*. Something like the command ```clang LearningCpp.cpp Functions.cpp``` if you are using the clang compiler. You don\'t have to worry about the Header file.

#### Buidling, Compiler Errors and Linker Errors
When you are building your project you might get compiler errors. For windows atleast those will have error codes that begin with the letter *C* to tell you have the compiler has found an error. Then you can also have Linker errors, those error codes will be prefixed with **LNK**. Linker errors are different than compiler errors. When you compile (or build) your code, the compiler will generate the appropriate *.obj* files from the *.cpp* files. Then theres a step to **link** them all together to create the *.exe* file which is then what we use to \"run\" the program.

## Adding Vector & Algorithm | Working with Collections
We went ahead and added the following lines of code to the just below the reference to the IO stream library.

```
#include <vector>
using std::vector;

#include <algorithm>
using std::sort;
using std::begin;
using std::end;
```

### The Collection | Vector Libary
Here we have added the ```vector``` library. A [vector](https://en.cppreference.com/w/cpp/container/vector) represents a collection of objects that are of the same type. Just above the while loop in the *LearningCpp.cpp* file we see the following code: ```vector<int> tries;``` which initializes a collection of type **int** called **tries**. This is an object.

Then we use the **tries** object to act as a container for all of the failed tries that the user does. If the user needs to keep guessing (keepGuessing == true) then we add the failed guess to the **tries**. This addition is done by the **push_back()** method on the vector object. This is implemented like so inside the while loop:
```
if (keepGuessing) 
{
    tries.push_back(userGuess);
}
```

### Working with Vectors | The Algorithm Library
We've also added the algorithm library. The algorithm library allows us to work with collections **(not just vectors)** in C++. These are available as functions in the library. 

At the top, you see the usin statements for **sort, begin, and end** methods. We use these to identify the beginning (begin()), the end (end()) of the vector and sort the vector. 
> The begin and end methods were needed so that we sort the entire vector and not just a slice of it.

Then we write them out to the console using a for loop. This is implemented in the code like so:
```
cout << "\nHere are were your failed attempts order by value:\n";
    sort(begin(tries), end(tries)); //sorting

    for (auto item : tries) {
        cout << item << " ";
    }
```