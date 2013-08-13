// *********************************************************************
//
// Intermediate C coding examples
//
// intermediate.c is a C (intermediate level) cheat sheet
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
//    gcc intermediate.c -o cintermediate
// with debug messages
//    gcc -D_DEBUG intermediate.c -o cintermediate
//
// Compile using the GNU C++ compiler
//    g++ intermediate.c -o intermediate
//
// *********************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <errno.h>

//Disable irrelevant Microsoft Visual C compiler warnings
#ifdef _MSC_VER
   #pragma warning (disable : 4244)
   #pragma warning (disable : 4305)
   #pragma warning (disable : 4996)
#endif

#define STR_BUFF 80


// *********************************************************************
//
// Characters & C-style strings
//
// *********************************************************************

//Character functions
void f001()
{
   char str[] = "The man yelled \"##**!!!\" for a 2nd time.";
   
   char str1[STR_BUFF], str2[STR_BUFF], str3[STR_BUFF], str4[STR_BUFF];
   char str5[STR_BUFF], str6[STR_BUFF], str7[STR_BUFF], str8[STR_BUFF];
   
   size_t i, len;

   int j1 = 0, j2 = 0, j3 = 0, j4 = 0, j5 = 0, j6 = 0;

   len = strlen(str);

   for(i = 0; i < len; i++)
   {
      if(islower(str[i])) str1[j1++] = str[i];
      if(isupper(str[i])) str2[j2++] = str[i];
      if(isdigit(str[i])) str3[j3++] = str[i];
      if(isalpha(str[i])) str4[j4++] = str[i];
      if(isspace(str[i])) str5[j5++] = str[i];
      if(ispunct(str[i])) str6[j6++] = str[i];
      str7[i] = tolower(str[i]);
      str8[i] = toupper(str[i]);
   }

   str1[j1] = '\0'; str2[j2] = '\0';
   str3[j3] = '\0'; str4[j4] = '\0';
   str5[j5] = '\0'; str6[j6] = '\0';
   str7[i]  = '\0'; str8[i]  = '\0';

   printf("Started with string: %s\n", str);
   printf("islower -> %s\n", str1);
   printf("isupper -> %s\n", str2);
   printf("isdigit -> %s\n", str3);
   printf("isalpha -> %s\n", str4);
   printf("isspace -> %s\n", str5);
   printf("ispunct -> %s\n", str6);
   printf("tolower -> %s\n", str7);
   printf("toupper -> %s\n", str8);

   return;
}

#ifdef __GNUC__
   //Flush the keyboard buffer
   void FlushKeybBuff()
   {
      //For more information http://faq.cprogramming.com
      char ch;

      //Discard all characters in the buffer
      while((ch = getchar()) != '\n' && ch != EOF);

      return;
   }

   //Discard newline character at the end of a string
   void DiscardNewLineChar(char* p2str)
   {
      char* pLastChar;

      size_t str_length = strlen(p2str);

      if(str_length > 0)
      {
         pLastChar = p2str + str_length - 1;

         if(*pLastChar == '\n') *pLastChar = '\0';
      }

      return;
   }
#else
   //Flush the keyboard buffer
   void FlushKeybBuff()
   {
      //For more information http://support.microsoft.com/kb/42075
      fflush(stdin);
   }
#endif

//Display character pointer information
void DisplayCharPtr(const char* p2str)
{
   printf("The content of the string is    : %s\n", p2str);
   printf("The length of string is         : %u\n", strlen(p2str));

   return;
}

//Display character array information
void DisplayCharArr(const char* p2str, size_t str_buff_size)
{
   DisplayCharPtr(p2str);
   printf("The size of the string buffer is: %u\n", str_buff_size);

   return;
}

//C-style strings basics
void f002()
{
   //A C-style string is a null terminated array of characters,
   //so this might be unconventional but is syntactically correct
   char str1[] = {'1','s','t',' ','s','t','r','i','n','g','\0'};

   //This is the conventional way to declare and initialize a string
   char str2[] = "String two is declared and initialized";

   //... and this is basically the same way as the conventional way
   //but using pointer notation
   const char* p2char_a = "Using pointer notation";

   //It's also possible to explicitly specify the width of the buffer
   char str3[STR_BUFF] = "1234";

   //Miscellaneous variables
   char* p2char_b = NULL;
   int i; double dbl;
   #ifdef __GNUC__
      int bytes_read; size_t buff_size = STR_BUFF;
   #endif

   //Reading a C-style string from the standard input stream
   printf("Enter a string: ");

   #ifdef __GNUC__
      //Use function getline to read the string from stdin
      bytes_read = getline(&p2char_b, &buff_size, stdin);

      //Read from stdin failed, handle error
      if(bytes_read == -1) return;

      //Discard the newline character that is read by function getline
      DiscardNewLineChar(p2char_b);
   #else
      //Dynamic string allocation, reserve a buffer for a C-style string
      //at run-time
      #ifdef __cplusplus 
         p2char_b = (char*)calloc(STR_BUFF, sizeof(char));
      #else
         p2char_b = calloc(STR_BUFF, sizeof(char));
      #endif
   
      //Note that function gets is considered to be a security risk because
      //there is no protection against buffer overflows!
      gets(p2char_b);
   #endif

   //String conversion functions
   i = atoi(str3);
   dbl = i + atof("0.5");

   //Display the string information to the user
   putchar('\n');
   DisplayCharArr(str1, sizeof(str1)); putchar('\n');
   DisplayCharArr(str2, sizeof(str2)); putchar('\n');
   DisplayCharPtr(p2char_a); putchar('\n');
   DisplayCharArr(str3, sizeof(str3)); putchar('\n');
   DisplayCharPtr(p2char_b); putchar('\n');

   printf("String conversion results: %s + 0.5 = %.2f\n", str3, dbl);

   if(p2char_b) free(p2char_b);

   return;
}

//C-style string library functions as defined in header file string.h
void f003()
{
   //Declaration and initialization section
   char str1[STR_BUFF] = "BCDE";
   char* p2chr_a; char* p2chr_b;
   char* p2chr_c; char* p2chr_d;
   size_t str_length; int cmp;

   //Dynamic string allocation, reserve a buffer for a C-style string
   //at run-time
   #ifdef __cplusplus
      p2chr_a = (char*)calloc(STR_BUFF, sizeof(char));
   #else
      p2chr_a = calloc(STR_BUFF, sizeof(char));
   #endif

   //Copy the contents of str1 to the buffer associated with p2chr_a
   strcpy(p2chr_a, str1);

   //String concatenation
   strcat(p2chr_a, " ");  //first add a string literal
   strcat(p2chr_a, str1); //then add the contents of str1

   //Change the contents of str1 using strcpy
   strcpy(str1, "ABC");
   //strcpy(str1, "BCDE BCDE");
   //strcpy(str1, "CDE");

   //Determine the length of a string
   str_length = strlen(p2chr_a);

   //Compare two strings
   cmp = strcmp(str1, p2chr_a); //more detail on the result of strcmp below

   //Search a string (left to right) for a specific character
   p2chr_b = strchr(p2chr_a, 'C');   
   
   //Search a string (right to left) for a specific character
   p2chr_c = strrchr(p2chr_a, 'C');   
   
   //Search a string for another string
   p2chr_d = strstr(p2chr_a, "DE");

   //Display the outcome of the string manipulations
   printf("str1    = %s\n", str1);
   printf("p2chr_a = %s (length is %u)\n\n", p2chr_a, str_length);

   printf("String compare result -> cmp = strcmp(str1, p2chr_a)\n");
   if(cmp == 0)
      printf("The 1st parameter to strcmp equals the 2nd\n\n");
   else if(cmp < 0)
      printf("The 1st parameter to strcmp comes before the 2nd\n\n");
   else //cmp > 0
      printf("The 1st parameter to strcmp comes after the 2nd\n\n");

   if(p2chr_b) printf("Located the character at %s\n", p2chr_b);
   if(p2chr_c) printf("Located the character at %s\n", p2chr_c);
   if(p2chr_d) printf("Located the search string at %s\n", p2chr_d);

   if(p2chr_a) free(p2chr_a);

   return;
}

// *********************************************************************
//
// Miscellaneous intermediate level coding examples involving;
//    * The use of structures
//    * Data structures like linked lists and binary trees
//    * File reading and writing in text and binay formats
//
// *********************************************************************

//Declare a self-referential stucture used for storing vowels
struct vowel
{
   char chr;              //The vowel located
   int iLine;             //The line in which the vowel was located
   int iPos;              //The position in the char array of the vowel
   struct vowel* p2vowel; //Pointer used to build a linked list
};

//Create an alias for data type struct vowel (optional)
typedef struct vowel Vowel;

//Insert a newly created node of type struct vowel in a linked list
void InsNodeInLL(Vowel** NodeStart, Vowel* NodeStore)
{
   Vowel* NodeBefore = NULL;
   Vowel* NodeAfter = *NodeStart;

   //Loop until the insertion point in the list is reached
   while(NodeAfter != NULL 
            && tolower(NodeStore->chr) >= tolower(NodeAfter->chr))
   {
      NodeBefore = NodeAfter;
      NodeAfter = NodeAfter->p2vowel;
   }

   //Insert the node to store at the beginning of the list
   if(NodeBefore == NULL)
   {
      NodeStore->p2vowel = *NodeStart;
      *NodeStart = NodeStore;
   }
   else //Insert the node in the middle or at the end of the list
   {
      NodeBefore->p2vowel = NodeStore;
      NodeStore->p2vowel = NodeAfter;
   }

   return;
}

//Write the contents of a linked list of vowels to a file
void ContentsLL2File(FILE* File, Vowel* NodeLL)
{
   //First write the file header
   fprintf(File, "%5s%6s%6s\n", "Vowel", "Line", "Pos"); 

   //Write the contents of the linked list 
   while(NodeLL)
   {
      fprintf(File, "%-5c%6d%6d\n", NodeLL->chr, NodeLL->iLine, NodeLL->iPos); 
      NodeLL = NodeLL->p2vowel;
   }

   return;
}

//Free up the resources associated with a linked list of vowels
void FreeResourcesLL(Vowel** NodeLL)
{
   //Declare a node pointer to the node about to be removed
   Vowel* NodeTemp;

   while(*NodeLL)
   {
      //Store a pointer to what currently is the 1st node in the list
      NodeTemp = *NodeLL;

      //Make the next node in the list the new 1st node in the list
      *NodeLL = (*NodeLL)->p2vowel;

      //Free the resources associated with the now de-threaded node
      free(NodeTemp);
   }

   return;
}

//Build a linked list of all the vowels read from an input file
int f004()
{
   //Declaration and initialization section
   int errValue = 0;
   FILE* InFile = NULL;
   FILE* OutFile = NULL;
   char str1[STR_BUFF];
   char str2[] = "aeiouAEIOU";
   char* p2CharLocated;
   Vowel* Node1st = NULL;
   Vowel* NodeNew;
   int i = 1;

   //Open a file for sequential read
   InFile = fopen("seinfeld.txt", "r");
   
   //Check whether the file was opened successfully
   if(InFile == NULL)
   {
      //Error occurred while opening the input file
      errValue = -1; goto ERR_HANDLER; //Unconditional branching using goto!
   }

   //Read the file sequentially and build the linked list
   while(fgets(str1, sizeof(str1), InFile) != NULL)
   {
      //Find the first vowel in the line read
      p2CharLocated = strpbrk(str1, str2);

      //If applicable, loop through all the vowels in the string
      while(p2CharLocated != NULL)
      {
         //Call malloc to dynamically reserve memory for storing a structure
         #ifdef __cplusplus
            //C++ forces the cast of the void pointer returned by malloc
            NodeNew = (Vowel*)malloc(sizeof(Vowel));
         #else
            //Function malloc returns a void pointer
            NodeNew = malloc(sizeof(Vowel));
         #endif

         //Set the properties of the new node
         NodeNew->chr = *p2CharLocated;
         NodeNew->iLine = i;
         NodeNew->iPos = p2CharLocated - str1; //Use of pointer arithmetic!
         NodeNew->p2vowel = NULL;

         //Insert the new node in the linked list
         InsNodeInLL(&Node1st, NodeNew);

         //Find the next vowel
         p2CharLocated = strpbrk(p2CharLocated + 1, str2);
      }

      i++; //Next line
   }

   //The input file can now be closed
   fclose(InFile);

   //Open a file for sequential write
   //Use "w" write and replace, "a" for append
   OutFile = fopen("vowels.txt", "w");
   
   //Check whether the file was opened successfully
   if(OutFile == NULL)
   {
      //Error occurred while opening the output file
      errValue = -2; goto ERR_HANDLER;
   }

   //Write the contents of the linked list to a file
   ContentsLL2File(OutFile, Node1st);

   //Let the user know that everything went according to plan
   printf("Successfully completed processing and wrote file vowels.txt\n");

ERR_HANDLER:
   //Show error message in case of error
   switch(errValue)
   {
      case -1: printf("Error opening input file, terminating ...\n\n"); break;
      case -2: printf("Error opening output file, terminating ...\n\n"); break;
   }

   //Free up resources associated with the linked list
   FreeResourcesLL(&Node1st);

   //Close the output file (if necessary)
   if(OutFile) fclose(OutFile);

   return errValue;
}

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


// *********************************************************************
//
// Application entry point
//
// *********************************************************************

int main()
{
   //Declarations section
   int iFunction = 0;

   #ifdef __cplusplus
      printf("Running C++ code\n\n");
   #else
      printf("Running C code\n\n");
   #endif

   #ifdef _DEBUG
      printf("Source code file   : %s\n", __FILE__);
      printf("Date of compilation: %s\n", __DATE__);
      printf("Time of compilation: %s\n\n", __TIME__);
   #endif

   printf("Please specify the function to run: ");
   scanf("%d", &iFunction); FlushKeybBuff();
   putchar('\n');

   switch(iFunction)
   {
      case   1: f001(); break;
      case   2: f002(); break;
      case   3: f003(); break;
      case   4: f004(); break;
      case   5: f005(); break;
      default: printf("Invalid function number specified\n");
   }

   return 0;
}

