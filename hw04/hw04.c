
/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. dlender@purdue.edu
*
*  Homework #: 4
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Day, Time, Location of Lab: Monday 1:30 SC
*
*  Program Description: This program takes in the year, value for the day of the week
*  and the number of occurences, then displays the calculated date.
*
***************************************************************************/

#include<stdio.h>
#include<math.h>

int getYear();
double getWeekNumb();
double getOccur();
int dayStart(int year);
int dayFinal(int occurNumb, int dayStart, int dayInitial);
void month(int dayNumb, int year);
void dayWeek(int dow, int year);
void output(int occur);

int main()
{
  int weekNumb; //defines the number for the day of the week
  int year; //defines the variable for the year
  int startDay; //defiens the variable for the numeric first day
  int occurNumb; //defines the number of occurences
  int dayNumb; //defines the numeric value of the date

  //executes the user-defined functions to calculate and display the final results
  year = getYear();
  weekNumb = getWeekNumb();
  occurNumb = getOccur();
  startDay = dayStart(year);
  dayNumb = dayFinal(occurNumb,startDay,weekNumb);
  output(occurNumb);
  dayWeek(weekNumb, year);
  month(dayNumb,year);
  printf("\n%d",dayNumb);
  return(0);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getYear()
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*
*  Function Description: Prompts for the year and saves it.
*
***************************************************************************/

int getYear()
{
  int year; //defines the variable for the year
  //displays the prompt and defines the number for the year
  printf("Enter year number -> ");
  scanf("%d",&year);
  return year;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getWeekNumb()
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*
*  Function Description: 
*  Prompts for the day of the week number and save it.
***************************************************************************/

double getWeekNumb()
{
  int weekNumb; //defines the variable for the numerical day of the week 
  //displays the prompt and defines the number for the day of the week
  printf("Enter day of week number -> ");
  scanf("%d",&weekNumb);
  return weekNumb;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getOccur()
*
*  Function Return Type: double
*
*
*  Function Description: Prompts for the occurrence and saves it.
*
***************************************************************************/

double getOccur()
{
  int occur; //defines the value for the number of occurences
  //displays and defines the number of occurences
  printf("Enter occurrence number -> ");
  scanf("%d",&occur);
  return occur;
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
*    1. int year
*
*  Function Description: Calculates the value for the day of the week of the previous year.
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
  return(dayStart); //returns the start day as an int
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: dayFinal()
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int occurNumb  this variable defines the number of occurences that took place
*    2. int dayStart    this variable defines the value for the last day of the previous year
*    3. int dayInitial   this variable defines the value for the first day of the current year
*
*  Function Description: This function calculates the value for what numerical number the desired day is.
*
***************************************************************************/

int dayFinal(int occurNumb, int dayStart, int dayInitial)
{
  int occur; //defines a new variable for occurences
  int dayNumb; //defines a variable for the numeriucal value of the date
  //calculates the number of days and returns it as an int value
  occur = occurNumb - 1;
  if (dayInitial > dayStart) 
  {  
    occur = occur - 1;
  }
  dayNumb = occur * 7 + (7 - (dayStart + 1)) + dayInitial + 1;
  return(dayNumb);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: month()
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1.int dayNumb  this variable is the numerical value for what day it is
*    2.int year    this variable is the definition for the inputted year
*
*  Function Description:  This program calculates what month the desired day is 
*                         using the numerical day and the inputted year.
*
***************************************************************************/

void month(int dayNumb, int year)
{
  dayNumb = dayNumb - 31; //subtracts the number of the days in the month from the total days
  if (dayNumb <= 0) //uses an if statement to see if the number of days is in the selected month
  {
    printf("January"); //displays the selected month
    printf(" %d",(dayNumb + 31)); //displays the date
  }
  if ((!(year % 4) && (year % 100)) || !(year % 400)) //checks if the year is a leap year
  {
    dayNumb = dayNumb - 29;
    if (dayNumb <= 0 && dayNumb >= -29)
    {
      printf("February");
      printf(" %d",(dayNumb + 29));
    }
  }
  else 
  {
    dayNumb = dayNumb - 28;
    if (dayNumb <= 0 && dayNumb >= -29)
    {
      printf("February");
      printf(" %d",(dayNumb + 28));
    }
  }
  dayNumb = dayNumb - 31;
  if (dayNumb <= 0 && dayNumb >= -30)
  {
    printf("March");
    printf(" %d",(dayNumb + 31));
  }
  dayNumb = dayNumb - 30;
  if (dayNumb <= 0 && dayNumb >= -30)
  {
    printf("April");
    printf(" %d",(dayNumb + 30));
  }
  dayNumb = dayNumb - 31;
  if (dayNumb <= 0 && dayNumb >= -31)
  {
    printf("May");
    printf(" %d",(dayNumb + 31));
  }
  dayNumb = dayNumb - 30;
  if (dayNumb < 0 && dayNumb > -30)
  {
    printf("June");
    printf(" %d",(dayNumb + 30));
  }
  dayNumb = dayNumb - 31;
  if (dayNumb <= 0 && dayNumb >= -30)
  {
    printf("July");
    printf(" %d",(dayNumb + 31));
  }
  dayNumb = dayNumb - 31;
  if (dayNumb <= 0 && dayNumb >= -30)
  {
    printf("August");
    printf(" %d",(dayNumb + 31));
  }
  dayNumb = dayNumb - 30;
  if (dayNumb <= 0 && dayNumb >= -30)
  {
    printf("September");
    printf(" %d",(dayNumb + 30));
  }
  dayNumb = dayNumb - 31;
  if (dayNumb <= 0 && dayNumb >= -30)
  {
    printf("October");
    printf(" %d",(dayNumb + 31));
  }
  dayNumb = dayNumb - 30;
  if (dayNumb <= 0 && dayNumb >= -30)
  {
    printf("November");
    printf(" %d",(dayNumb + 30));
  }
  dayNumb = dayNumb - 31;
  if (dayNumb <= 1 && dayNumb >= -30)
  {
    printf("December");
    printf(" %d",(dayNumb + 31));
  }
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: dayWeek()
*
*  Function Return Type:
*
*  Parameters (list data type, name, and comment one per line):
*    1. int dow   variable representing the numeric day of the week
*    2. int year   variable representing the year
*
*  Function Description: This function calculates and prints the day of the week using the inputted value.
*
***************************************************************************/

void dayWeek(int dow, int year)
{
  if (dow == 0)
  //uses if statements to see if the day of the week is equal to the value, then displays the year and day of the week in text
  {
    printf("Sunday in %d: ",year);
  }

  if (dow == 1)
  {
    printf("Monday in %d: ",year);
  }

  if (dow == 2)
  {
    printf("Tuesday in %d: ",year);
  }

  if (dow == 3)
  {
    printf("Wednesday in %d: ",year);
  }

  if (dow == 4)
  {
    printf("Thursday in %d: ",year);
  }

  if (dow == 5)
  {
    printf("Friday in %d: ",year);
  }

  if (dow == 6)
  {
    printf("Saturday in %d: ",year);
  }
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: output()
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1.int occur   variable defining the number of occurence that take place
*
*  Function Description: Displays the text and number of occurences for the display.
*
***************************************************************************/

void output(int occur)
//displays the final text and number of occurences
{
  printf("\nDesired occurrence #%d of ",occur);
}