// *********************************************************************
//
// Basic C coding examples
//
// basics.c is a C (basics) cheat sheet
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
// Compile using the GNU C compiler
//    gcc basics.c -o cbasics
//
// Compile using the GNU C++ compiler
//    g++ basics.c -o basics
//
// *********************************************************************

#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include <stdlib.h>
#include "timestwo.h"

//Disable irrelevant Microsoft Visual C compiler warnings
#ifdef _MSC_VER
   #pragma warning (disable : 4244)
   #pragma warning (disable : 4305)
   #pragma warning (disable : 4996)
#endif

#define SIZE_ARR_A 4
#define SIZE_ARR_B 6


// *********************************************************************
//
// Data types and related subjects
//
// *********************************************************************

//Variable declaration, initialization and assignment
void f001()
{
   //Declarations section
   int n;     //simple variable declaration
   int m = 3; //combined declaration and initialization

   //Assignment
   n = 2;

   //Send the sum of the two variables to the screen
   printf("m + n = %d\n", (m + n));

   return;
}

//Integer type ranges and byte sizes
void f002()
{
   printf("Type char          : range[%d, %d] and size in bytes %d\n",
             CHAR_MIN, CHAR_MAX, sizeof(char));
   printf("Type short         : range[%d, %d] and size in bytes %d\n",
             SHRT_MIN, SHRT_MAX, sizeof(short));
   printf("Type int           : range[%d, %d] and size in bytes %d\n",
             INT_MIN, INT_MAX, sizeof(int));
   printf("Type long          : range[%ld, %ld] and size in bytes %d\n",
             LONG_MIN, LONG_MAX, sizeof(long));
   printf("Type signed char   : range[%d, %d] and size in bytes %d\n",
             SCHAR_MIN, SCHAR_MAX, sizeof(signed char));
   printf("Type unsigned char : range[%d, %u] and size in bytes %d\n",
             0, UCHAR_MAX, sizeof(unsigned char));
   printf("Type unsigned short: range[%d, %u] and size in bytes %d\n",
             0, USHRT_MAX, sizeof(unsigned short));
   printf("Type unsigned int  : range[%d, %u] and size in bytes %d\n",
             0, UINT_MAX, sizeof(unsigned int));
   printf("Type unsigned long : range[%d, %lu] and size in bytes %d\n",
             0, ULONG_MAX, sizeof(unsigned long));

   return;
}

//Floating point numbers
void f003()
{
   //Declarations section
   float flt1 = 0, flt2 = 0.1;
   int i;

   //Floating point arithmetic can lead to unexpected results
   for(i = 0; i < 1000; i++)
   {
      flt1 += flt2;
   }

   printf("1000 * 0.1 = %f (or is it?)\n\n", flt1);

   //Floating point variable byte sizes
   printf("Byte size of a float       = %d\n", sizeof(flt1));
   printf("Byte size of a double      = %d\n", sizeof(double));
   printf("Byte size of a long double = %d\n", sizeof(long double));

   return;
}

//Char data type
void f004() 
{
   char chr;

   //Basic Sesame street
   for(chr = 65; chr <= 90; chr++)
   {
      putchar(chr);
   }

   putchar('\n');

   //Advanced Sesame street
   for(chr = 122; chr >= 97; chr--)
   {
      putchar(chr);
   }

   putchar('\n');

   return;
}

//Enumeration types
void f005()
{
   //Declarations section
   enum GameStatus{UNDECIDED, WIN, LOOSE}; //Define the enumeration
   enum GameStatus gs = UNDECIDED; //Declare & initialize an enum variable

   //Loop to play the game while undecided
   while(gs == UNDECIDED)
   {
      //Game code goes here
      gs = WIN;
   }

   //Let the user know the final game status
   switch(gs)
   {
      case WIN: printf("You win\n"); break;
      case LOOSE: printf("You loose\n"); break;
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
   #ifdef __cplusplus
      i2 = (int)dbl2; //use explicit C style cast for C++ compile
   #else
      i2 = dbl2; //no C compiler warning in case of implicit cast
   #endif

   printf("i1 = 1234      -> i1 = %d\n", i1);
   printf("dbl1 = i1      -> dbl1 = %f\n\n", dbl1); 

   printf("dbl2 = 234.645 -> dbl2 = %f\n", dbl2); 
   #ifdef __cplusplus
      printf("i2 = (int)dbl2 -> i2 = %d\n", i2);
   #else
      printf("i2 = dbl2      -> i2 = %d\n", i2);
   #endif

   return;
}


// *********************************************************************
//
// C Operators
//
// *********************************************************************

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

   printf("%d + %d = %d\n", m, n, i1);
   printf("%d - %d = %d\n", m, n, i2);
   printf("   - %d = %d\n", n, i3);
   printf("%d * %d = %d\n", m, n, i4);
   printf("%d / %d = %d\n", m, n, i5);
   printf("%d %% %d = %d\n", m, n, i6);

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

   printf("cntr = 1;\n");
   printf("i1 = cntr++; -> i1 = %d\n", i1);
   printf("i2 = cntr;   -> i2 = %d\n\n", i2);

   printf("cntr = 1;\n");
   printf("i3 = ++cntr; -> i3 = %d\n", i3);
   printf("i4 = cntr;   -> i4 = %d\n", i4);

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

   printf("i1 = %2d, j1 = %2d\n", i1, j1);
   printf("i2 = %2d, j2 = %2d\n", i2, j2);
   printf("i3 = %2d, j3 = %2d\n", i3, j3);
   printf("i4 = %2d, j4 = %2d\n", i4, j4);
   printf("i5 = %2d, j5 = %2d\n", i5, j5);

   return;
}

//Relational operators
void f010()
{
   int m = 38, n = 5;
   short b1, b2, b3, b4, b5, b6;

   b1 = (m < n);  //smaller than
   b2 = (m > n);  //larger than
   b3 = (m <= n); //smaller than or equal to
   b4 = (m >= n); //larger than or equal to
   b5 = (m != n); //not equal to
   b6 = (m == n); //equal to

   printf("Variable m = %d, variable n = %d\n\n", m, n); 
   printf("m < n evaluates to %s\n", b1 ? "true": "false");
   printf("m > n evaluates to %s\n", b2 ? "true": "false");
   printf("m <= n evaluates to %s\n", b3 ? "true": "false");
   printf("m >= n evaluates to %s\n", b4 ? "true": "false");
   printf("m != n evaluates to %s\n", b5 ? "true": "false");
   printf("m == n evaluates to %s\n", b6 ? "true": "false");
   
   return;
}

//Compound conditions
void f011()
{
   short bFoo = 1, bBar = 0;
   short b1, b2, b3;

   b1 = bFoo && bBar; //logical and
   b2 = bFoo || bBar; //logical or
   b3 = !bFoo;        //logical not

   printf("Variable bFoo evaluates to %s\n", bFoo ? "true": "false");
   printf("Variable bBar evaluates to %s\n\n", bBar ? "true": "false");
   printf("bFoo && bBar evaluates to %s\n", b1 ? "true": "false");
   printf("bFoo || bBar evaluates to %s\n", b2 ? "true": "false");
   printf("!bFoo evaluates to %s\n", b3 ? "true": "false");

   return;
}


// *********************************************************************
//
// Conditional execution
//
// *********************************************************************

//If else construct
int f012()
{
   int i = 4, j = 3;
   short bIsDivisible;

   if(j == 0) //single selection if
   {
      //Invalid input for second integer, handle error
      return -1;
   }

   if(i % j == 0) //double selection if ... else
   {
      bIsDivisible = 1;
   }
   else
   {
      bIsDivisible = 0;
   }

   printf("%d is %sdivisible by %d\n", i, (bIsDivisible ? "" : "not "), j);

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

   printf("Variable chr now holds the value %c\n", chr);

   return;
}

//Conditional expression operator
void f014()
{
   short bFoo = 0;
   int i = 10;

   bFoo ? i++ : i--;

   !bFoo ? i-- : i++;

   printf("Integer i now holds the value %d\n", i);

   return;
}


// *********************************************************************
//
// Iteration
//
// *********************************************************************

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

   printf("%s\n", arr);

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

   printf("%s\n", arr);

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

   printf("%s\n", arr);

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

   printf("%s\n", arr);

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

   printf("%s\n", arr);

   return;
}


// *********************************************************************
//
// Functions
//
// *********************************************************************

// Remarks for compiling & linking using an external function
// Execute the following commands;
// 1. gcc -c timestwo.c
// 2. gcc -c basics.c
// 3. gcc -o cbasics timestwo.o basics.o
// or
// 1. g++ -c timestwo.c
// 2. g++ -c basics.c
// 3. g++ -o basics timestwo.o basics.o

//Calls externally defined function TimesTwo
void f020()
{
   int n = 3, m;

   m = TimesTwo(n); //the actual function call

   printf("n = %d, n * 2 = %d\n", n, m); 

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

void PassingParameters(int p1, int* p2)
{
   //Save the initial values of the parameters passed to the function
   int p1_save = p1, p2_save = *p2;

   //Change the parameter values
   p1 *= 4;
   *p2 *= 4;

   printf("At the start of function PassingParameters;\n");
   printf("  p1 = %d\n", p1_save);
   printf(" *p2 = %d\n\n", p2_save);

   printf("At the end of function PassingParameters;\n");
   printf("  p1 = %d\n", p1);
   printf(" *p2 = %d\n\n", *p2);

   return;
}

//Passing parameters
void f021()
{
   //Declare and initialize the test variables
   int a1 = 1, a2 = 2;
   int a1_save = a1, a2_save = a2; //store initial values of a1 & a2

   //Call the function, pass a1 and the address of a2
   PassingParameters(a1, &a2);

   printf("At the start of function f021;\n");
   printf("  a1 = %d\n", a1_save);
   printf("  a2 = %d\n\n", a2_save);

   printf("At the end of function f021;\n");
   printf("  a1 = %d\n", a1);
   printf("  a2 = %d\n", a2);

   return;
}

//Function with a local static variable
int StaticVariable()
{
   //Declare and initialize variable i
   static int i = 0; //i has static storage duration

   return(++i); //increment i and return 
}

//Local variable with static storage duration
void f022()
{
   int i1, i2, i3;

   //Call the function with the local static variable
   i1 = StaticVariable();

   //Call the same function again
   i2 = StaticVariable();

   //... and again
   i3 = StaticVariable();

   printf("i1 = %d\n", i1);
   printf("i2 = %d\n", i2);
   printf("i3 = %d\n", i3);

   return;
}


// *********************************************************************
//
// Arrays
//
// *********************************************************************

//Display one dimensional integer array
void DisplayArray(int arr[], int numElements)
{
   int n;

   for(n = 0; n < numElements; n++)
   {
      printf("arr[%d] = %d\n", n, arr[n]);
   }

   putchar('\n');

   return;
}

//Display one dimensional integer array in decending order
void DisplayArrayDesc(int arr[], int numElements)
{
   int n;

   for(n = numElements - 1; n >= 0; n--)
   {
      printf("arr[%d] = %d\n", n, arr[n]);
   }

   putchar('\n');

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
         printf("arr[%d][%d] = %2d    ", n, m, arr[n][m]);
      }

      putchar('\n');
   }

   putchar('\n');

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
      printf("p = %p, *p = %d\n", p, *p);
   }

   return;
}


// *********************************************************************
//
// Pointers and dynamic memory allocation
//
// *********************************************************************

//Pointers (no such a thing as references in C!)
void f027()
{
   //Declare and initialize integer variable n
   int n = 3; //initialize n to 3

   //Declare integer pointer p
   int* p = &n; //intialize p to the address of n

   //Declare pointer p2p of type pointer to integer pointer
   int** p2p = &p; //initialize p2p to the address of p

   printf("The value of n     = %d\n", n);
   printf("The address of n   = %p\n\n", &n);

   printf("Pointer p holds the address of variable n\n");
   printf("The value of p     = %p\n", p);
   printf("The address of p   = %p\n", &p);
   printf("The value of *p    = %d (*p is p dereferenced)\n\n", *p);

   printf("Pointer p2p holds the address of variable p\n");
   printf("The value of p2p   = %p\n", p2p);
   printf("The address of p2p = %p\n", &p2p);
   printf("The value of *p2p  = %p\n", *p2p);
   printf("The value of **p2p = %d\n", **p2p);

   return;
}

//Display values associated with integer pointer
void DisplayIntPtr(int* ip, short bDisplayDeref)
{
   printf("The value of  ip = %p\n", ip);
   bDisplayDeref ? printf("The value of *ip = %d\n\n", *ip) : putchar('\n');

   return;
}

//Dynamic memory allocation
void f028()
{
   //Call malloc to reserve enough memory for storing an integer
   #ifdef __cplusplus
      //C++ forces the cast of the void pointer returned by malloc
      int* q = (int*)malloc(sizeof(int));
   #else
      //Function malloc returns a void pointer
      int* q = malloc(sizeof(int));
   #endif

   if(q == NULL)
   {
      //Memory allocation failed, handle error
      return; 
   }

   //The value to which pointer q refers is not automatically initialized
   DisplayIntPtr(q, 1);

   //Assign the value 3 to integer pointer q dereferenced
   *q = 3;

   //The value to which integer pointer q points is now changed
   DisplayIntPtr(q, 1);

   //Free up q's allocated memory resources using free
   free(q);

   //Don't dereference a pointer after releasing it's resources!
   //*q = 4; //Absolute no no

   //Integer pointer q still points to the previously allocated memory
   DisplayIntPtr(q, 0);

   //Better make q a null pointer
   q = NULL;

   //Integer pointer q is now completely reset
   DisplayIntPtr(q, 0);
   
   return;
}

//Dynamic memory allocation for arrays
void f029()
{
   int i; int* p;

   //It is possible to use malloc to reserve memory for an array
   #ifdef __cplusplus
      int* q = (int*)malloc(SIZE_ARR_A * sizeof(int));
   #else
      int* q = malloc(SIZE_ARR_A * sizeof(int));
   #endif

   //Initialize the array using pointer notation
   for(p = q; p < q + SIZE_ARR_A; p++) { *p = 3; }

   //Show array contents after initialization
   DisplayArray(q, SIZE_ARR_A); //function uses subscript notation

   free(q);

   //It is also possible to initialize an array using calloc. This
   //funtion has two parameters; the 1st is the number of variables,
   //the 2nd the size of each variable. Using calloc the allocated
   //memory is automatically initialized
   #ifdef __cplusplus
      q = (int*)calloc(SIZE_ARR_B, sizeof(int));
   #else
      q = calloc(SIZE_ARR_B, sizeof(int));
   #endif

   //Show array contents immediately after the call to calloc
   DisplayArray(q, SIZE_ARR_B);

   //Set array values using a subscript notation
   for(i = 0; i < SIZE_ARR_B; i++) { q[i] = (i + 1) * 10; }

   //Show array contents after setting the array values
   DisplayArray(q, SIZE_ARR_B);

   free(q);

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

   printf("Return value of the 1st function call = %d\n", i1);
   printf("Return value of the 2nd function call = %d\n", i2);

   return;
}


// *********************************************************************
//
// Application entry point
//
// *********************************************************************

int main(int argc, char* argv[])
{
   //Declarations section
   int iFunction = 0;

   #ifdef __cplusplus
      printf("Running %s, built using a C++ compiler\n\n", argv[0]);
   #else
      printf("Running %s, built using a C compiler\n\n", argv[0]);
   #endif

   //Check if a function number was specified on the commandline
   if(argc >= 2) iFunction = atoi(argv[1]);

   //If necessary prompt the user for a function number
   if(iFunction <= 0 || iFunction > 30)
   {
      printf("Please specify the function to run: ");
      if(scanf("%d", &iFunction) <= 0) iFunction = 0;
      putchar('\n');
   }

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
      default: printf("Invalid function number specified\n");
   }

   return 0;
}
