' *********************************************************************
'
' Basic Visual Basic coding examples
'
' basics.bas is a Visual Basic (basics) cheat sheet
' copyright 2006 Hans de Rooij
'
' This program is free software; you can redistribute it and/or
' modify it under the terms of the GNU General Public License as
' published by the Free Software Foundation; either version 2 of
' the License, or (at your option) any later version.
'
' This program is distributed in the hope that it will be useful,
' but WITHOUT ANY WARRANTY; without even the implied warranty of
' MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
' GNU General Public License for more details.
'
' You should have received a copy of the GNU General Public
' License along with this program; if not, write to the Free
' Software Foundation, Inc., 51 Franklin St, Boston, MA
' 20110-1301, USA.
'
' ****************************************************************** */

Option Explicit

'Definition of minimum and maximum values of native VB data types
'Preferred approach is to use a separate BAS file for these defines
Public Const BYTE_MIN As Byte = 0
Public Const BYTE_MAX As Byte = 255
Public Const INT_MIN As Integer = -32768
Public Const INT_MAX As Integer = 32767
Public Const LONG_MIN As Long = "-2147483648"
Public Const LONG_MAX As Long = 2147483647

'Enumeration definition (used in f005)
Enum GameStatus
   UNDECIDED = 0
   WIN = 1
   LOOSE = 2
End Enum

Const SIZE_ARR_A = 4


' *********************************************************************
'
' Data types and related subjects
'
' ****************************************************************** */

'Variable declaration and assignment
Sub f001()
   'In VB the Dim statement is used to declare the data type of a
   'variable and to allocate storage space. Visual Basic variables
   'are always initialized to default values. The language doesn't
   'allow for a combined declaration and initialization.
   Dim n As Integer   'simple variable declaration

   'Assignment
   n = 2

   'Send the sum of 3 plus the value of n to the debug window
   Debug.Print "3 + n = " & (3 + n)
End Sub

'Integer type ranges and byte sizes
Sub f002()
   Dim aByte As Byte, aInt As Integer, aLong As Long

   Debug.Print "Type Byte   : range[" & BYTE_MIN & ", " & BYTE_MAX _
        & "] and size in bytes " & LenB(aByte)
   Debug.Print "Type Integer: range[" & INT_MIN & ", " & INT_MAX _
        & "] and size in bytes " & LenB(aInt)
   Debug.Print "Type Long   : range[" & LONG_MIN & ", " & LONG_MAX _
        & "] and size in bytes " & LenB(aLong)
End Sub

'Floating point numbers
Sub f003()
   'Declarations section
   Dim single1 As Single, single2 As Single
   Dim i As Integer, dbl As Double
   
   'Initialize variable single2
   single2 = 0.1

   'Floating point arithmetic can lead to unexpected results
   For i = 1 To 1000
      single1 = single1 + single2
   Next
   
   Debug.Print "1000 * 0.1 = " & single1 & " (or is it?)"
   Debug.Print

   'Floating point variable byte sizes
   Debug.Print "Byte size of a Single = " & LenB(single1)
   Debug.Print "Byte size of a Double = " & LenB(dbl)
End Sub

'Char data type doesn't exist in VB
Sub f004()
   Dim ichr As Integer
   
   'Basic Sesame street
   For ichr = 65 To 90
      Debug.Print chr(ichr);
   Next

   Debug.Print
   
   'Advanced Sesame street
   For ichr = 122 To 97 Step -1
      Debug.Print chr(ichr);
   Next

   Debug.Print
End Sub

'Enumeration types
Sub f005()
   'Definition of the enumeration can only
   'be done at the module level in VB
   
   'Declare an enum variable and assign an initial value
   Dim gs As GameStatus
   gs = GameStatus.UNDECIDED

   'Loop to play the game while undecided
   Do While (gs = GameStatus.UNDECIDED)
      'Game code goes here
      gs = GameStatus.WIN
   Loop

   'Let the user know the final game status
   Select Case gs
      Case GameStatus.WIN
         Debug.Print "You win"
      Case GameStatus.LOOSE
         Debug.Print "You loose"
   End Select
End Sub

'Variable promotion and implicit and explicit casts
Sub f006()
   'Declarations section
   Dim i1 As Integer, i2 As Integer, i3 As Integer
   Dim dbl1 As Double, dbl2 As Double

   'Integer promotion, no problem
   i1 = 1234   'assign the value 1234 to i1
   dbl1 = i1   'assign the integer value to variable dbl1

   'Cast the value of a double to an integer
   dbl2 = 234.645   'assign the value 234.645 to dbl2
   'An implicit cast doesn't result in a warning in VB. Even
   'if no conversion is used banker's rounding is applied.
   i2 = dbl2
   'It's preferable to use a conversion function
   i3 = CInt(dbl2)

   Debug.Print "i1 = 1234       -> i1 = " & i1
   Debug.Print "dbl1 = i1       -> dbl1 = " & dbl1

   Debug.Print "dbl2 = 234.645  -> dbl2 = " & dbl2
   Debug.Print "i2 = dbl2       -> i2 = " & i2
   Debug.Print "i3 = CInt(dbl2) -> i3 = " & i3
End Sub


' *********************************************************************
'
' VB Operators
'
' ******************************************************************* *

'Arithmetic operators
Sub f007()
   Dim m As Integer, n As Integer
   Dim i1 As Integer, i2 As Integer, i3 As Integer
   Dim i4 As Integer, i5 As Integer, i6 As Integer

   m = 38: n = 5 'Variable initialization
   
   i1 = m + n   'addition
   i2 = m - n   'substraction
   i3 = -n      'negation
   i4 = m * n   'multiplication
   i5 = m / n   'division (again banker's rounding!)
   i6 = m Mod n 'modules

   Debug.Print m & " + " & n & " = " & i1
   Debug.Print m & " - " & n & " = " & i2
   Debug.Print "   - " & n & " = " & i3
   Debug.Print m & " * " & n & " = " & i4
   Debug.Print m & " / " & n & " = " & i5
   Debug.Print m & " Mod " & n & " = " & i6
End Sub

'Increment(++) and decrement(--) operators
Sub f008()
   Debug.Print "No such thing as increment operators in VB"
End Sub

'Compound assignments
Sub f009()
   Debug.Print "No such thing compound assignments in VB"
End Sub

'Relational operators
Sub f010()
   Dim m As Integer, n As Integer
   Dim b1 As Boolean, b2 As Boolean, b3 As Boolean
   Dim b4 As Boolean, b5 As Boolean, b6 As Boolean
   
   m = 38: n = 5 'Assign initial values to variables

   b1 = (m < n)  'smaller than
   b2 = (m > n)  'larger than
   b3 = (m <= n) 'smaller than or equal to
   b4 = (m >= n) 'larger than or equal to
   b5 = (m <> n) 'not equal to
   b6 = (m = n)  'equal to

   Debug.Print "Variable m = " & m & ", variable n = " & n
   Debug.Print "m < n evaluates to " & b1
   Debug.Print "m > n evaluates to " & b2
   Debug.Print "m <= n evaluates to " & b3
   Debug.Print "m >= n evaluates to " & b4
   Debug.Print "m <> n evaluates to " & b5
   Debug.Print "m = n evaluates to " & b6
End Sub

'Compound conditions
Sub f011()
   Dim bFoo As Boolean, bBar As Boolean
   Dim b1 As Boolean, b2 As Boolean, b3 As Boolean
   
   bFoo = True: bBar = False

   b1 = bFoo And bBar 'logical and
   b2 = bFoo Or bBar  'logical or
   b3 = Not bFoo      'logical not

   Debug.Print "Variable bFoo evaluates to " & bFoo
   Debug.Print "Variable bBar evaluates to " & bBar
   Debug.Print
   Debug.Print "bFoo And bBar evaluates to " & b1
   Debug.Print "bFoo Or bBar evaluates to " & b2
   Debug.Print "Not bFoo evaluates to " & b3
End Sub


' *********************************************************************
'
' Conditional execution
'
' ******************************************************************* *

'If else construct
Sub f012()
   Dim i As Integer, j As Integer
   Dim bIsDivisible As Boolean
   
   i = 4
   j = 3

   If (j = 0) Then 'single selection if
      'Invalid input for second integer, handle error
      Exit Sub
   End If

   If (i Mod j = 0) Then 'double selection if ... else
      bIsDivisible = True
   Else
      bIsDivisible = False
   End If

   Dim s As String: s = i & " is "
   If Not bIsDivisible Then s = s & "not "
   s = s & "divisible by " & j
   Debug.Print s
End Sub

'Switch
Sub f013()
   Dim choice As Integer
   Dim chr As String
   
   choice = 4

   Select Case (choice)  'multiple selection switch
      Case 1
         chr = "a"
      Case 2
         chr = "b"
      Case 3
         chr = "c"
      Case Else
         chr = "x"
   End Select

   Debug.Print "Variable chr now holds the value " & chr
End Sub

'Conditional expression operator
Sub f014()
   Debug.Print "No such thing as conditional expression operators in VB"
End Sub

' *********************************************************************
'
' Iteration
'
' ******************************************************************* *

'While loop, a pre-tested loop
Sub f015()
   Dim i As Integer
   Dim iCharA As Integer: iCharA = Asc("A")
   Dim s As String

   Do While (i < 26)
      s = s + chr(iCharA + i)
      i = i + 1
   Loop

   Debug.Print s
End Sub

'Do while loop, a post-tested loop
Sub f016()
   Dim i As Integer
   Dim iCharZ As Integer: iCharZ = Asc("Z")
   Dim s As String

   Do
      s = s + chr(iCharZ - i)
      i = i + 1
   Loop While (i < 26)

   Debug.Print s
End Sub

'For loop
Sub f017()
   Dim i As Integer
   Dim iChar_a As Integer: iChar_a = Asc("a")
   Dim s As String
   
   For i = 0 To 25
      s = s + chr(iChar_a + i)
   Next
   
   Debug.Print s
End Sub

'Escape from a loop
Sub f018()
   Dim i As Integer
   Dim iChar_a As Integer: iChar_a = Asc("a")
   Dim iChar_d As Integer: iChar_d = Asc("d")
   Dim s As String
   
   For i = 0 To 25
      If (iChar_a + i = iChar_d) Then Exit For
      s = s + chr(iChar_a + i)
   Next
   
   Debug.Print s
End Sub

'Jump to next iteration in loop
Sub f019()
   Debug.Print "No such thing as the continue statement in VB"
End Sub


' *********************************************************************
'
' Functions
'
' ******************************************************************* *

' Calling a function defined in an external module;
'    - Add a new module to the VB project
'    - Define the function to be called in this newly added module
'    - Please note that private functions can't be called externally
'    - No prototyping or includes are necessary

'Calls externally defined function TimesTwo
Sub f020()
   Dim n As Integer, m As Integer

   n = 3

   m = TimesTwo(n) 'the actual function call

   Debug.Print "n = " & n & ", n * 2 = " & m
End Sub

' An internal implementation of function TimesTwo, this to enable simple
' program execution if no externally defined function is available.
' Please remark this implementation in order to test the external one.
Function TimesTwo(n As Integer) As Integer
   TimesTwo = n * 2
End Function

' Different ways of passing parameters. In the function PassingParameters;
' 1. the value of parameter p1 is passed by value. The value of argument a1
'    is copied to p1 when the function call is executed. This is similar to
'    to assigning the value of a1 to variable p1.
' 2. p2 is passed by reference. In VB passing parameters by reference is
'    default. The explicit keyword to accomplish this is ByRef. Parameter
'    p2 is now an alias for a2. All changes to p2 are in actual fact also
'    changes to a2.

Sub PassingParameters(ByVal p1 As Integer, p2 As Integer)
   'Save the initial values of the parameters passed to the function
   Dim p1_save As Integer, p2_save As Integer
   p1_save = p1: p2_save = p2

   'Change the parameter values
   p1 = p1 * 4
   p2 = p2 * 4

   Debug.Print "At the start of function PassingParameters;"
   Debug.Print "  p1 = " & p1_save
   Debug.Print " *p2 = " & p2_save
   Debug.Print
   Debug.Print "At the end of function PassingParameters;"
   Debug.Print "  p1 = " & p1
   Debug.Print " *p2 = " & p2
   Debug.Print
End Sub

'Passing parameters
Sub f021()
   'Declare and initialize the test variables
   Dim a1 As Integer, a2 As Integer
   Dim a1_save As Integer, a2_save As Integer

   'Store initial values
   a1 = 1: a2 = 2
   a1_save = a1: a2_save = a2

   'Call the function, pass a1 and the address of a2
   PassingParameters a1, a2

   Debug.Print "At the start of function f021;"
   Debug.Print "  a1 = " & a1_save
   Debug.Print "  a2 = " & a2_save
   Debug.Print
   Debug.Print "At the end of function f021;"
   Debug.Print "  a1 = " & a1
   Debug.Print "  a2 = " & a2
   Debug.Print
End Sub

'Function with a local static variable
Function StaticVariable() As Integer
   'Declare and initialize variable i
   Static i As Integer 'i has static storage duration
   
   i = i + 1 'VB style increment

   StaticVariable = i 'return the value of i
End Function

'Local variable with static storage duration
Sub f022()
   Dim i1 As Integer, i2 As Integer, i3 As Integer

   'Call the function with the local static variable
   i1 = StaticVariable()

   'Call the same function again
   i2 = StaticVariable()

   '... and again
   i3 = StaticVariable()

   Debug.Print "i1 = " & i1
   Debug.Print "i2 = " & i2
   Debug.Print "i3 = " & i3
End Sub


' *********************************************************************
'
' Arrays
'
' *********************************************************************

'Display one dimensional integer array
Sub DisplayArray(arr() As Integer, numElements As Integer)
   Dim n As Integer

   For n = 0 To numElements
      Debug.Print "arr[" & n & "] = " & arr(n)
   Next

   Debug.Print
End Sub

'Display one dimensional integer array in decending order
Sub DisplayArrayDesc(arr() As Integer, numElements As Integer)
   Dim n As Integer

   For n = numElements To 0 Step -1
      Debug.Print "arr[" & n & "] = " & arr(n)
   Next

   Debug.Print
End Sub

'Display two dimensional integer array
Sub Display2DimArray(arr() As Integer, numRows As Integer, numCols As Integer)
   Dim n As Integer, m As Integer

   For n = 0 To numRows
      For m = 0 To numCols
         Debug.Print "arr(" & n & ", " & m & ") = " & arr(n, m) & "    ";
      Next
      Debug.Print
   Next

   Debug.Print
End Sub

'In C an array is declared with this statement;
'  int arrFoo[SIZE_ARR_A];
'
'This statement declares an array of size SIZE_ARR_A. Valid
'index values are 0, 1, ..., SIZE_ARR_A - 1.
'
'The following statement declares a VB array;
'  Dim arrFoo(SIZE_ARR_A) As Integer
'
'It's important to note that the above sample VB code actually
'initializes an array of size SIZE_ARR_A + 1 with the folllowing
'valid index values 0, 1, ..., SIZE_ARR_A.
'
'The picture is further complicated by the possibility to
'specify an Option Base setting but it's a good programming
'practice to leave this setting at it's default value 0. In
'the latest incarnation of VB, VB.Net, the way arrays are
'handled is much closer to the way they are handled in C.
   
' Array declaration, set values and show values
Sub f023()
   'Declaration of counter variable i and array arrFoo
   Dim i As Integer, arrFoo(SIZE_ARR_A) As Integer

   'Set the values stored in the array
   For i = 0 To SIZE_ARR_A
      arrFoo(i) = (i + 1) * 10
   Next

   'Show the values stored in the array
   DisplayArray arrFoo, SIZE_ARR_A
   DisplayArrayDesc arrFoo, SIZE_ARR_A
End Sub

'Sum array elements and store the result in the first element of the array
Sub SumArrayElements(arr() As Integer, numElements As Integer)
   'Declare and initialize a counter variable
   Dim i As Integer
   
   'Reset the value of the first element of the array to 0
   arr(0) = 0

   'Sum the remaining elements and store the result in the first element
   For i = 1 To numElements
      arr(0) = arr(0) + arr(i)
   Next
End Sub

'Array initialization and passing an array to a function
Sub f024()
   'Declare array arrBar and initialize to the values in the initializer list
   Dim arrBar(SIZE_ARR_A) As Integer
   
   'Set array values
   arrBar(1) = 25
   arrBar(2) = 50
   arrBar(3) = 75
   arrBar(4) = 100

   'Show the values stored in the array
   DisplayArray arrBar, SIZE_ARR_A

   'Call the function SumArrayElements, pass arrBar as a parameter
   SumArrayElements arrBar, SIZE_ARR_A

   'Again show the values stored in the array
   DisplayArray arrBar, SIZE_ARR_A
End Sub

'Multi-dimensional array
Sub f025()
   Dim arr(1, 2) As Integer
   arr(0, 0) = 1: arr(0, 1) = 2: arr(0, 2) = 3
   arr(1, 0) = 4: arr(1, 1) = 5: arr(1, 2) = 6
   
   Display2DimArray arr, 1, 2
End Sub

'Using a pointer to traverse an array
Sub f026()
   Debug.Print "No such thing as pointers in VB"
End Sub


' *********************************************************************
'
' Pointers and dynamic memory allocation
'
' ******************************************************************* *

'Pointers and references
Sub f027()
   'The use of pointers is not supported in VB. It is therefore uncommon
   'for a Visual Basic programmer to have the need to gain access to low
   'level information on a variable, such as its memory address. There
   'are however a number of (unsupported) functions, like VarPtr, that
   'provide this access when needed. More information; Microsoft support
   'article Q199824
   
   'Use the Dim statement to declare the data type of a variable and to
   'allocate storage space
   Dim n As Integer: n = 3 'Declare variable n and assign the value 3
   
   'In Visual Basic references do exist but they can't be set to basic
   'data types. For more information regarding (object) references in VB
   'please consult the examples in sub procedure f028

   Debug.Print "The value of n     = " & n
   Debug.Print "The address of n   = " & VarPtr(n)
   Debug.Print
End Sub

'Dynamic memory allocation
Sub f028()
   'Use the Dim statement to declare the object type of a variable
   Dim objCollection As Collection
   
   'At this point the variable of type Collection doesn't yet reference an
   'object instance and has the special value Nothing
   Debug.Assert objCollection Is Nothing
   
   'When New is used in conjuction with Set, it creates a new instance of
   'the class to which it is applied and a reference to the object instance
   'is stored in the variable which is set. In case this variable already
   'contained a reference, that reference is released when the new one is
   'assigned.
   Set objCollection = New Collection
   
   'The variable of type Collection now holds a reference to the newly
   'instantiated object
   Debug.Assert Not (objCollection Is Nothing)

   'Add items to the Collection object
   objCollection.Add Item:="Bakkerij Bierhuizen B.V.", Key:="271953850006"
   objCollection.Add Item:="Bram Ladage Holding B.V.", Key:="242164120000"

   'Change the way errors are handled
   On Error GoTo ErrHandler

   'Retrieve specific key values from the Collection object
   Debug.Print objCollection.Item("242164120000") 'This key will be located
   Debug.Print objCollection.Item("090453630000") 'This key is not available
   Debug.Print

   'Declare a variable of type Object. The Object data type is specifically
   'designed for storing object references.
   Dim objRefColl As Object
   
   'Set a reference to the previously instantiated Collection object
   Set objRefColl = objCollection

   'Use the object reference to add an item to the Collection object
   objRefColl.Add Item:="Grolsch Café 't Pumpke", Key:="090453630000"

   'Retrieve specific key values from the Collection object
   Debug.Print objRefColl.Item("242164120000")
   Debug.Print objCollection.Item("090453630000")
   Debug.Print
   
   'Revert to the default way of error handling
   On Error GoTo 0
   
   Exit Sub

ErrHandler:
    Debug.Print "Error occured"
    Resume Next
End Sub

'Dynamic memory allocation for arrays
Sub f029()
   'Declare a dynamic array using Dim and a empty dimension list
   Dim DynArrQ() As Integer

   'Allocate the actual number of elements using ReDim
   ReDim DynArrQ(SIZE_ARR_A)

   'Set the values contained in the array
   Dim i As Integer

   For i = 0 To UBound(DynArrQ)
      DynArrQ(i) = i
   Next

   'Show the contents of the array
   DisplayArray DynArrQ, UBound(DynArrQ)
   
   'Now enlarge the array while preserving the existing content
   ReDim Preserve DynArrQ(UBound(DynArrQ) + 3)
   
   'Set the value of the additional elements
   For i = SIZE_ARR_A + 1 To UBound(DynArrQ)
      DynArrQ(i) = i * 10
   Next
   
   'Show the contents of the array
   DisplayArray DynArrQ, UBound(DynArrQ)
End Sub

'Function pointers
Sub f030()
   Debug.Print "No such thing as function pointers in VB"
End Sub


' *********************************************************************
'
' Application entry point
'
' ****************************************************************** */
Sub main()
   'Declarations section
   Dim iFunction As Integer
   iFunction = InputBox("Specify function to run", "Run Function")
   Select Case (iFunction)
      Case 1: f001
      Case 2: f002
      Case 3: f003
      Case 4: f004
      Case 5: f005
      Case 6: f006
      Case 7: f007
      Case 8: f008
      Case 9: f009
      Case 10: f010
      Case 11: f011
      Case 12: f012
      Case 13: f013
      Case 14: f014
      Case 15: f015
      Case 16: f016
      Case 17: f017
      Case 18: f018
      Case 19: f019
      Case 20: f020
      Case 21: f021
      Case 22: f022
      Case 23: f023
      Case 24: f024
      Case 25: f025
      Case 26: f026
      Case 27: f027
      Case 28: f028
      Case 29: f029
      Case 30: f030
      Case Else: Debug.Print "Invalid function number specified"
   End Select
End Sub



