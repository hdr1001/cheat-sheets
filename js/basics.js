// *********************************************************************
//
// Basic JavaScript coding examples
//
// basics.js is a JavaScript (basics) cheat sheet
// copyright 2011 Hans de Rooij
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
// *********************************************************************

var SIZE_ARR_A = 4;
var SIZE_ARR_B = 6;


// *********************************************************************
//
// Data types and related subjects
//
// *********************************************************************

//Variable declaration, initialization and assignment
function f001()
{
   //Declarations section
   var n;     //simple variable declaration
   var m = 3; //combined declaration and initialization

   //Assignment
   n = 2;

   //Return the sum of the two variables
   return "m + n = " + (m + n);
}

//JavaScript datatypes
function f002()
{
   var num1, num2, str, boole;
   var obj, arr, dt, regExp, err;
   var func;
   var ret;
   
   //Primitive datatypes
   num1 = 1; //No difference between integer and floating point number types
   ret = "The value of variable \'num1\' = " + num1 + 
      ", the datatype is " + typeof(num1) + "\n";
   num2 = 10.1;
   ret += "The value of variable \'num2\' = " + num2 + 
      ", the datatype is " + typeof(num2) + "\n";

   str = "JavaScript datatypes"; //String type
   ret += "The value of variable \'str\' = \'" + str + 
      "\', the datatype is " + typeof(str) + "\n";

   boole = true; //Boolean type
   ret += "The value of variable \'boole\' = \'" + boole + 
      "\', the datatype is " + typeof(boole) + "\n";

   ret += "Both \'null\' and \'undefined\' are special instances " + 
      "of primitive JavaScript datatypes\n\n";

   //Predefined object datatypes
   obj = {prop1:10, prop2:"ABC"}; //Basic object type
   ret += "The value of variable \'obj\' = \'" + obj + 
      "\', the datatype is " + typeof(obj) + "\n";

   arr = ["E0", 1, true]; //Array type
   ret += "The value of variable \'arr\' = \'" + arr + 
      "\', the datatype is " + typeof(arr) + "\n";

   dt = new Date(); //Date type
   ret += "The value of variable \'dt\' = \'" + dt + 
      "\', the datatype is " + typeof(dt) + "\n";

   regExp = new RegExp("test", "i"); //Regular expression type
   ret += "The value of variable \'regExp\' = \'" + regExp + 
      "\', the datatype is " + typeof(regExp) + "\n";

   err = new Error("Whoops!"); //Error type
   ret += "The value of variable \'err\' = \'" + err + 
      "\', the datatype is " + typeof(err) + "\n\n";

   //Please note that a function is a special kind of object
   //in JavaScript
   func = function(p) {return "p = " + p;};
   ret += "The value of variable \'func\' = \'" + func + 
      "\', the datatype is " + typeof(func);

   return ret;
}

//Floating point numbers
function f003()
{
   //Declarations section
   var flt1 = 0, flt2 = 0.1;
   var i;

   //Floating point arithmetic can lead to unexpected results
   for(i = 0; i < 1000; i++)
   {
      flt1 += flt2;
   }

   return "1000 * 0.1 = " + flt1 + " (or is it?)";
}

//JavaScript has no separate char data type only strings
function f004() 
{
   var i, ret = "";

   //Basic Sesame street
   for(i = 65; i <= 90; i++)
   {
      ret += String.fromCharCode(i);
   }

   ret += "\n";

   //Advanced Sesame street
   for(i = 122; i >= 97;  i--)
   {
      ret += String.fromCharCode(i);
   }

   return ret;
}

//Enumeration types can be emulated in JavaScript using objects
function f005()
{
   //Declarations section
   var GameStatus = {UNDECIDED:0, WIN:1, LOOSE:2}; //Define the enumeration
   var gs = GameStatus.UNDECIDED;

   //Loop to play the game while undecided
   while(gs == GameStatus.UNDECIDED)
   {
      //Game code goes here
      gs = GameStatus.WIN;
   }

   //Let the user know the final game status
   switch(gs)
   {
      case GameStatus.WIN: return "You win";
      case GameStatus.LOOSE: return "You loose";
   }
}

//The JavaScript number datatype
function f006()
{
   //In JavaScript there's no difference between integer and floating
   //point number types
   var num;
   var ret;
   
   for(num = 0; num < 5; num++) {;} //A counter is an integer isn't it?
   ret = "After completing the 1st loop -> num = " + num + "\n";

   num = num / 4; //This is integer division isn't it? No!
   ret += "After division by 4 -> num = " + num + "\n";

   while(num < 10) {num++;} //Increment a number with a fractional part
   ret += "After completing the 2nd loop -> num = " + num + "\n";

   num = Math.round(num); //Round the fractional part
   ret += "After rounding off the fractional part -> num = " + num;

   return ret;
}


// *********************************************************************
//
// JavaScript Operators
//
// *********************************************************************

//Arithmetic operators
function f007()
{
   var m = 38, n = 5;
   var i1, i2, i3, i4, i5, i6;
   var ret;

   i1 = m + n; //addition
   i2 = m - n; //substraction
   i3 = -n;    //negation
   i4 = m * n; //multiplication
   i5 = m / n; //division
   i6 = m % n; //modules

   ret = m + " + " + n + " = " + i1 + "\n";
   ret += m + " - " + n + " = " + i2 + "\n";
   ret += "   - " + n + " = " + i3 + "\n";
   ret += m + " * " + n + " = " + i4 + "\n";
   ret += m + " / " + n + " = " + i5 + "\n";
   ret += m + " % " + n + " = " + i6;

   return ret;
}

//Increment(++) and decrement(--) operators
function f008()
{
   var cntr;
   var i1, i2, i3, i4;
   var ret;
   
   cntr = 1;
   i1 = cntr++; //post-increment
   i2 = cntr;

   cntr = 1;
   i3 = ++cntr; //pre-increment
   i4 = cntr;

   ret = "cntr = 1;\n";
   ret += "i1 = cntr++; -> i1 = " + i1 + "\n";
   ret += "i2 = cntr;   -> i2 = " + i2 + "\n\n";

   ret += "cntr = 1;\n";
   ret += "i3 = ++cntr; -> i3 = " + i3 + "\n";
   ret += "i4 = cntr;   -> i4 = " + i4;

   return ret;
}

//Compound assignments
function f009()
{
   var n = 5;
   var i1 = 2, i2 = 8, i3 = 2, i4 = 12, i5 = 11;
   var j1 = 2, j2 = 8, j3 = 2, j4 = 12, j5 = 11;
   var ret;

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

   ret = "i1 = " + i1 + ", j1 = " + j1 + "\n";
   ret += "i2 = " + i2 + ", j2 = " + j2 + "\n";
   ret += "i3 = " + i3 + ", j3 = " + j3 + "\n";
   ret += "i4 = " + i4 + ", j4 = " + j4 + "\n";
   ret += "i5 = " + i5 + ", j5 = " + j5;
 
   return ret;
}

//Relational operators
function f010()
{
   var m = 38, n = 5;
   var b1, b2, b3, b4, b5, b6, b7, b8;
   var ret;

   b1 = (m < n);  //smaller than
   b2 = (m > n);  //larger than
   b3 = (m <= n); //smaller than or equal to
   b4 = (m >= n); //larger than or equal to
   b5 = (m != n); //not equal to
   b6 = (m == n); //equal to
   b7 = (m !== n);//not identical to
   b8 = (m === n);//identical to

   ret = "Variable m = " + m + ", variable n = " + n + "\n\n";
   ret += "m < n evaluates to " + (b1 ? "true": "false") + "\n";
   ret += "m > n evaluates to " + (b2 ? "true": "false") + "\n";
   ret += "m <= n evaluates to " + (b3 ? "true": "false") + "\n";
   ret += "m >= n evaluates to " + (b4 ? "true": "false") + "\n";
   ret += "m != n evaluates to " + (b5 ? "true": "false") + "\n";
   ret += "m == n evaluates to " + (b6 ? "true": "false") + "\n";
   ret += "m !== n evaluates to " + (b7 ? "true": "false") + "\n";
   ret += "m === n evaluates to " + (b8 ? "true": "false");
   
   return ret;
}

//Compound conditions
function f011()
{
   var bFoo = true, bBar = false;
   var b1, b2, b3;
   var ret;

   b1 = bFoo && bBar; //logical and
   b2 = bFoo || bBar; //logical or
   b3 = !bFoo;        //logical not

   ret = "Variable bFoo evaluates to "+ (bFoo ? "true": "false") + "\n";
   ret += "Variable bBar evaluates to "+ (bBar ? "true": "false") + "\n\n";
   ret += "bFoo && bBar evaluates to "+ (b1 ? "true": "false") + "\n";
   ret += "bFoo || bBar evaluates to "+ (b2 ? "true": "false") + "\n";
   ret += "!bFoo evaluates to "+ (b3 ? "true": "false");

   return ret;
}


// *********************************************************************
//
// Conditional execution
//
// *********************************************************************

//If else construct
function f012()
{
   var i = 4, j = 3;
   var bIsDivisible;

   if(j == 0) //single selection if
   {
      //Invalid input for second integer, handle error
      throw new Error("Division by zero!");
   }

   if(i % j == 0) //double selection if ... else
   {
      bIsDivisible = true;
   }
   else
   {
      bIsDivisible = false;
   }

   return i + " is " + (bIsDivisible ? "" : "not ") + "divisible by " + j;
}

//Switch
function f013()
{
   var choice = 4;
   var chr;

   switch(choice) //multiple selection switch
   {
      case 1: chr = 'a'; break;
      case 2: chr = 'b'; break;
      case 3: chr = 'c'; break;
      default: chr = 'x';
   }

   return "Variable chr now holds the value " + chr;
}

//Conditional expression operator
function f014()
{
   var bFoo = false;
   var i = 10;

   bFoo ? i++ : i--;

   !bFoo ? i-- : i++;

   return "Integer i now holds the value " + i;
}


// *********************************************************************
//
// Iteration
//
// *********************************************************************

//While loop, a pre-tested loop
function f015()
{
   var i = 0;
   var ret = "";

   while(i < 26)
   {
      ret += String.fromCharCode("A".charCodeAt(0) + i++);
   }

   return ret;
}

//Do while loop, a post-tested loop
function f016()
{
   var i = 0;
   var ret = "";

   do
   {
      ret += String.fromCharCode("Z".charCodeAt(0) - i++);
   }
   while(i < 26);

   return ret;
}

//For loop
function f017()
{
   var obj = {p1:"property one", p2:2};
   var ret = "";

   for(var i = 0; i < 26; i++)
   {
      ret += String.fromCharCode("a".charCodeAt(0) + i);
   }

   ret += "\n\n";

   //A JavaScript for-in loop enumerates the properties of an object 
   for(var p in obj)
   {
      ret += "Property " + p + " of object obj = " + obj[p] + "\n";
   }

   return ret;
}

//Escape from a loop
function f018()
{
   var exit_chr = "d";
   var ret = "";

   for(var i = 0; i < 26; i++)
   {
      if("a".charCodeAt(0) + i == exit_chr.charCodeAt(0)) break;

      ret += String.fromCharCode("a".charCodeAt(0) + i);
   }

   return ret;
}

//Jump to next iteration in loop
function f019()
{
   var exit_chr = "d";
   var ret = "";

   for(var i = 0; i < 26; i++)
   {
      if("a".charCodeAt(0) + i == exit_chr.charCodeAt(0))
      {
         ret += " "; 

         continue;
      }

      ret += String.fromCharCode("a".charCodeAt(0) + i);
   }

   return ret;
}


// *********************************************************************
//
// Functions
//
// *********************************************************************

function PassingParameters(p1_int, p2_obj)
{
   var ret;

   ret = "At the start of function PassingParameters;\n";
   ret += "  p1_int      = " + p1_int + "\n";
   ret += "  p2_obj.prop = " + p2_obj.prop + "\n\n";

   //Change the parameter values
   p1_int *= 4;
   p2_obj.prop *= 4;

   ret += "At the end of function PassingParameters;\n";
   ret += "  p1_int      = " + p1_int + "\n";
   ret += "  p2_obj.prop = " + p2_obj.prop + "\n\n";

   return ret;
}

//Passing parameters
function f021()
{
   //Declare and initialize the test variables
   var a1 = 1, a2 = {prop:2};
   var ret;

   ret = "At the start of function f021;\n";
   ret += "  a1      = " + a1 + "\n";
   ret += "  a2.prop = " + a2.prop + "\n\n";

   //Call the function, pass a1 and a2
   ret += PassingParameters(a1, a2);

   ret += "At the end of function f021;\n";
   ret += "  a1      = " + a1 + "\n";
   ret += "  a2.prop = " + a2.prop;

   return ret;
}

//Function with a local static variable
var StaticVariable = (function()
{
   var i = 0;

   return function() {return ++i;}
})();

//Local variable with static storage duration
function f022()
{
   var i1, i2, i3;
   var ret;

   //Call the function with the local static variable
   i1 = StaticVariable();

   //Call the same function again
   i2 = StaticVariable();

   //... and again
   i3 = StaticVariable();

   ret = "i1 = " + i1 + "\n";
   ret += "i2 = " + i2 + "\n";
   ret += "i3 = " + i3;

   return ret;
}


// *********************************************************************
//
// Arrays
//
// *********************************************************************

//Display one dimensional integer array
function DisplayArray(arr)
{
   var n;
   var ret = "";

   for(n = 0; n < arr.length; n++)
   {
      ret += "arr[" + n + "] = " + arr[n] + "\n";
   }

   return ret;
}

//Display one dimensional integer array in decending order
function DisplayArrayDesc(arr)
{
   var n;
   var ret = "";

   for(n = arr.length - 1; n >= 0; n--)
   {
      ret += "arr[" + n + "] = " + arr[n] + "\n";
   }

   return ret;
}

//Display two dimensional integer array
function Display2DimArray(arr)
{
   var n, m;
   var ret = "";

   for(n = 0; n < arr.length; n++)
   {
      for(m = 0; m < arr[n].length; m++)
      {
         ret += "arr[" + n + "][" + m + "] = " + arr[n][m] + "\n";
      }

   }

   return ret;
}

// Array declaration, set values and show values 
function f023()
{
   //Declaration of counter variable i and array arrFoo 
   var i, arrFoo = new Array(SIZE_ARR_A);
   var ret;

   //Set the values stored in the array
   for(i = 0; i < SIZE_ARR_A; i++)
   {
      arrFoo[i] = (i + 1) * 10;
   }

   //Show the values stored in the array
   ret = DisplayArray(arrFoo) + "\n";
   ret += DisplayArrayDesc(arrFoo);

   return ret;
}

//Sum array elements
function SumArrayElements(arr)
{
   //JavaScript array's are objects, so just add a property sum
   arr.sum = 0;

   //Sum the remaining elements and store the result in the first element
   for(var i = 0; i < arr.length; i++)
   {
      arr.sum += arr[i];
   }

   return;
}

//Array initialization and passing an array to a function
function f024()
{
   //Declare array arrBar and initialize to the values in the initializer list
   var arrBar = [25, 50, 75, 100];
   var ret;

   //Show the values stored in the array
   ret = DisplayArray(arrBar) + "\n";

   //Call the function SumArrayElements, pass arrBar as a parameter
   SumArrayElements(arrBar);

   //Again show the values stored in the array
   ret += DisplayArray(arrBar);
   ret += "arrBar.sum = " + arrBar.sum;

   return ret;
}
/
//Multi-dimensional array
function f025()
{
   var arr = [[1, 2, 3], [4, 5, 6]];
   var ret;

   ret = Display2DimArray(arr);

   return ret;
}

//Using a for-in loop to traverse an array
function f026()
{
   var arr = [1, 3, 5];
   var ret = "";

   var p;

   for(p in arr)
   {
      ret += "arr[" + p + "] = " + arr[p] + "\n";
   }

   return ret;
}


// *********************************************************************
//
// Pointers and dynamic memory allocation
//
// *********************************************************************

//Dynamic memory allocation
function f028()
{
   //Declare variable q and initialize it as an empty object
   var q = {}, n, num_elem;
   var ret;

   ret = "Initial value of variable q = " + q + "\n\n";

   //In JavaScript it's not necessary to declare object properties
   q.prop1 = "In JavaScript object properties can be added on the fly";

   //In this example the number of object properties is randomly chosen
   num_elem = Math.floor(Math.random() * 10) + 1;

   //Access object q as an associative array to dynamically add object
   //properties. Memory is dynamically allocated in the process
   for(n = 2; n <= num_elem; n++)
   {
      q["prop" + n] = "Content of prop" + n;
   }

   //List all (enumerable) properties of object q
   for(n in q)
   {
      ret += "q[" + n + "] = " + q[n] + "\n";
   }

   ret += "\n";

   //Test for the availability of property "prop2". Access this
   //property using the dot operator
   if ("prop2" in q) ret += "q.prop2 = " + q.prop2 + "\n\n";

   //Delete all (enumerable) properties from object q. Because there
   //are no other references to the dynamically allocated memory the
   //garbage collection process will automatically free it up
   n = 1;

   while("prop" + n in q) {delete q["prop" + n]; n++}

   if ("prop1" in q) ret += "q.prop1 = " + q.prop1 + "\n";
   if ("prop2" in q) ret += "q.prop2 = " + q.prop2 + "\n";

   return ret;
}

//Dynamic memory allocation for arrays
function f029()
{
   //Declare variable arr and initialize it as an empty array
   var arr = [];
   var ret;

   //Add array elements by assigning a value
   for(var i = 0; i < SIZE_ARR_A; i++) {arr[i] = 3;}

   //Show array contents after initialization
   ret = DisplayArray(arr) + "\n";

   //Truncate the array. The garbage collection process will free up
   //all allocated memory addresses that are no longer referenced
   arr.length = 0;

   //Add array elements by assigning a value
   for(i = 0; i < SIZE_ARR_B; i++) {arr[i] = (i + 1) * 10;}

   //Show array contents after setting the array values
   ret += DisplayArray(arr);

   return ret;
}

//Function reference example function
function TimesFour(n) {return n * 4;}

//Function reference
function f030()
{
   var i1, i2;
   var ret;

   //Declare and initialize function pointer fPtr
   var fPtr = function(n) {return n * 3;};

   //Call the function for the 1st time
   i1 = fPtr(2); //pass 2 as parameter

   //Change the function associated with the function pointer
   fPtr = TimesFour;

   //Call the function for the 2nd time
   i2 = fPtr(2); //pass 2 as parameter

   ret = "Return value of the 1st function call = " + i1 + "\n";
   ret += "Return value of the 2nd function call = " + i2;

   return ret;
}

