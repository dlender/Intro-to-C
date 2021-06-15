/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. hoke5@purdue.edu
*  2. smonge@purdue.edu
*  3. dlender@purdue.edu
*
*  Lab #: 10
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Day, Time, Location of Lab: Monday, 1:30 PM, SC231
*
*  Program Description: This program takes in 20 or less input values, arranges the array into even and odd numbers, sorts it out from smallest to largest, and gets the sum of the array for each value mod size of the array.
*
***************************************************************************/

#include <stdio.h>
//Global Variable Declaration
#define ARR_SIZE 20

//Function Declarations
void getInp(int inp[], int* );
int oddEven(int inp [],int);
void sortFunct(int inp[],int, int);
void Outp1(int inp[],int);

int main(void) 
{
  //Local Declarations
  int inp[ARR_SIZE]; // input array
  int elements = 0; //elements in the array
  int evenEl; //elements in the array that are even 
  
  getInp(inp,&elements);
  evenEl = oddEven(inp,elements);
  sortFunct(inp,evenEl,elements);
  Outp1(inp,elements);
  return(0);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getInp()
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1.int inp[] - user input array 
*    2.int* elements - elements in the array
*
*  Function Description: This function receives the input integer values. 
*
***************************************************************************/

void getInp(int inp[], int* elements)
{
  //LOCAL DECLARATIONS
  int counter; // Counter for for loop 
  //EXECUTABLE STATEMENTS 
  printf("Enter up to 20 integer values -> ");
  //uses a for loop to save each inputted value to an array
  for(counter = 0; counter < ARR_SIZE; counter++)
  {
    scanf("%d",&inp[counter]);
    *elements = *elements + 1;
    if(inp[counter] == -1)
    {
      counter = 100;
      *elements = *elements - 1;
    }
  }
  return;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: oddEven
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1.int inp[] - user input array 
*    2.int elements - elements in the array
*
*  Function Description: This function arranges the even elements first in the array and then outputs the number of elements that are even. 
*
***************************************************************************/

int oddEven(int inp [],int elements)
{
  //Local Declarations
  int counter; // control variable for loops
  int i; //index of where next even number will be moved to
  int temp; //variable that holds the value of the current number being moved

  i = 0;
  //uses a for loop and an if statement to check wether each value is even
  for(counter = 0; counter < elements; counter++) 
  {
    if(inp[counter] % 2 == 0)
    {
      temp = inp[i];
      inp[i] = inp[counter];
      inp[counter] = temp;
      i++;
    }
  }
  return(i);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: sortFunct
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1.int inp[] - user input array 
*    2.int evenEl - elements of the array that are even 
*    3.int elements - elements in the array
*
*  Function Description: This function sorts the even values in ascending order and then the odd values in ascending order. (Function taken out of CS 159 book, Computer Science: A Structured Aprroach Using C) 
*
***************************************************************************/

void sortFunct(int inp [], int evenEl,int elements)
{
  //Local Declarations
  int smallest; //smallest element in the unsorted list
  int temp; //variable that holds the value of the current number being moved
  int current = 0; //control variable for loops
  int walk; //variable used in loop

  //Loops and Calculations
  if(inp[current] % 2 == 0)
  {
    for(current = 0; current < evenEl; current++)
    {
      smallest = current;
      for(walk = current + 1; walk < evenEl; walk++)
      {
        if(inp[walk] < inp[smallest]) 
        {
          smallest = walk;
        }
      }
      temp = inp[current];
      inp[current] = inp[smallest];
      inp[smallest] = temp;
    }
  }

  for(current = evenEl; current < elements; current++)
  {
    smallest = current;
    for(walk = current + 1; walk < elements; walk++)
    {
      if(inp[walk] < inp[smallest]) 
      {
        smallest = walk;
      }
    }
    temp = inp[current];
    inp[current] = inp[smallest];
    inp[smallest] = temp;
  }
  return;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: oddEven
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1.int inp[] - user input array 
*    2.int elements - elements in the array
*
*  Function Description: This function gives out the output for the sorted array and the calculated sum of the array numbers mod size of the array. 
*
***************************************************************************/

void Outp1(int inp[],int elements)
{
  //Local Declarations
  int counter; //control variable for loops
  int sumIndex; //index for current value being calculated for the sum
  int sumEl = 0; //Sum of elements

 //Calcuations and Print Statements
  printf("\nSorted array: ");
  
  for(counter = 0; counter < elements; counter++)
  {
    printf("%d ",inp[counter]);
    sumIndex = inp[counter] % elements;
    sumEl += inp[sumIndex];
  }
  if (inp[counter + 1] == -1)
  {
    counter = elements;
  }
  printf("\nCalculated sum: %d\n",sumEl);
}