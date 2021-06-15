
/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. dlender@purdue.edu
*
*  Homework #: 06
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Day, Time, Location of Lab: Monday, 1:30 PM, SC231
*
*  Program Description: This program takes in 10 year variables and a day of the week.
*                       using this it calculates the months that start with that day of the week in each year.
*
***************************************************************************/

#include<stdio.h>
#include<math.h>
#define ARRAY 10

void getInput(int inp[]);
int getDow();
void dowOutput(int dow, int option);
int dayStart(int year);
void checkDay(int dow, int startDay,int year);
void output(int year);

int main()
{
  int inp[ARRAY]; //defines an array of size 10 for the input
  int dowStart; //defines the value for the starting day of the week
  int counter; //defines a variable used for iterations in loops
  //int month; //deines a value for the month
  getInput(inp);

  //do while loop to keep prompting for input until it is within the allowed range
  do
  {
    dowStart = getDow();
  } while ((dowStart < 0) || (dowStart > 6));
  
  dowOutput(dowStart,1);

  //for loop to iterate the user defined functions 
  for (counter = 0; counter < 10; counter++)
  {
    output(inp[counter]);
    dowOutput((dowStart + counter) % 7, 0);
    checkDay((dowStart + counter) % 7, dayStart(inp[counter]),inp[counter]);
  }
  dowOutput(dowStart,3);
  return(0);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: output()
*
*  Function Return Type:void
*
*  Parameters (list data type, name, and comment one per line):
*    1.int year //defines the year taken from the input array
*
*  Function Description: Displays the output text and the corresponding year.
*
***************************************************************************/

void output(int year)
{
  //displays the output text and corresponding year
  printf("Months in %d starting on ",year);
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
  printf("Enter 10 years [1700 - 2100] -> ");

  for(counter = 0; counter < 10; counter++)
  {
    scanf("%d", &inp[counter]);
  }
  return;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getDow
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*
*  Function Description: This function gets the day of the week from the user and checks if it is valid.
*
***************************************************************************/

int getDow()
{
  int dow; //variable defining the day of the week value
  //displays a prompt and looks for the response

  printf("Enter day of week number -> ");
  scanf("%d", &dow);

  //checks if the inputted value is within the allowed range
  if((dow < 0) || (dow > 6))
  {
    //displays an error message
    printf("\nError! Day of the week must be 0 to 6\n\n");
  }
  return(dow);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: dowOutput()
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int dow //inputted day of the week value
*    2. int option //option variable allows the funciton to display the day of the week with different text
*    3.
*
*  Function Description: This function displays the day of the week.
*
***************************************************************************/

void dowOutput(int dow, int option)
{ 
  //checks which option is selected and prints the appropriate statement
  if (option == 3)
  {
    printf("\n");
  }
  else
  {
    //checks the day of the week value and prints the corresponding day
    if (option == 1)
    {
      printf("\nDesired day of the week: ");
    }
    if(dow == 0)
    {
      printf("Sunday");
    }
    if(dow == 1)
    {
      printf("Monday");
    }
    if(dow == 2)
    {
      printf("Tuesday");
    }
    if(dow == 3)
    {
      printf("Wednesday");
    }
    if(dow == 4)
    {
      printf("Thursday");
    }
    if(dow == 5)
    {
      printf("Friday");
    }
    if(dow == 6)
    {
      printf("Saturday");
    }
    if (option == 1)
    {
      printf("\n");
    }
    if (option == 0)
    {
      printf(": ");
    }
  }
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: dayStart()
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int year //the inputed year from the array
*
*  Function Description: This function calculates the day of the week for the first day of the year.
*
***************************************************************************/

int dayStart(int year)
{
  double dayStart; //defines the numerical value of the day from the previous year
  double yearfl = year; //sets the year as a float
  //calculates the start day

  dayStart = ((yearfl - 1) * 365 + ((yearfl - 1) / 4) - ((yearfl - 1) / 100) + ((yearfl - 1) / 400));
  dayStart = (int)dayStart % 7;

  //adds one to the last day if the year is a leap year
  if ((year - 1) % 4 == 0)
  {
    if ((year - 1) % 100 != 0 || (year - 1) % 400 == 0)
    {
      dayStart = dayStart + 1;
    }
  }
  dayStart++;  
  //printf("\nday start %lf",dayStart);
  return(dayStart); //returns the start day as an int
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: checkDay()
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1.int dow //variable for the day of the week
*    2.int startDay //variable for the day of the week of January 1st
*    3.int year //variable for the year
*
*  Function Description: Calculates which the first day of the week for every month, and displays the months that start with the given day.
*
***************************************************************************/

void checkDay(int dow, int startDay,int year)
{
  //uses an if statement to check if the day of the week is the same as that of the first day of the month
  if (startDay == dow)
  {
    //displays the month
    printf("January ");
  }
  //adds the difference in the days of the week to the total running count of the day of the week
  startDay = (startDay + 3) % 7;
  if (startDay == dow)
  {
    printf("February ");
  }
  if ((year) % 4 == 0)
  {
    if ((year) % 100 != 0 || (year) % 400 == 0)
    {
      startDay++;
    }
  }
  if (startDay == dow)
  {
    printf("March ");
  }
  startDay = (startDay + 3) % 7;
  if (startDay == dow)
  {
    printf("April ");
  }
  startDay = (startDay + 2) % 7;
  if (startDay == dow)
  {
    printf("May ");
  }
  startDay = (startDay + 3) % 7;
  if (startDay == dow)
  {
    printf("June ");
  }  
  startDay = (startDay + 2) % 7;
  if(startDay == dow)
  {
    printf("July ");
  }
  startDay = (startDay + 3) % 7;
  if (startDay == dow)
  {
    printf("August ");
  }
  startDay = (startDay + 3) % 7;
  if (startDay == dow)
  {
    printf("September ");
  }
  startDay = (startDay + 2) % 7;
  if (startDay == dow)
  {
    printf("October ");
  }
  
  startDay = (startDay + 3) % 7;
  if (startDay == dow)
  {
    printf("November ");
  }
  startDay = (startDay + 2) % 7;
  if (startDay == dow)
  {
    printf("December ");
  }
  printf("\n");
}

