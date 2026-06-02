# cBasics

[![Static Badge](https://img.shields.io/badge/language-6771B0?logo=c&logoColor=white&labelColor=585858)](https://www.c-language.org/)
[![GitHub License](https://img.shields.io/github/license/fernandomartinscardoso/cBasics?color=5B9C73)](https://github.com/fernandomartinscardoso/cBasics/blob/main/LICENSE)

This repository was created to share basic projects in C for study and tests purposes.

## Basic concepts

This section presents summary and notes on the reading of the book __C, The Complete Reference__ by Herbert Schildt, among other references like  [this article from Geeks for Geeks site](https://www.geeksforgeeks.org/c/structure-of-c-program/).

### C Program compilation

According to Schildt, C program compilation to create the executable consists of three steps:
1. Creating the program
1. Compiling the program
1. Linking the program with the functions needed from the library

The general form of a C program looks like this:

```
Global declarations

int main(parameter list)
{
    statement sequence
}

return-type f1 (parameter list)
{
    statement sequence
}

return-type f2 (parameter list)
{
    statement sequence
}
.
.
.
return-type fN (parameter list)
{
    statement sequence
}
```

This form can be broken down into the following six main sections:
1. Documentation
1. Preprocessor Section
1. Definition
1. Global Declaration
1. Main() Function
1. Sub Programs

### 1. Documentation

Contains the description of the program, specified in the form of comments:

```
// description, name of the program, programmer name, date, time etc.
```

or

```
/*
    description, name of the program, programmer name, date, time etc.
*/
```

### 2. Preprocessor section

Contains the header files of the program, which help us to access other's code into our code. Example:

```
#include<stdio.h>
#include<math.h>
```

### 3. Definition

The `#define` preprocessor is used to create a constant throughout the program. Whenever this name is encountered by the compiler, it is replaced by the actual piece of defined code. Example:

```
#define long long ll
```

### 4. Global declaration

The global declaration section contains global variables, function declaration, and static variables. Variables and functions which are declared in this scope can be used anywhere in the program. Example:

```
int num = 18;
```

### 5. Main() function

Every C program must have a main function. Operations like declaration and execution are performed inside the curly braces of the main program. The return type of the main() function can be int as well as void too. void() main tells the compiler that the program will not return any value. The int main() tells the compiler that the program will return an integer value. Examples:

```
void main()
```

or

```
int main()
```

### 6. Sub programs

User-defined functions are called in this section of the program. The control of the program is shifted to the called function whenever they are called from the main or outside the main() function, as per requirements of the programmer. Example:

```
int sum(int x, int y)
{
    return x+y;
}
```

### Complete example of a C program

[The article from Geeks for Geeks site](https://www.geeksforgeeks.org/c/structure-of-c-program/) brings this full example of a C program to find the sum of 2 numbers, containing the sections mentioned above:

```
// Documentation
/**                     
 * file: sum.c
 * author: you
 * description: program to find sum.
 */

// Link
#include <stdio.h>      

// Definition
#define X 20 

// Global Declaration
int sum(int y);   

// Main() Function
int main(void)       
{
  int y = 55;
  printf("Sum: %d", sum(y));
  return 0;
}

// Subprogram
int sum(int y) 
{
  return y + X;
}
```

Output:

```
Sum: 75
```

### Review of terms

As summarized by Schildt:

* _Source code:_ The text of a program that the user can read. The source code is input into the C compiler.

* _Object code:_ Translation of the source code of a program into a machine code, which the computer can read and execute directly. Object code is the input to the linker.

* _Linker:_ A program that links the separately compiled modules into one program. It also combines the functions in the Standard C library with the code that you wrote. The output of the linker is the executable program.

* _Library:_ The file containing the standard functions that your program can use. There functions include all I/O operations as well as other useful routines.

* _Compile time:_ The time during which your program is being compiled.

* _Run time:_ The time during which your program is executing.

## Expressions: Data and Operators

C supports many types of data, which can be represented by variables, constants, or values returned by functions.

### Basic data types

The foundational data types defined by C89 are:

1. Character, declared using __char__
1. Integer, declared using __int__
1. Floating-point, declared using __float__
1. Double floating-point, declared using __double__
1. Valueless, declared using __void__

Except for __void__, all the other types can be altered by the following modifiers:

* __signed__
* __unsigned__
* __long__
* __short__

Which results on the _minimum range_ below for all data types defined by the C standard (Schildt):

|   Type                 |  Typical Size (Bits) |   Minimal Range                              |
|:-----------------------|----------------------|:---------------------------------------------|
| char                   |   8                  |  -127 to 127                                 |
| unsigned char          |   8                  |  0 to 255                                    |
| signed char            |   8                  |  -127 to 127                                 |
| int                    |   16 or 32           |  -32,767 to 32,767                           |
| unsigned int           |   16 or 32           |  0 to 65,535                                 |
| signed int             |   16 or 32           |  Same as __int__                             |
| short int              |   16                 |  -32,767 to 32,767                           |
| unsigned short int     |   16                 |  0 to 65,535                                 |
| signed short int       |   16                 |  Same as __short int__                       |
| long int               |   32                 |  -2,147,483,647 to 2,147,483,647             |
| long long int          |   64                 |  -(2<sup>63</sup> - 1) to 2<sup>63</sup> - 1 (Added by C99) |
| signed long int        |   32                 |  Same as __long int__                        |
| unsigned long int      |   32                 |  0 to 4,294,967,295                          |
| unsigned long long int |   64                 |  2<sup>64</sup> - 1 (Added by C99)           |
| float                  |   32                 |  1E-37 to 1E+37 with six digits of precision |
| double                 |   64                 |  1E-37 to 1E+37 with ten digits of precision |
| long double            |   80                 |  1E-37 to 1E+37 with ten digits of precision |

The integers are __signed__ by default, so __signed integer__ is redundant but allowed. The __char__ is unsigned by default, therefore it can be modified by __signed__, which is the main use of this modifier.

In Schildt's words:

> Signed and unsigned integers differ in the way that the high-order bit of the integer is interpreted. If you specify a signed integer, the compiler generates code that assumes the high-order bit of an integer is to be used as a _sign flag_. If the sign flag is 0, the number is positive; if it is 1, the number is negative.
>
> In general, negative numbers are represented using the _two's complement_ approach, which reverses all bits in the number (except the sign flag), adds 1 to this number, and sets the sign flag to 1.
>
> Signed integers are important for a great many algorithms, but they only have half the absolute magnitude of their unsigned relatives. For example, here is 32,767 in binary: __0 1 1 1 1 1 1 1  1 1 1 1 1 1 1 1__
>
> If the high-order bit were set to 1, the number would be interpreted as –1. However, if you declare this to be an __unsigned int__, the number becomes 65,535 when the high-order bit is set to 1.

If the modifier is used by itself, then __int__ is assumed by default. Thus, __signed__ is the same as __signed int__, __long__ is the same as __long int__, and so on.

### Identifiers names

In C, the name of variables, functions, labels, among other user-defined items are called _identifiers_. The length of the identifiers can vary from one to several characters, but the first character must be a letter or underscore, and teh subsequent characters must be either letters, digits, or underscores. Examples (Schildt):

| Correct      | Incorrect      |
|:-------------|:---------------|
| count        | 1count         |
| test23       | hi!there       |
| high_balance | high...balance |

C is case sensitive, therefore in an identifier, upper- and lowercase are treated as distinct.

### Variables

P. 58
