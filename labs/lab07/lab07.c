/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. cpoukey@purdue.edu
*  2. zrohm@purdue.edu
*  3. dlender@purdue.edu
*
*  Lab #: 7
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Day, Time, Location of Lab: Monday, 13:30 ET, SC 231
*
*  Program Description: This program gets a base 10 number from
*                                     the user and converts it to base 8. The
*                                     program then compares the number of
*                                     odd and even digits of the two numbers
*                                     respectively before outputting the
*                                     converted and calculated values via print
*                                     statements.
*
***************************************************************************/

//Imports math and stdio libraries for later use
#include<stdio.h>
#include<math.h>

//GLOBAL DECLARATIONS
int getDecimal(void);
int convertToOctal(int decimal);
int countDigits(int num, int isOdd);
void output(int octal, int oddChange, int evenChange);

int main(void)
{
  //LOCAL DECLARATIONS
  int decimal; //Variable for user-inputted base 10 number
  int octal; //Variable for converted base 8 number
  int decimalOddDigits; //Variable for number of odd digits in base 10 number
  int decimalEvenDigits; //Variable for number of even digits in base 10 number
  int octalOddDigits; //Variable for number of odd digits in base 8 number
  int octalEvenDigits; //Variable for number of even digits in base 8 number

  //EXECUTABLE STATEMENTS
  //Gets user-inputted base 10 value and converts to base 8 via UDFs
  decimal = getDecimal();
  octal = convertToOctal(decimal);

  //Gets number of odd and even digits for each base number via UDFs
  decimalOddDigits = countDigits(decimal, 1);
  decimalEvenDigits = countDigits(decimal, 0);
  octalOddDigits = countDigits(octal, 1);
  octalEvenDigits = countDigits(octal, 0);

  //Outputs converted and calculated values via a UDF
  output(octal, decimalOddDigits - octalOddDigits, decimalEvenDigits - octalEvenDigits);

  //Returns the integer 0, effectively terminating the main function
  return(0);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getDecimal
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. void
*
*  Function Description: This function gets a positive base 10 integer from
*                        the user as input. If the user does not enter a
*                        positive number, then an error will be produced
*                        and the function will ask for another number.
*
***************************************************************************/
int getDecimal(void)
{
  int decimal; //Variable for user-inputted base 10 number

  /*Handles user input by setting the default value to a negative and repeating
    the following code whenever the value is negative*/
  decimal = -1;
  while(decimal < 1)
  {
    //Gets a base 10 value from user
    printf("Enter decimal value -> ");
    scanf("%d", &decimal);

    //If base 10 number is negative, print error message
    if(decimal < 0)
    {
      printf("\nError! The decimal value provided should be non-negative.\n\n");
    }
  }

  //Returns inputted decimal to main function
  return(decimal);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: convertToOctal
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int decimal - User-inputted base 10 number
*
*  Function Description: This function uses repetition based on a
*                                     while statement to convert a base 10
*                                     number to a base 8 number.
*
***************************************************************************/
int convertToOctal(int decimal)
{
  int octal; //Variable for converted base 8 number
  int mult; //Variable for multiplication factor based on iterations

  //Sets default octal value to 0 and multiplication factor to 1*10^0
  octal = 0;
  mult = 1;
  
  //Runs until decimal only contains leading 0 digits
  while(decimal > 0)
  {
    //Uses multiplier factor to place new remainder at front of octal
    octal += mult * (decimal % 8);
    
    //Divides decimal by a factor of 8 due to conversion being to base 8
    decimal /= 8;
    //Multiplies multiplier by a factor of 10 due to conversion being from base 10
    mult *= 10;
  }

  //Returns converted base 8 number
  return(octal);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: countDigits
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int num - Number to count odd or even digits of
*    2. int isOdd - Marks whether targeting odd or even digits
*
*  Function Description: This function counts the specified odd or
*                                     even digits in a number given the number
*                                     and whether the user would like to target
*                                     odd or even numbers.
*
***************************************************************************/
int countDigits(int num, int isOdd)
{
  int digits; //Variable for number of odd or even digits

  //Sets default number or odd or even digits to 0
  digits = 0;

  //If isOdd is 0, then targeting even digits, otherwise, targeting odd digits
  if(isOdd == 0)
  {
    //Continues to run until there are no non-zero leading digits of num
    while(num > 0)
    {
      //If the last digit in num is even, adds 1 of digits
      if(num % 2 == 0)
      {
        digits++;
      }

      //Divides num by 10 to truncate digit that was just analyzed
      num /= 10;
    }
  }
  else
  {
    //Continues to run until there are no non-zero leading digits of num
    while(num > 0)
    {
      //If the last digit in num is odd, adds 1 of digits
      if(num % 2 != 0)
      {
        digits++;
      }

      //Divides num by 10 to truncate digit that was just analyzed
      num /= 10;
    }
  }

  //Returns number of targeted even or odd digits
  return(digits);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: output
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int octal - Converted base 8 value
*    2. int oddChange - Difference in odd numbers between base 10 and base 8
*    3. int evenChange - Difference in even numbers between base 10 and base 8
*
*  Function Description: This function outputs each converted and
*                                     calculated value with a description in front
*                                     via print statements.
*
***************************************************************************/
void output(int octal, int oddChange, int evenChange)
{
  //Prints converted base 8 number
  printf("\nOctal equivalent: %d\n", octal);

  //Prints odd digit change description
  printf("Odd digit change: ");

  //If odd digit change is positive, prints positive sign (+) followed by number
  if(oddChange > 0)
  {
    printf("+");
  }
  printf("%d\n", oddChange);

  //Prints even digit change description
  printf("Even digit change: ");

  //If even digit change is positive, prints positive sign (+) followed by number
  if(evenChange > 0)
  {
    printf("+");
  }
  printf("%d\n\n", evenChange);
}
