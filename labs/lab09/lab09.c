/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. hoke5@purdue.edu
*  2. smonge@purdue.edu
*  3. dlender@purdue.edu
*
*  Lab #: 09
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Day, Time, Location of Lab: Monday, 1:30 PM, SC231
*
*  Program Description: This program takes in 20 input values and converts odd values to binary and even values to octals.
*
***************************************************************************/

#include <stdio.h>
#include <math.h>
#define ARR_SIZE 20 //defines the size of the input array

void getInput(int inp[]);
int findBinary(int);
int findOctal(int);
int oddEven(int);
void printResults(int);
void printNumbers(int, int, int*);
void noneFunc(int number, int check);

int main(void) 
{
  int inp[ARR_SIZE]; //defines the input array 
  int counter; //defines a variable to keep track of loop iterations
  int numBin; //defines a variable to be used for the binary value
  int numOct; //defines a variable to be used for the octal value

  //printf("number: ");
  //scanf("%d",&number);
  //newNumber = findBinary(number);
  getInput(inp); //gets the input and returns an array
  //uses the input array to check if the numbers or even or odd
  // and saves the new calculated values to the array
  for(counter = 0; counter < ARR_SIZE; counter++)
  {
    inp[counter] = oddEven(inp[counter]);
  }

  //displays the output text and uses a for loop to iterate through
  // the array and check if each value is an binary that should be displayed now
  printResults(1);
  numBin = 0;
  for(counter = 0; counter < ARR_SIZE; counter++)
  {
    printNumbers(inp[counter], 1, &numBin);
  }
  noneFunc(numBin,0);

  //iterates through the loop and chekcs if each value is an octal and should be printed
  printResults(0);
  numOct = 0;
  for(counter = 0; counter < ARR_SIZE; counter++)
  {
    printNumbers(inp[counter], 0, &numOct);
  }
  noneFunc(numOct,1);
  return 0;
}
/***************************************************************************
*
*  Function Information
*
*  Name of Function: noneFunc()
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1.int number - user input number 
*    2.int check - temporary variable used to print another line break
*
*  Function Description: This function prints out the desired message when
*  either no binary or octal values is found. 
*
***************************************************************************/

void noneFunc(int number, int check)
{
  //checks if the number of outputs is 0, if it is displays that there are no outputs
  if (number == 0)
  {
    printf("None\n");
  }
  else
  {
    printf("\n");
  }
  //checks if it is the octal values beind displayed and prints another line break
  if (check == 1)
  {
    printf("\n");
  }
  return;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: printNumbers
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1.int number - variable for the calculated value in the array
*    2.int binOct - variable used to check if the number is octal or binary
*    3.int numBinOct - variable passed by parameters used to check if there is output 
*
*  Function Description: This function checks if the numbers in the array are binary or octal, and displays them accordingly.
*
***************************************************************************/

void printNumbers(int number, int binOct, int *numBinOct)
{
  //uses an if statement to check if the values are binary or octal
  if ((number % 2) == binOct)
  {
    //displays the according set of values
    printf("%d ",number);
    //adds 1 to numBinOct to tell the main function that there is an output
    *numBinOct = *numBinOct + 1;
  }
  return;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: printResults
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1.int binOct - variable used to tell the function which statement to display
*
*  Function Description: This function displays the text statements describing the outputs.
*
***************************************************************************/

void printResults(int binOct)
{
  //binOct is bin if == 1, oct if == 0
  //uses an if statement to check which input is given and displays the corresponding output
  if (binOct == 1)
  {
    printf("\nBinary values: ");
  }
  else
  {
    printf("Octal values: ");
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
*    1.int number - variable for the inputted value from the input array
*
*  Function Description: This function checks if the inputted value is odd or even and calculates
*                       the corresponding binary or octal value.
*
***************************************************************************/

int oddEven(int number)
{
  int newNumber; //variable for the new calculated value

  //uses an if statement to check if the value is even or odd
  if((number % 2) == 1)
  {
    //uses nested functions to calculated the corresponding binary value
    newNumber = findBinary(number);
  }
  else
  {
    newNumber = findOctal(number);
  }

  return(newNumber);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getInput
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1.int inp[] - array for the inputted values
*
*  Function Description: This function takes in the input values as an array
*
***************************************************************************/

void getInput(int inp[])
{
  int counter; //variable to keep track of iterations in the for loop
  
  //displays the prompt and saves each input using a for loop and an array
  printf("Enter 20 integer values -> ");
  for(counter = 0; counter < 20; counter ++)
  {
    scanf("%d", &inp[counter]);
  }
  return;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: findBinary 
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1.int input - variable defining the input from the array
*
*  Function Description: This function calculates calculates the binary value from a decimal value.
*
***************************************************************************/

int findBinary(int input)
{
  int tempInput; //temporary value used to calculate the binary output
  int quotient; //temporary value used to calculate the binary output
  int digit; //temporary value used to calculate the binary output
  int binNumber; //temporary value used to calculate the binary output
  int decPlace; //temporary value used to calculate the binary output

  binNumber = 0;
  decPlace = 0;
  tempInput = input;
  while(tempInput > 0)
  {
    quotient = tempInput / 2;
    digit = tempInput % 2;
    
    binNumber = binNumber + digit * pow(10, decPlace);

    tempInput = quotient;
    decPlace++;
  }
  return(binNumber);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: findOctal 
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1.int input - variable defining the input from the array
*
*  Function Description: 
*
***************************************************************************/

int findOctal(int input)
{
  int tempInput; //temporary variable used to calculate the octal
  int quotient; //temporary variable used to calculate the octal
  int digit; //temporary variable used to calculate the octal
  int octal; //variable defining the calculated octal value

  tempInput = input;
  octal = input % 8;
  while(tempInput > 0)
  {
    quotient = tempInput / 8;
    digit = quotient % 8;
    
    if (quotient == 0)
    {
      octal = octal + digit * pow(10, round(log10(input)));
    }
    else
    {
      octal = octal + digit * pow(10, round((log10(input) - log10(quotient))));
    }
    tempInput = quotient;
  }
  return(octal);
}
