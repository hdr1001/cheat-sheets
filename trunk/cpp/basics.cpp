/* *********************************************************************
//
// Basic C++ coding examples
//
// basics.cpp is a C++ (basics) cheat sheet
// copyright 2006 Hans de Rooij
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; either version 2 of
// the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public
// License along with this program; if not, write to the Free
// Software Foundation, Inc., 51 Franklin St, Boston, MA
// 20110-1301, USA.
//
//
// Compile using the GNU C++ compiler
//    g++ basics.cpp -o basics
//
// ****************************************************************** */

#include <iostream>
#include <iomanip>
#include <limits.h>
#include <assert.h>
#include "timestwo.h"

//Disable irrelevant Microsoft Visual C++ compiler warnings
#ifdef _MSC_VER
   #pragma warning (disable : 4244)
   #pragma warning (disable : 4305)
   #pragma warning (disable : 4996)
#endif

using namespace std;

const int SIZE_ARR_A = 4;
const int SIZE_ARR_B = 6;


/* *********************************************************************
//
// Data types and related subjects
//
// ****************************************************************** */

//Variable declaration, initialization and assignment
void f001()
{
   //Declarations section
   int n;     //simple variable declaration
   int m = 3; //combined declaration and initialization

   //Assignment
   n = 2;

   //Send the sum of the two variables to the screen
   cout << "m + n = " << (m + n) << endl;

   return;
}

//Integer type ranges and byte sizes
void f002()
{
   cout << "Type char          : range[" << CHAR_MIN << ", " << CHAR_MAX
        << "] and size in bytes " << sizeof(char) << endl;
   cout << "Type short         : range[" << SHRT_MIN << ", " << SHRT_MAX
        << "] and size in bytes " << sizeof(short) << endl;
   cout << "Type int           : range[" << INT_MIN << ", " << INT_MAX
        << "] and size in bytes " << sizeof(int) << endl;
   cout << "Type long          : range[" << LONG_MIN << ", " << LONG_MAX
        << "] and size in bytes " << sizeof(long) << endl;
   cout << "Type signed char   : range[" << SCHAR_MIN << ", " << SCHAR_MAX
        << "] and size in bytes " << sizeof(signed char) << endl;
   cout << "Type unsigned char : range[" << 0 << ", " << UCHAR_MAX
        << "] and size in bytes " << sizeof(unsigned char) << endl;
   cout << "Type unsigned short: range[" << 0 << ", " << USHRT_MAX
        << "] and size in bytes " << sizeof(unsigned short) << endl;
   cout << "Type unsigned int  : range[" << 0 << ", " << UINT_MAX
        << "] and size in bytes " << sizeof(unsigned int) << endl;
   cout << "Type unsigned long : range[" << 0 << ", " << ULONG_MAX
        << "] and size in bytes " << sizeof(unsigned long) << endl;

   return;
}

//Floating point numbers
void f003()
{
   //Declarations section
   float flt1 = 0, flt2 = 0.1;

   //Floating point arithmetic can lead to unexpected results
   for(int i = 0; i < 1000; i++)
   {
      flt1 += flt2;
   }

   cout << "1000 * 0.1 = " << flt1 << " (or is it?)" << endl << endl;

   //Floating point variable byte sizes
   cout << "Byte size of a float       = " << sizeof(flt1) << endl;
   cout << "Byte size of a double      = " << sizeof(double) << endl;
   cout << "Byte size of a long double = " << sizeof(long double) << endl;

   return;
}

//Char data type
void f004() 
{
   char chr;

   //Basic Sesame street
   for(chr = 65; chr <= 90; chr++)
   {
      cout << chr;
   }

   cout << endl;

   //Advanced Sesame street
   for(chr = 122; chr >= 97; chr--)
   {
      cout << chr;
   }

   cout << endl;

   return;
}

//Enumeration types
void f005()
{
   //Declarations section
   enum GameStatus{UNDECIDED, WIN, LOOSE}; //Define the enumeration
   GameStatus gs = UNDECIDED; //Declare & initialize an enum variable

   //Loop to play the game while undecided
   while(gs == UNDECIDED)
   {
      //Game code goes here
      gs = WIN;
   }

   //Let the user know the final game status
   switch(gs)
   {
      case WIN: cout << "You win" << endl; break;
      case LOOSE: cout << "You loose" << endl; break;
   }

   return;
}

//Variable promotion and implicit and explicit casts
void f006()
{
   //Declarations section
   int i1, i2;
   double dbl1, dbl2;

   //Integer promotion, no problem
   i1 = 1234; //assign the value 1234 to i1
   dbl1 = i1; //assign the integer value to variable dbl1

   //Cast the value of a double to an integer
   dbl2 = 234.645; //assign the value 234.645 to dbl2
   i2 = static_cast<int>(dbl2); //use explicit C++ style cast

   cout << "i1 = 1234                   -> i1 = " << i1 << endl;
   cout << "dbl1 = i1                   -> dbl1 = " << dbl1 << endl << endl;

   cout << "dbl2 = 234.645              -> dbl2 = " << dbl2 << endl; 
   cout << "i2 = static_cast<int>(dbl2) -> i2 = " << i2 << endl;

   return;
}


/* *********************************************************************
//
// C++ Operators
//
// ****************************************************************** */

//Arithmetic operators
void f007()
{
   int m = 38, n = 5;
   int i1, i2, i3, i4, i5, i6;

   i1 = m + n; //addition
   i2 = m - n; //substraction
   i3 = -n;    //negation
   i4 = m * n; //multiplication
   i5 = m / n; //division
   i6 = m % n; //modules

   cout << m << " + " << n << " = " << i1 << endl;
   cout << m << " - " << n << " = " << i2 << endl;
   cout << "   - " << n << " = " << i3 << endl;
   cout << m << " * " << n << " = " << i4 << endl;
   cout << m << " / " << n << " = " << i5 << endl;
   cout << m << " % " << n << " = " << i6 << endl;

   return;
}

//Increment(++) and decrement(--) operators
void f008()
{
   int cntr;
   int i1, i2, i3, i4; 
   
   cntr = 1;
   i1 = cntr++; //post-increment
   i2 = cntr;

   cntr = 1;
   i3 = ++cntr; //pre-increment
   i4 = cntr;

   cout << "cntr = 1;" << endl;
   cout << "i1 = cntr++; -> i1 = " << i1 << endl;
   cout << "i2 = cntr;   -> i2 = " << i2 << endl << endl;

   cout << "cntr = 1;" << endl;
   cout << "i3 = ++cntr; -> i3 = " << i3 << endl;
   cout << "i4 = cntr;   -> i4 = " << i4 << endl;

   return;
}

//Compound assignments
void f009()
{
   int n = 5;
   int i1 = 2, i2 = 8, i3 = 2, i4 = 12, i5 = 11;
   int j1 = 2, j2 = 8, j3 = 2, j4 = 12, j5 = 11;

   //Written in full
   i1 = i1 + n;
   i2 = i2 - n;
   i3 = i3 * n;
   i4 = i4 / n;
   i5 = i5 % n;

   //Abbreviated through compound assignment
   j1 += n;
   j2 -= n;
   j3 *= n;
   j4 /= n;
   j5 %= n;

   cout << "i1 = " << setw(2) << i1 << ", j1 = " << setw(2) << j1 << endl;
   cout << "i2 = " << setw(2) << i2 << ", j2 = " << setw(2) << j2 << endl;
   cout << "i3 = " << setw(2) << i3 << ", j3 = " << setw(2) << j3 << endl;
   cout << "i4 = " << setw(2) << i4 << ", j4 = " << setw(2) << j4 << endl;
   cout << "i5 = " << setw(2) << i5 << ", j5 = " << setw(2) << j5 << endl;

   return;
}

//Relational operators
void f010()
{
   int m = 38, n = 5;
   bool b1, b2, b3, b4, b5, b6;

   b1 = (m < n);  //smaller than
   b2 = (m > n);  //larger than
   b3 = (m <= n); //smaller than or equal to
   b4 = (m >= n); //larger than or equal to
   b5 = (m != n); //not equal to
   b6 = (m == n); //equal to

   cout << "Variable m = " << m << ", variable n = " << n << endl << endl; 
   cout << "m < n evaluates to " << (b1 ? "true": "false") << endl;
   cout << "m > n evaluates to " << (b2 ? "true": "false") << endl;
   cout << "m <= n evaluates to " << (b3 ? "true": "false") << endl;
   cout << "m >= n evaluates to " << (b4 ? "true": "false") << endl;
   cout << "m != n evaluates to " << (b5 ? "true": "false") << endl;
   cout << "m == n evaluates to " << (b6 ? "true": "false") << endl;
   
   return;
}

//Compound conditions
void f011()
{
   bool bFoo = true, bBar = false;
   bool b1, b2, b3;

   b1 = bFoo && bBar; //logical and
   b2 = bFoo || bBar; //logical or
   b3 = !bFoo;        //logical not

   cout << "Variable bFoo evaluates to " << (bFoo ? "true": "false") << endl;
   cout << "Variable bBar evaluates to " << (bBar ? "true": "false") << endl;
   cout << endl;
   cout << "bFoo && bBar evaluates to " << (b1 ? "true": "false") << endl;
   cout << "bFoo || bBar evaluates to " << (b2 ? "true": "false") << endl;
   cout << "!bFoo evaluates to " << (b3 ? "true": "false") << endl;

   return;
}


/* *********************************************************************
//
// Conditional execution
//
// ****************************************************************** */

//If else construct
int f012()
{
   int i = 4, j = 3;
   bool bIsDivisible;

   if(j == 0) //single selection if
   {
      //Invalid input for second integer, handle error
      return -1;
   }

   if(i % j == 0) //double selection if ... else
   {
      bIsDivisible = true;
   }
   else
   {
      bIsDivisible = false;
   }

   cout << i << " is " << (bIsDivisible ? "" : "not ")
        << "divisible by " << j << endl;

   return 0;
 }

//Switch
void f013()
{
   int choice = 4;
   char chr;

   switch(choice) //multiple selection switch
   {
      case 1: chr = 'a'; break;
      case 2: chr = 'b'; break;
      case 3: chr = 'c'; break;
      default: chr = 'x';
   }

   cout << "Variable chr now holds the value " << chr << endl;

   return;
}

//Conditional expression operator
void f014()
{
   bool bFoo = false;
   int i = 10;

   bFoo ? i++ : i--;

   !bFoo ? i-- : i++;

   cout << "Integer i now holds the value " << i << endl;

   return;
}


/* *********************************************************************
//
// Iteration
//
// ****************************************************************** */

//While loop, a pre-tested loop
void f015()
{
   int i = 0;
   char chr = 'A';
   char arr[40];

   while(i < 26)
   {
      arr[i] = chr + i++;
   }

   arr[i] = '\0';

   cout << arr << endl;

   return;
}

//Do while loop, a post-tested loop
void f016()
{
   int i = 0;
   char chr = 'Z';
   char arr[40];

   do
   {
      arr[i] = chr - i++;
   }
   while(i < 26);

   arr[i] = '\0';

   cout << arr << endl;

   return;
}

//For loop
void f017()
{
   int i;
   char chr = 'a';
   char arr[40];

   for(i = 0; i < 26; i++)
   {
      arr[i] = chr + i;
   }

   arr[i] = '\0';

   cout << arr << endl;

   return;
}

//Escape from a loop
void f018()
{
   int i;
   char chr = 'a', exit_chr = 'd';
   char arr[40];

   for(i = 0; i < 26; i++)
   {
      if(chr == exit_chr) break;

      arr[i] = chr++;
   }

   arr[i] = '\0';

   cout << arr << endl;

   return;
}

//Jump to next iteration in loop
void f019()
{
   int i;
   char chr = 'a', cont_chr = 'd';
   char arr[40];

   for(i = 0; i < 26; i++, chr++)
   {
      if(chr == cont_chr)
      {
         arr[i] = ' ';

         continue;
      }

      arr[i] = chr;
   }

   arr[i] = '\0';

   cout << arr << endl;

   return;
}


/* *********************************************************************
//
// Functions
//
// ****************************************************************** */

// Remarks for compiling & linking using an external function
// Execute the following commands;
// 1. g++ -c timestwo.cpp
// 2. g++ -c basics.cpp
// 3. g++ -o basics timestwo.o basics.o

//Calls externally defined function TimesTwo
void f020()
{
   int n = 3, m;

   m = TimesTwo(n); //the actual function call

   cout<< "n = " << n << ", n * 2 = " << m << endl; 

   return;
}

// An internal implementation of function TimesTwo, this to enable simple
// straight forward compiling & linking.
// Remark this implementation in case the external function is linked.
/*
int TimesTwo(int k)
{
   return k * 2;
}
*/

// Different ways of passing parameters. In the function PassingParameters;
// 1. the value of parameter p1 is passed by value. The value of argument a1
//    is copied to p1 when the function call is executed. This is similar to
//    to assigning the value of a1 to variable p1.
// 2. parameter p2 is an integer pointer. In the example the address of a2
//    is passed to p2. This implies that all changes to *p2 are, in effect,
//    changes to a2.
// 3. p3 is passed by reference. The & character is used to indicate this.
//    Parameter p3 is now an alias for a3. All changes to p3 are in actual
//    fact also changes to a3.

void PassingParameters(int p1, int* p2, int& p3)
{
   //Save the initial values of the parameters passed to the function
   int p1_save = p1, p2_save = *p2, p3_save = p3;

   //Change the parameter values
   p1 *= 4;
   *p2 *= 4;
   p3 *= 4;

   cout << "At the start of function PassingParameters;" << endl;
   cout << "  p1 = " << p1_save << endl;
   cout << " *p2 = " << p2_save << endl;
   cout << "  p3 = " << p3_save << endl << endl;

   cout << "At the end of function PassingParameters;" << endl;
   cout << "  p1 = " << p1 << endl;
   cout << " *p2 = " << *p2 << endl;
   cout << "  p3 = " << p3 << endl << endl;

   return;
}

//Passing parameters
void f021()
{
   //Declare and initialize the test variables
   int a1 = 1, a2 = 2, a3 = 3;
   int a1_save = a1, a2_save = a2, a3_save = a3; //store initial values

   //Call the function, pass a1 and the address of a2
   PassingParameters(a1, &a2, a3);

   cout << "At the start of function f021;" << endl;
   cout << "  a1 = " << a1_save << endl;
   cout << "  a2 = " << a2_save << endl;
   cout << "  a3 = " << a3_save << endl << endl;

   cout << "At the end of function f021;" << endl;
   cout << "  a1 = " << a1 << endl;
   cout << "  a2 = " << a2 << endl;
   cout << "  a3 = " << a3 << endl;

   return;
}

//Overloaded function with a local static variable
int StaticVariable()
{
   //Declare and initialize variable i
   static int i = 0; //i has static storage duration

   return(++i); //increment i and return
}

//Overloaded function with default argument
int StaticVariable(const char* sMsg, int m = 3)
{
   cout << sMsg << ", m = " << m << endl;

   return(StaticVariable());
}

//Local variable with static storage duration
void f022()
{
   int i1, i2, i3;

   //Call the overloaded version of function StaticVariable with parameters
   i1 = StaticVariable("Two parameters passed", 4);

   //Call the same implementation without specifying the 2nd parameter
   i2 = StaticVariable("Only one parameter passed");

   //... and call the implementation of StaticVariable without parameters
   i3 = StaticVariable();

   cout << "i1 = " << i1 << endl;
   cout << "i2 = " << i2 << endl;
   cout << "i3 = " << i3 << endl;

   return;
}


/* *********************************************************************
//
// Arrays
//
// ****************************************************************** */

//Display one dimensional integer array
void DisplayArray(int arr[], int numElements)
{
   int n;

   for(n = 0; n < numElements; n++)
   {
      cout << "arr[" << n << "] = " << arr[n] << endl;
   }

   cout << endl;

   return;
}

//Display one dimensional integer array in decending order
void DisplayArrayDesc(int arr[], int numElements)
{
   int n;

   for(n = numElements - 1; n >= 0; n--)
   {
      cout << "arr[" << n << "] = " << arr[n] << endl;
   }

   cout << endl;

   return;
}

//Display two dimensional integer array
void Display2DimArray(int arr[][3], int numRows, int numCols)
{
   int n, m;

   for(n = 0; n < numRows; n++)
   {
      for(m = 0; m < numCols; m++)
      {
         cout << "arr[" << n << "][" << m << "] = " 
              << setw(2) << arr[n][m] << "    ";
      }

      cout << endl;
   }

   cout << endl;

   return;
}

// Array declaration, set values and show values 
void f023()
{
   //Declaration of counter variable i and array arrFoo 
   int i, arrFoo[SIZE_ARR_A];

   //Set the values stored in the array
   for(i = 0; i < SIZE_ARR_A; i++)
   {
      arrFoo[i] = (i + 1) * 10;
   }

   //Show the values stored in the array
   DisplayArray(arrFoo, SIZE_ARR_A);
   DisplayArrayDesc(arrFoo, SIZE_ARR_A);

   return;
}

//Sum array elements and store the result in the first element of the array
void SumArrayElements(int arr[], int numElements)
{
   //Declare and initialize a counter variable
   int i;
   
   //Reset the value of the first element of the array to 0
   arr[0] = 0;

   //Sum the remaining elements and store the result in the first element
   for(i = 1; i < numElements; i++)
   {
      arr[0] += arr[i];
   }

   return;
}

//Array initialization and passing an array to a function
void f024()
{
   //Declare array arrBar and initialize to the values in the initializer list
   int arrBar[] = {0, 25, 50, 75, 100};

   //Show the values stored in the array
   DisplayArray(arrBar, 5);

   //Call the function SumArrayElements, pass arrBar as a parameter
   SumArrayElements(arrBar, 5);

   //Again show the values stored in the array
   DisplayArray(arrBar, 5);

   //The first element of the array has changed because passing parameter
   //arrBar is an example of passing a pointer to a funtion
   #ifdef _DEBUG
      assert(arrBar == &arrBar[0]);
   #endif

   return;
}

//Multi-dimensional array
void f025()
{
   int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};

   Display2DimArray(arr, 2, 3);

   return;
}

//Using a pointer to traverse an array
void f026()
{
   int arr[] = {1, 3, 5};

   int* p;

   for(p = arr; p < arr + 3; p++)
   {
      cout << "p = " << p << ", *p = " << *p << endl;
   }

   return;
}


/* *********************************************************************
//
// Pointers and dynamic memory allocation
//
// ****************************************************************** */

//Pointers and references
void f027()
{
   //Declare and initialize integer variable n
   int n = 3; //initialize n to 3

   //Declare integer pointer p
   int* p = &n; //intialize p to the address of n

   //Declare pointer p2p of type pointer to integer pointer
   int** p2p = &p; //initialize p2p to the address of p

   //Declare integer reference i and intialize i to n
   int& i = n;

   cout << "The value of n     = " << n << endl;
   cout << "The address of n   = " << &n << endl << endl;

   cout << "Pointer p holds the address of variable n" << endl;
   cout << "The value of p     = " << p << endl;
   cout << "The address of p   = " << &p << endl;
   cout << "The value of *p    = " << *p
        << " (*p is p dereferenced)" << endl << endl;

   cout << "Pointer p2p holds the address of variable p" << endl;
   cout << "The value of p2p   = " << p2p << endl;
   cout << "The address of p2p = " << &p2p << endl;
   cout << "The value of *p2p  = " << *p2p << endl;
   cout << "The value of **p2p = " << **p2p << endl << endl;

   cout << "Variable i is the same variable as n, it is an alias" << endl;
   cout << "The value of i     = " << i << endl;
   cout << "The address of i   = " << &i << endl << endl;

   return;
}

//Display values associated with integer pointer
void DisplayIntPtr(int* ip, bool bDisplayDeref)
{
   cout << "The value of  ip = " << ip << endl;
   if(bDisplayDeref) cout << "The value of *ip = " << *ip << endl;
   cout << endl;

   return;
}

//Dynamic memory allocation
void f028()
{
   //Call new to reserve enough memory for storing an integer
   int* q = new int;

   //In case memory allocation fails an exception is thrown
   //Do not check "q == NULL" instead catch the bad_alloc exception

   //The value to which pointer q refers is not automatically initialized
   DisplayIntPtr(q, true);

   //Assign the value 3 to integer pointer q dereferenced
   *q = 3;

   //The value to which integer pointer q points is now changed
   DisplayIntPtr(q, true);

   //Free up q's allocated memory resources using delete
   delete q;

   //Don't dereference a pointer after releasing it's resources!
   //*q = 4; //Absolute no no

   //Integer pointer q still points to the previously allocated memory
   DisplayIntPtr(q, false);

   //Better make q a null pointer
   q = NULL;

   //Integer pointer q is now completely reset
   DisplayIntPtr(q, false);
   
   return;
}

//Dynamic memory allocation for arrays
void f029()
{
   //It is possible to use new to reserve memory for an array
   int* q = new int[SIZE_ARR_A];

   //Initialize the array using pointer notation
   for(int* p = q; p < q + SIZE_ARR_A; p++) { *p = 3; }

   //Show array contents after initialization
   DisplayArray(q, SIZE_ARR_A); //function uses subscript notation

   delete[] q;

   return;
}

//Function pointer example functions
int TimesThree(int n){return n * 3;}
int TimesFour(int n){return n * 4;}

//Function pointers
void f030()
{
   int i1, i2;

   //Declare and initialize function pointer fPtr
   int (*fPtr)(int) = TimesThree;

   //Dereference the function pointer for the 1st time
   i1 = (*fPtr)(2); //pass 2 as parameter

   //Change the function associated with the function pointer
   fPtr = TimesFour;

   //Dereference the function pointer for the 2nd time
   i2 = (*fPtr)(2); //pass 2 as parameter

   cout << "Return value of the 1st function call = " << i1 << endl;
   cout << "Return value of the 2nd function call = " << i2 << endl;

   return;
}


/* *********************************************************************
//
// Application entry point
//
// ****************************************************************** */

int main()
{
   //Declarations section
   int iFunction = 0;

   cout << "Please specify the function to run: "; cin >> iFunction;
   cout << endl;

   switch(iFunction)
   {
      case   1: f001(); break;
      case   2: f002(); break;
      case   3: f003(); break;
      case   4: f004(); break;
      case   5: f005(); break;
      case   6: f006(); break;
      case   7: f007(); break;
      case   8: f008(); break;
      case   9: f009(); break;
      case  10: f010(); break;
      case  11: f011(); break;
      case  12: f012(); break;
      case  13: f013(); break;
      case  14: f014(); break;
      case  15: f015(); break;
      case  16: f016(); break;
      case  17: f017(); break;
      case  18: f018(); break;
      case  19: f019(); break;
      case  20: f020(); break;
      case  21: f021(); break;
      case  22: f022(); break;
      case  23: f023(); break;
      case  24: f024(); break;
      case  25: f025(); break;
      case  26: f026(); break;
      case  27: f027(); break;
      case  28: f028(); break;
      case  29: f029(); break;
      case  30: f030(); break;
      default: cout << "Invalid function number specified" << endl;
   }

   return 0;
}

