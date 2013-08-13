// *********************************************************************
//
// Intermediate C++ coding examples
//
// intermediate.cpp is a C++ (intermediate level) cheat sheet
// copyright 2009 Hans de Rooij
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
//    g++ intermediate.cpp -o intermediate
//
// *********************************************************************

#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include <algorithm>
#include <fstream>

//Disable irrelevant Microsoft Visual C compiler warnings
#ifdef _MSC_VER
   #pragma warning (disable : 4244)
   #pragma warning (disable : 4305)
   #pragma warning (disable : 4996)
#endif

using namespace std;

//C++ doesn't contain standard functions for converting a string to either
//upper- or lowercase. It's preferable to develop locale dependent versions
//of these functions. Below a quick 'n dirty alternative
void str_conv(string& str_in, int(*fpChrConv)(int))
{
   transform(str_in.begin(), str_in.end(), str_in.begin(), fpChrConv);
}


// *********************************************************************
//
// Characters & C-style strings
//
// *********************************************************************

//Character functions
void f001()
{
   string str = "The man yelled \"##**!!!\" for a 2nd time.";
   
   string str1, str2, str3, str4;
   string str5, str6, str7, str8;
   
   string::size_type i, len;

   int j1 = 0, j2 = 0, j3 = 0, j4 = 0, j5 = 0, j6 = 0;

   len = str.length();

   for(i = 0; i < len; i++)
   {
      if(islower(str[i])) str1 += str[i];
      if(isupper(str[i])) str2 += str[i];
      if(isdigit(str[i])) str3 += str[i];
      if(isalpha(str[i])) str4 += str[i];
      if(isspace(str[i])) str5 += str[i];
      if(ispunct(str[i])) str6 += str[i];
   }

   str7 = str; str_conv(str7, tolower);
   str8 = str; str_conv(str8, toupper);

   cout << "Started with string: " << str << endl;
   cout << "islower -> " << str1 << endl;
   cout << "isupper -> " << str2 << endl;
   cout << "isdigit -> " << str3 << endl;
   cout << "isalpha -> " << str4 << endl;
   cout << "isspace -> " << str5 << endl;
   cout << "ispunct -> " << str6 << endl;
   cout << "tolower -> " << str7 << endl;
   cout << "toupper -> " << str8 << endl;

   return;
}

#ifdef __GNUG__
   //Flush the keyboard buffer
   void FlushKeybBuff()
   {
      char ch;
      while((ch = cin.get()) != '\n' && ch != EOF)
      return;
   }
#else
   //Flush the keyboard buffer
   void FlushKeybBuff()
   {
      cin.sync();
      return;
   }
#endif

//Display character pointer information
void DisplayCharPtr(const char* p2str)
{
   cout << "The content of the string is    : " << p2str << endl;
   cout << "The length of string is         : " << strlen(p2str) << endl;

   return;
}

//Display character array information
void DisplayCharArr(const char* p2str, size_t str_buff_size)
{
   DisplayCharPtr(p2str);
   cout << "The size of the string buffer is: " << str_buff_size << endl;

   return;
}

//Display string information
void DisplayString(const string& str)
{
   cout << "The content of the string is    : " << str << endl;
   cout << "The length of string is         : " << str.length() << endl;

   return;
}

//C-style strings basics
void f002()
{
   //It's possible to use C-style strings in C++

   //A C-style string is a null terminated array of characters,
   //so this might be unconventional but is syntactically correct
   char str1[] = {'1','s','t',' ','s','t','r','i','n','g','\0'};

   //This is the conventional way to declare and initialize a string
   char str2[] = "String two is declared and initialized";

   //... and this is basically the same way as the conventional way
   //but using pointer notation
   const char* p2char_a = "Using pointer notation";

   //It's also possible to explicitly specify the width of the buffer
   char str3[80] = "1234";

   //In C++ it's preferable however to use objects of type string
   string stl_str1 = str1; //Initialize object C-style string
   string stl_str2 = "STL string is declared and initialized";
   string stl_str3, stl_str4;
   string* p2str = new string("Pointer to string object");

   //Reading a string object from the standard input stream
   printf("Enter a string: "); getline(cin, stl_str4);
   cout << endl;

   //Miscellaneous variables
   int i; double dbl;

   //String conversion functions
   stl_str3 = "12345";
   i = atoi(str3);
   dbl = i + atof("0.5");

   //Display the string information to the user
   DisplayCharArr(str1, sizeof(str1)); cout << endl;
   DisplayCharArr(str2, sizeof(str2)); cout << endl;
   DisplayCharPtr(p2char_a); cout << endl;
   DisplayCharArr(str3, sizeof(str3)); cout << endl;

   DisplayString(str1); cout << endl;
   DisplayString(stl_str2); cout << endl;
   DisplayString(*p2str); cout << endl;
   DisplayString(stl_str3); cout << endl;
   DisplayString(stl_str4); cout << endl << endl;

   cout << "String conversion results: " << str3 
      << " + 0.5 = " << fixed << setprecision(2) << dbl << endl;

   delete p2str; //Release the memory associated with p2str

   return;
}

//C-style string library functions as defined in header file string.h
void f003()
{
   //Declaration and initialization section
   string str1 = "BCDE";
   string* p2str_a;
   string::size_type pos_1, pos_2, pos_3, str_length;
   int cmp;

   //Dynamic string allocation
   p2str_a = new string;

   //Copy the contents of str1 to p2str_a dereferenced
   *p2str_a = str1;

   //String concatenation
   *p2str_a += " ";  //first add a string literal
   *p2str_a += str1; //then add the contents of str1

   //Assign a different value to str1
   str1 = "ABC";
   //str1 = "BCDE BCDE";
   //str1 = "CDE";

   //Determine the length of a string
   str_length = (*p2str_a).length();

   //Compare two strings
   cmp = str1.compare(*p2str_a); //more detail below

   //Search a string (left to right) for a specific character
   pos_1 = (*p2str_a).find('C');
   
   //Search a string (right to left) for a specific character
   pos_2 = (*p2str_a).rfind('C');
   
   //Search a string for another string
   pos_3 = (*p2str_a).find("DE"); //method find is overloaded

   //Display the outcome of the string manipulations
   cout << "str1     = " << str1 << endl;
   cout << "*p2chr_a = " << *p2str_a << " (length is " << str_length << ")";
   cout << endl << endl;

   cout << "String compare result -> cmp = str1.compare(*p2str_a)";
   cout << endl;
   if(cmp == 0)
      cout << "str1 equals *p2str_a";
   else if(cmp < 0)
      cout << "str1 comes before *p2str_a";
   else //cmp > 0
      cout << "str1 comes after *p2str_a";
   cout << endl << endl;

   if(pos_1 != string::npos) cout << "Located the character at "
      << pos_1 << endl;
   if(pos_2 != string::npos) cout << "Located the character at "
      << pos_2 << endl;
   if(pos_3 != string::npos) cout << "Located the search string at "
      << pos_3 << endl;

   delete p2str_a; //Release the memory associated with p2str_a

   return;
}


// *********************************************************************
//
// Miscellaneous intermediate level coding examples involving;
//    * The use of classes
//    * Data structures like linked lists and binary trees
//    * File reading and writing in text and binay formats
//
// *********************************************************************

//Class for storing information related to to vowels found
class Vowel
{
private: //Private is the default access specifier  
   char chr;
   int iLine;
   int iPos;
   int DoCompare(Vowel&);

public: //The declaration of the public interface of the class
   Vowel(char, int, int);      //Constructor
   ~Vowel();                   //Destructor
   char getVowel();            //Accessor functions
   void setVowel(char);
   int getLine();
   void setLine(int);
   int getPos();
   void setPos(int);
   bool operator==(Vowel&);    //Overloaded operators
   bool operator>(Vowel&);

private: //Friend functions of the class
   friend ostream& operator<<(ostream&, Vowel&);
};

//Rudimentary container class for the vowels located
class LinkedList
{
private:
   //Nested class for defining nodes in the linked list
   class LinkedListNode
   {
   public:
      Vowel* vwl;
      LinkedListNode* nextLln;

      //Constructors, default constructor and two arguments
      LinkedListNode();
      LinkedListNode(Vowel*, LinkedListNode*);
      ~LinkedListNode(); //Destructor
   };

   LinkedListNode* firstLln;

public:
   LinkedList();  //Default constructor
   ~LinkedList(); //Destructor

   //Add a vowel object to the linked list
   void addVwl(Vowel*);

private: //Friend functions of the class
   friend ostream& operator<<(ostream&, LinkedList&);
};

//Implement private function DoCompare of the Vowel class
int Vowel::DoCompare(Vowel& otherVwl)
{
   int iResult;

   //First make a case insensitive comparison of the vowels
   if((iResult = toupper(this->chr) - toupper(otherVwl.chr)) == 0)
   {
      //If the vowels are equal compare the lines on which they are found
      if((iResult = this->iLine - otherVwl.iLine) == 0)
      {
         //Let the character position be the final decider
         iResult = this ->iPos - otherVwl.iPos;
      }
   }

   return iResult;
}

//Implementation of the Vowel class, constructor
Vowel::Vowel(char vwl, int line, int pos)
{
   #ifdef _DEBUG
      cout << "In constructor of Vowel object" << endl;
   #endif

   chr = vwl;
   iLine = line;
   iPos = pos;
}

//Implementation of destructor of the Vowel class
Vowel::~Vowel()
{
   #ifdef _DEBUG
      cout << "In destructor of Vowel object" << endl;
   #endif
}

//Retrieve the value of the vowel property
char Vowel::getVowel()
{
   return chr;
}

//Set the value of the vowel property
void Vowel::setVowel(char vwl)
{
   chr = vwl;
   return;
}

//Retrieve the value of the line property
int Vowel::getLine()
{
   return iLine;
}

//Set the value of the line property
void Vowel::setLine(int line)
{
   iLine = line;
   return;
}

//Retrieve the value of the position property
int Vowel::getPos()
{
   return iPos;
}

//Set the value of the position property
void Vowel::setPos(int pos)
{
   iPos = pos;
   return;
}

//Implement overloaded operator == for the Vowel class
bool Vowel::operator==(Vowel& otherVwl)
{
   return DoCompare(otherVwl) == 0;
}

//Implement overloaded operator > for the Vowel class
bool Vowel::operator>(Vowel& otherVwl)
{
   return DoCompare(otherVwl) > 0;
}

//The overloaded insertion operator is a friend of the Vowel class
ostream& operator<<(ostream& os, Vowel& aVwl)
{
   return os << "Vowel " << aVwl.chr << " located on line " << aVwl.iLine <<
      " at position " << aVwl.iPos;
}

//Default constructor for a linked list node
LinkedList::LinkedListNode::LinkedListNode()
{
   #ifdef _DEBUG
      cout << "In default constructor of LinkedListNode object" << endl;
   #endif

   //Call the two argument constructor
   LinkedListNode(NULL, NULL);
}

//Two argument constructor for a linked list node
LinkedList::LinkedListNode::LinkedListNode(Vowel* aVwl, LinkedListNode* aLln)
{
   #ifdef _DEBUG
      cout << "In two arg constructor of LinkedListNode object" << endl;
   #endif

   vwl = aVwl;
   nextLln = aLln;
}

//linked list node destructor
LinkedList::LinkedListNode::~LinkedListNode()
{
   #ifdef _DEBUG
      cout << "In destructor of LinkedListNode object" << endl;
   #endif
}

//Default constructor LinkedList class
LinkedList::LinkedList()
{
   #ifdef _DEBUG
      cout << "In default constructor of LinkedList object" << endl;
   #endif

   firstLln = NULL;
}

//Implementation of destructor of the LinkedList class
LinkedList::~LinkedList()
{
   #ifdef _DEBUG
      cout << "In destructor of LinkedList object" << endl;
   #endif

   //Start with the first node in the list
   LinkedListNode* aLln = firstLln;
   LinkedListNode* tmpLln;

   while(aLln) //Loop through the entire list
   {
      //Clean up the Vowel object
      delete aLln->vwl;

      //Cleanup the linked list node
      tmpLln = aLln;
      aLln = aLln->nextLln;
      delete tmpLln;
   }
}

//Add a vowel object to the linked list
void LinkedList::addVwl(Vowel* aVwl)
{
   LinkedListNode* llnBefore = NULL;
   LinkedListNode* llnAfter = firstLln;

   //Loop until the insertion point in the list is reached
   while(llnAfter != NULL && *aVwl > *(llnAfter->vwl))
   {
      llnBefore = llnAfter;
      llnAfter = llnAfter->nextLln;
   }

   //Insert the node to store at the beginning of the list
   if(llnBefore == NULL)
   {
      firstLln = new LinkedListNode(aVwl, firstLln);
   }
   else
   {
      llnBefore->nextLln = new LinkedListNode(aVwl, llnAfter);
   }

   return;
}

//The overloaded insertion operator is a friend of the LinkedList class
ostream& operator<<(ostream& os, LinkedList& aLl)
{
   //Start with the first node in the list
   LinkedList::LinkedListNode* aLln = aLl.firstLln;

   while(aLln)
   {
      os << *(aLln->vwl) << endl; //Insert the vowel in the output stream
      aLln = aLln->nextLln;       //Set the pointer to the next node
   }

   return os;
}

int f004()
{
   //Declaration and initialization section
   int errValue = 0;
   ifstream InFile;
   ofstream OutFile;
   string str1;
   string str2 = "aeiouAEIOU";
   string::size_type posVwl;
   LinkedList ll;
   Vowel* aVwl;
   int i = 1;
   
   //Open a file for sequential read
   InFile.open("seinfeld.txt");

   //Read the file sequentially and build the linked list
   if(InFile.is_open())
   {
      while(!InFile.eof())
      {
         getline(InFile, str1);

         //Find the first vowel in the line read
         posVwl = str1.find_first_of(str2);

         //If applicable, loop through all the vowels in the string
         while(posVwl != string::npos)
         {
            //Create a new Vowel object on the heap
            aVwl = new Vowel(str1[posVwl], i, posVwl);

            //Add the newly instantiated object to the list
            ll.addVwl(aVwl);

            //Find the next vowel
            posVwl = str1.find_first_of(str2, posVwl + 1);
         }

         i++; //Next line
      }

      //The input file can now be closed
      InFile.close();
   }
   else //Error occurred while opening the input file
   {
      errValue = -1; goto ERR_HANDLER; //Unconditional branching using goto!
   }

   //Open a file for sequential write
   OutFile.open("vowels.txt", ios::out | ios::trunc);

   if(OutFile.is_open())
   {
      //Write the contents of the linked list to a file
      OutFile << ll << endl;
   }
   else //Error occurred while opening the output file
   {
      errValue = -2; goto ERR_HANDLER;
   }

   //Let the user know that everything went according to plan
   cout << "Successfully completed processing and wrote file vowels.txt" << endl;

ERR_HANDLER:
   //Show error message in case of error
   switch(errValue)
   {
      case -1: cout << "Error opening input file, terminating ..." << endl << endl; break;
      case -2: cout << "Error opening output file, terminating ..." << endl << endl; break;
   }

   //Close the files used in this program (if necessary)
   if(InFile.is_open()) InFile.close();
   if(OutFile.is_open()) OutFile.close();

   return errValue;
}
/*
//Do you know the Seinfeld regulars?
struct seinfeldCharacter
{
   int iCharacterID; //Seinfeld character identifier
   char sName[32];   //Name of the character
};

//Create an alias for data type struct seinfeldCharacter (optional)
typedef struct seinfeldCharacter SeinfeldCharacter;

//Declare a structure used for building a binary tree
struct bTreeNode
{
   int iCharacterID; //Seinfeld character identifier
   long pos;         //Offset in the binary file
   struct bTreeNode* LeftChild;
   struct bTreeNode* RightChild;
};

//Create an alias for data type struct bTreeNode (optional)
typedef struct bTreeNode BTreeNode;

//Determine the maximum number of records the file can hold
int iGetMaxNRs(FILE* File)
{
   long lPos;

   //Set the file position pointer to the end of the file
   fseek(File, 0, SEEK_END);

   lPos = ftell(File);

   //Reset the file position pointer
   fseek(File, 0, SEEK_SET);

   return (lPos / sizeof(SeinfeldCharacter));
}

//Show node contents
void ShowBTreeNodeContents(FILE* File, BTreeNode* BTN)
{
   SeinfeldCharacter SFC;

   //Position the file position pointer and read character info
   fseek(File, BTN->pos, SEEK_SET);
   fread(&SFC, sizeof(SeinfeldCharacter), 1, File);

   //List the content associated with the node
   printf("%d. %s\n", BTN->iCharacterID, SFC.sName);

   return;
}

//List the contents of file in ascending order
void ListBTreeContentsAsc(FILE* File, BTreeNode* BTN)
{
   if(BTN != NULL)
   {
      //Recursive call in search of a smaller identifier
      ListBTreeContentsAsc(File, BTN->LeftChild);

      ShowBTreeNodeContents(File, BTN);

      //Recursive call in search of a larger identifier
      ListBTreeContentsAsc(File, BTN->RightChild);
   }

   return;
}

//List the contents of file in descending order
void ListBTreeContentsDesc(FILE* File, BTreeNode* BTN)
{
   if(BTN != NULL)
   {
      //Recursive call in search of a larger identifier
      ListBTreeContentsDesc(File, BTN->RightChild);

      ShowBTreeNodeContents(File, BTN);

      //Recursive call in search of a smaller identifier
      ListBTreeContentsDesc(File, BTN->LeftChild);
   }

   return;
}

//Search for a node with a particular ID
BTreeNode* SearchBTree(BTreeNode* BTN, int iID)
{
   //ID searched is smaller than the current key, go left
   if(iID < BTN->iCharacterID)
   {
      if(BTN->LeftChild == NULL)
      {
         return NULL;
      }
      else
      {
         return SearchBTree(BTN->LeftChild, iID);
      }
   }
   //ID searched is larger than the current key, go right
   else if(iID > BTN->iCharacterID)
   {
      if(BTN->RightChild == NULL)
      {
         return NULL;
      }
      else
      {
         return SearchBTree(BTN->RightChild, iID);
      }
   }
   //Located the ID!
   else
   {
      return BTN;
   }
}

//Free the resources associated with the binary tree index
void CleanUpBTreeIndex(BTreeNode* BTN)
{
   if(BTN != NULL)
   {
      //Recursive call in search of a smaller identifier
      CleanUpBTreeIndex(BTN->LeftChild);

      //Recursive call in search of a larger identifier
      CleanUpBTreeIndex(BTN->RightChild);

      //List the content associated with the node
      #ifdef _DEBUG
         printf("Clean up node with ID %d\n", BTN->iCharacterID);
      #endif

      free(BTN);
   }

   return;
}

//Create a new database containing the quintessential Seinfeld characters
int CreateNewBinFile(FILE** File)
{
   SeinfeldCharacter SFC[7]; //An array of Seinfeld characters
   SeinfeldCharacter EmptySFC = {0, ""}; //Empty Seinfeld character
   int i;

   assert(*File == NULL);

   //Open a file for binary write, create or truncate
   *File = fopen("seinfeld.dat", "wb");

   //Handle errors that might have occured while opening the file
   if(*File == NULL) return -1;

   //The regular cast
   SFC[0].iCharacterID = 40; strcpy(SFC[0].sName, "Elaine");
   SFC[1].iCharacterID = 20; strcpy(SFC[1].sName, "George");
   SFC[2].iCharacterID = 10; strcpy(SFC[2].sName, "Jerry");
   SFC[3].iCharacterID = 60; strcpy(SFC[3].sName, "Babu");
   SFC[4].iCharacterID = 50; strcpy(SFC[4].sName, "Newman");
   SFC[5].iCharacterID = 80; strcpy(SFC[5].sName, "Uncle Leo");
   SFC[6].iCharacterID = 30; strcpy(SFC[6].sName, "Kramer");

   //Write the entire array to the binary file
   fwrite(SFC, sizeof(SeinfeldCharacter), 7, *File);

   //Add a number of empty records to the file
   for(i = 7; i < 24; i++)
   {
      fwrite(&EmptySFC, sizeof(SeinfeldCharacter), 1, *File);
   }

   //All the writing is now done, close the file
   fclose(*File);

   //Open the newly created binary file for read & write
   *File = fopen("seinfeld.dat", "rb+");

   //Handle errors that might have occured while opening the file
   if(*File == NULL) return -2;

   return 0;
}

//Insert a new node in the binary tree
int InsNodeInBTree(BTreeNode** BTRoot, BTreeNode* BTCurrNode,
                      BTreeNode* BTNewNode)
{
   int iRet = 0;

   if(*BTRoot == NULL) //The tree is completely empty
   {
      *BTRoot = BTNewNode;

      #ifdef _DEBUG
         printf("New root, with ID %d\n\n", (*BTRoot)->iCharacterID);
      #endif
   }
   else //Find the correct spot in the tree
   {
      //Start of searching at the root of the tree
      if(BTCurrNode == NULL) BTCurrNode = *BTRoot;

      //In case the new key is smaller than the current key, go left
      if(BTNewNode->iCharacterID < BTCurrNode->iCharacterID)
      {
         if(BTCurrNode->LeftChild == NULL) //Insertion point located
         {
            BTCurrNode->LeftChild = BTNewNode;

            #ifdef _DEBUG
               printf("Placed in tree, left of node with ID %d\n\n",
                         BTCurrNode->iCharacterID);
            #endif
         }
         else
         {
            #ifdef _DEBUG	
               printf("Continue search left of node with ID %d\n",
                         BTCurrNode->iCharacterID);
            #endif

            //Use a recursive call to continue the search
            iRet = InsNodeInBTree(BTRoot, BTCurrNode->LeftChild, BTNewNode);
         }
      }
      //In case the new key is larger than the current key, go right
      else if(BTNewNode->iCharacterID > BTCurrNode->iCharacterID)
      {
         if(BTCurrNode->RightChild == NULL) //Insertion point located
         {
            BTCurrNode->RightChild = BTNewNode;

            #ifdef _DEBUG
               printf("Placed in tree, right of node with ID %d\n\n",
                         BTCurrNode->iCharacterID);
            #endif
         }
         else
         {
            #ifdef _DEBUG
               printf("Continue search right of node with ID %d\n",
                         BTCurrNode->iCharacterID);
            #endif

            //Use a recursive call to continue the search
            iRet = InsNodeInBTree(BTRoot, BTCurrNode->RightChild, BTNewNode);
         }
      }
      //No duplicate keys allowed
      else
      {
         #ifdef _DEBUG
            printf("No duplicate keys allowed, ID %d\n\n",
                      BTNewNode->iCharacterID);
         #endif

         iRet = -1;
      }
   }

   return iRet;
}

//Create a new Seinfeld character, write to file and add to binary tree
void CreateNewSFC(FILE* File, BTreeNode** BTRoot, int* NRs, int iID)
{
   SeinfeldCharacter SFC;
   char* p2char = NULL;
   long lpos;
   BTreeNode* BTN;
   #ifdef __GNUC__
      int bytes_read; size_t buff_size = 32;
   #endif

   //Before calling this function please make sure that;
   //1. The user has indicated that he or she wants to create a new character
   //2. a non-existing ID was specified for the character to be created (iID)
   //3. there is sufficient room available on the database for record creation
   SFC.iCharacterID = iID;

   //Prompt the user for the name of the character to be added
   printf("Enter character name: ");

   #ifdef __GNUC__
      //Use function getline to read the string from stdin
      bytes_read = getline(&p2char, &buff_size, stdin);

      //Handling of error condition (bytes_read == -1) not implemented

      //Discard the newline character that is read by function getline
      DiscardNewLineChar(p2char);
   #else
      //Dynamic string allocation, reserve a buffer for a C-style string
      //at run-time
      #ifdef __cplusplus 
         p2char = (char*)calloc(STR_BUFF, sizeof(char));
      #else
         p2char = calloc(STR_BUFF, sizeof(char));
      #endif
   
      //Note that function gets is considered to be a security risk because
      //there is no protection against buffer overflows!
      gets(p2char);
   #endif

   //Copy the name specified by the user to the struct
   strncpy(SFC.sName, p2char, 32); SFC.sName[31] = '\0';
   free(p2char); //Temporary buffer is no longer needed

   putchar('\n');

   //Position the file position pointer and store the pointer value
   fseek(File, *NRs * sizeof(SeinfeldCharacter), SEEK_SET);
   lpos = ftell(File);

   //Execute the write of the newly created character
   fwrite(&SFC, sizeof(SeinfeldCharacter), 1, File);

   //Call malloc to reserve memory for storing a node
   #ifdef __cplusplus
      BTN = (BTreeNode*)malloc(sizeof(BTreeNode));
   #else
      BTN = malloc(sizeof(BTreeNode));
   #endif

   //Set the properties of the binary tree node
   BTN->iCharacterID = SFC.iCharacterID;
   BTN->pos = lpos;
   BTN->LeftChild = NULL;
   BTN->RightChild = NULL;

   //Insert the node read from file in the binary tree
   InsNodeInBTree(BTRoot, NULL, BTN);

   //Reflect the record creation in the record count
   (*NRs)++;

   return;
}

//Create a binary tree index on the file
int CreateBTreeIndex(FILE* File, BTreeNode** BTRoot)
{
   int NRs, numStructs; long lpos;
   SeinfeldCharacter SFC;
   BTreeNode* BTN;

   //Position the file position pointer at the beginning of the file
   rewind(File);

   //Reset the variable for storing the number of records on the file
   NRs = 0;

   //Index all the Seinfeld characters available on the file. Read one
   //structure at a time, escape from the loop using break when;
   //1. Read beyond the EOF occurs or
   //2. First empty stucture is read
   while(1)
   {
      //Store the value currently held by the file position pointer
      lpos = ftell(File);

      //Read the next struct from the binary file
      numStructs = fread(&SFC, sizeof(SeinfeldCharacter), 1, File);

      //Specifying !feof(File) as a condition for the while loop won't work!
      //The EOF flag is only set when an attempt is made to read beyond the
      //last byte of data. Reading up to and including the last byte of data
	  //does not set the EOF flag.
      if(numStructs != 1)
      {
         if(ferror(File))
         {
            #ifdef _DEBUG
               printf("Error occured while reading the file\n\n");
            #endif
            return -1; //Exit from the function and return a negative value
         }
         else
         {
            assert(feof(File));
            break; //Break out of the loop and return the number of records
         }
      }

      #ifdef _DEBUG
         printf("Read \"%s\" with ID %d\n", SFC.sName, SFC.iCharacterID);
      #endif

      //Exit from loop when reading the first empty stucture
      if(SFC.iCharacterID == 0) break;

      //Call malloc to reserve memory for storing a node
      #ifdef __cplusplus
         BTN = (BTreeNode*)malloc(sizeof(BTreeNode));
      #else
         BTN = malloc(sizeof(BTreeNode));
      #endif

      //Set the properties of the binary tree node
      BTN->iCharacterID = SFC.iCharacterID;
      BTN->pos = lpos;
      BTN->LeftChild = NULL;
      BTN->RightChild = NULL;

      //Insert the node read from file in the binary tree
      if(InsNodeInBTree(BTRoot, NULL, BTN) != 0)
      {
         //Release the resources associated with the newly created node
         free(BTN);

         return -2;
      }

      NRs++;
   }

   #ifdef _DEBUG
      if(NRs == 0)
         printf("No Seinfeld characters available on the file\n\n");
      else
         printf("Successfully read & indexed %d records\n\n", NRs);
   #endif

   return NRs;
}

//Let the user specify either yes or no
char GetUserYesOrNo(const char* sPrompt)
{
   char chrYesNo;

   printf("%s (y\\n): ", sPrompt);
   scanf("%c", &chrYesNo); FlushKeybBuff();
   putchar('\n');

   //Count a 'Y' as a 'y'
   return tolower(chrYesNo);
}

//Let the user specify his or her preferred option
char GetUserOption()
{
   char chr;

   printf("Enter your choice\n"
          " a. Find Seinfeld character\n"
          " b. List file contents in ascending order\n"
          " c. List file contents in descending order\n"
          " q. Exit\n\n"
          "? ");

   //Get the user input
   scanf("%c", &chr); FlushKeybBuff();
   putchar('\n');

   //Allow for upper- and lowercase option entry
   return tolower(chr);
}

//Build and manipulate a binary tree of Seinfeld characters
int f005()
{
   //Declaration and initialization section
   int errValue = 0, iMaxNumRecs, iNumRecs, iID;
   FILE* BinFile = NULL;
   BTreeNode* BTreeRoot = NULL;
   BTreeNode* BTNode = NULL;
   char chrOption;

   //Open the binary file, if NULL is returned special handling is required
   if((BinFile = fopen("seinfeld.dat", "rb+")) == NULL)
   {
      if(errno != ENOENT) //File exists but access attempt results in error
      {
         //Database locked, no rights, ...
         errValue = -1; goto ERR_HANDLER; 
      }

      //From this point on errno == ENOENT (no such file or directory)
      if(GetUserYesOrNo("No data file! Create new file?") != 'y')
      {
         //No database and user doesn't want to create one
         errValue = -2; goto ERR_HANDLER;
      }

      //Create a new binary database file
	  if(CreateNewBinFile(&BinFile) == 0)
      {
         printf("Successfully created a new binary data file\n\n");
      }
      else
      {
         //No rights, disk full, ...
         errValue = -3; goto ERR_HANDLER;
      }
   }

   assert(BinFile != NULL);

   //Determine the maximum number of records that the file can store
   if((iMaxNumRecs = iGetMaxNRs(BinFile)) == 0)
   {
      //File too small to hold any records
      errValue = -4; goto ERR_HANDLER;
   }

   //Build the file index
   if((iNumRecs = CreateBTreeIndex(BinFile, &BTreeRoot)) < 0)
   {
      //Error occured building index, posibly a duplicate ID
      errValue = -5; goto ERR_HANDLER;
   }

   printf("Read %d records, maximum number of records is %d\n\n",
             iNumRecs, iMaxNumRecs);

   //The application functionality is exposed to the user in this loop
   while((chrOption = GetUserOption()) != 'q')
   {
      switch(chrOption)
      {
         case 'a': //Find Seinfeld character

            //Prompt the user for a character ID
            printf("Please specify a character identifier: ");
            scanf("%d", &iID); FlushKeybBuff();
            putchar('\n');

            //Reset the node pointer
            BTNode = NULL;

            //Search the tree for the ID specified
            if(iNumRecs > 0) BTNode = SearchBTree(BTreeRoot, iID);

            if(BTNode != NULL) //Located ID
            {
               ShowBTreeNodeContents(BinFile, BTNode);
               putchar('\n');
            }
            else //ID not found
            {
               printf("Unable to locate identifier %d\n\n", iID);

               if(iNumRecs < iMaxNumRecs) //Space available on the file
               {
                  if(GetUserYesOrNo("Create a new character?") == 'y')
                  {
                     //Create a new Seinfeld character with ID iID &
                     //Write the character information to the database &
                     //Insert the new character in the binary tree
                     CreateNewSFC(BinFile, &BTreeRoot, &iNumRecs, iID);
                  }
               }
               else
               {
                  printf("No space available in binary file\n\n");
               }
            }

            break;

         case 'b': //List file contents (ascending)

            ListBTreeContentsAsc(BinFile, BTreeRoot);
            putchar('\n');

            break;

         case 'c': //List file contents (descending)

            ListBTreeContentsDesc(BinFile, BTreeRoot);
            putchar('\n');

            break;

         default:
            printf("Choice specified not valid\n\n");
      }
   }

ERR_HANDLER:
   //Show error message in case of error
   switch(errValue)
   {
      case -1: printf("Error opening file, terminating ...\n\n"); break;
      case -2: printf("No data file, terminating ...\n\n"); break;
      case -3: printf("Error creating file, terminating ...\n\n"); break;
      case -4: printf("File too small, terminating ...\n\n"); break;
      case -5: printf("File corrupt, terminating ...\n\n"); break;
   }

   //Release the allocated binary tree resources
   if(BTreeRoot) CleanUpBTreeIndex(BTreeRoot);

   //Close the connection to the binary file
   if(BinFile) fclose(BinFile);

   return errValue;
}
*/

// *********************************************************************
//
// Application entry point
//
// *********************************************************************

int main(int argc, char *argv[])
{
   //Declarations section
   int iFunction = 0;

   #ifdef __cplusplus
      cout << "Running C++ code" << endl << endl;
   #else
      cout << "Running C code" << endl << endl;
   #endif

   #ifdef _DEBUG
      cout << "Source code file   : " << __FILE__ << endl;
      cout << "Date of compilation: " << __DATE__ << endl;
      cout << "Time of compilation: " << __TIME__ << endl << endl;
   #endif

   if(argc == 1) //No command line parameters specified
   {
      cout << "Please specify the function to run: "; cin >> iFunction;
      FlushKeybBuff(); cout << endl;
   }
   else //User entered parameter on the command line
   {
      iFunction = atoi(argv[1]);
   }

   switch(iFunction)
   {
      case   1: f001(); break;
      case   2: f002(); break;
      case   3: f003(); break;
      case   4: f004(); break;
/*
      case   5: f005(); break;
*/
      default: cout << "Invalid function number specified" << endl;
   }

   return 0;
}
