
/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. dlender@purdue.edu
*
*  Homework #: 5
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Day, Time, Location of Lab: Monday 1:30 SC
*
*  Program Description: This program takes an input for the year and occurance number and displays the corresponding week.
*
***************************************************************************/

#include<stdio.h>
#include<math.h>

int dayStart(int year);
int month(int dayNumb, int year, int *day, int tracker);
int firstDate(int occur);
int lastDate(int occur);
int dayWeek(int dayNumb, int startDay);
void output();
void outputWeek(int selector);
void outputYear(int year);
void monthCalc(int month_num);
void printDates(int date, int first_day);
void dateOrder(int date, int dow, int month, int year);
int getYear();
int getOccur();
int checkOccur(int occur, int year, int* newYear, int* tracker);

int main()
{
  int year; //definest the year
  int occur; //defines the occurence number 
  int last_date; //defines the date of the last day of the week
  int first_date; //defines the date of the first day of the week
  int start_day; //defines the day of the week for the first day of the year
  int month_num; //defines the month number
  int first_dow; //defines the day for the first day of the week
  int first_day_numb; //defines the number of the first day
  int second_day_numb; //defines the number of the last day
  int newYear; //defines the new year
  int newOccur; //defines the new occurence
  int trackYear; //defines a variable to trackl the year function

  year = getYear();
  occur = getOccur();

  start_day = dayStart(year);
  last_date = lastDate(occur);
  first_date = firstDate(occur);

  outputWeek(1);
  first_dow = dayWeek(first_date,start_day);
  month_num = month(first_date,year,&first_day_numb, 0);
  outputYear(year);
  outputWeek(2);
  dayWeek(last_date,start_day);
  newOccur = checkOccur(occur, year, &newYear, &trackYear);
  last_date = lastDate(newOccur);
  month(last_date,newYear,&second_day_numb, trackYear);

  outputYear(newYear);
  monthCalc(month_num);
  output();
  printDates(first_day_numb,first_dow);
  dateOrder(first_day_numb + 1, start_day, month_num,year);

  return(0);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: checkOccur()
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int occur //defines the occurence number
*    2. int year //defines the year
*    3. int* newYear //pass by parameters to define the new year
*    4. int* tracker //pass by parameter a tracker for use in a later function
*
*  Function Description: This function checks if the week number is greater than 52,
*                       and if it is, then it sets the occurence number to 1 and adds to the year.
*
***************************************************************************/

int checkOccur(int occur, int year, int* newYear, int* tracker)
{
  if(occur > 52) //checks if the occurence is greater than 52
  { 
    //sets the year and occurence to the following year
    occur = occur - 52;
    *newYear = year + 1;
    *tracker = 1; //sets the tracker equal to one, to be used in the month function
  }

  else
  {
    *newYear = year;
  }

  return occur;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: dateOrder()
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int date //defines the number of the date
*    2. int dow //defines the number for the day of the week
*    3. int month //defines the month
*    4. int year //defines the year
*
*  Function Description: This function checks if the day is in the next month and converts,
*                         then it displays the day using the proper formatting.
*
***************************************************************************/

void dateOrder(int date, int dow, int month, int year)
{
  int x = 2; //defines a variable for the while loop
  int prev = date; //defines a variable for the previous date
  int leap; //defines a variable for checking if its a leap year
  while (x < 8) //while loop for each day of the week
  {
    if (date == 32 && month == 1) //checks if the date is greater than the days in the month
    {
      date = 1; //if it is then it sets the date to 0 
    }
    if ((!(year % 4) && (year % 100)) || !(year % 400)) //checks if the year is a leap year
    {
      leap = 1;
      if (date == 30 && month == 2)
      {
        date = 1;
      }
    }
    if (date == 29 && month == 2 && leap == 0)
    {
      date = 1;
    }
    if (date == 32 && month == 3)
    {
      date = 1;
    }
    if (date == 31 && month == 4)
    {
      date = 1;
    }
    if (date == 32 && month == 5)
    {
      date = 1;
    }
    if (date == 31 && month == 6)
    {
      date = 1;
    }
    if (date == 31 && month == 7)
    {
      date = 1;
    }
    if (date == 32 && month == 8)
    {
      date = 1;
    }
    if (date == 31 && month == 9)
    {
      date = 1;
    }
    if (date == 32 && month == 10)
    {
      date = 1;
    }
    if (date == 31 && month == 11)
    {
      date = 1;
    }
    if (date == 32 && month == 12)
    {
      date = 1;
    }
    if (7 - x - dow != 0) //checks to see if the displays are at the end of the line
    {
      if (prev - 1 > 9) //checks the previous date length to determine the spacing format
      {
        printf("  %d",date);
      }
      else
      {
        printf("   %d", date);
      }
    }
    else
    {
      printf("\n"); //if the display is at the end of the line it displays a line break
      printf(" %d",date);
    }
    x = x + 1; //adds 1 to the x iteration
    date = date + 1; //adds 1 to the date beind displayed
    prev = date; //sets the previous date equal to the new date
  }  
  printf("\n");
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:getYear()
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*
*  Function Description: Displays a prompt, then saves and gets the year input.
*
***************************************************************************/

int getYear()
{
  int year; //defines the variable for the year

  printf("Enter year number -> ");
  scanf("%d",&year);

  return year;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:getOccur()
*
*  Function Return Type:int
*
*  Parameters (list data type, name, and comment one per line):
*
*  Function Description: Displays a prompt then saves and gets the occurence input.
*
***************************************************************************/

int getOccur()
{
  int occur; //defines the variable for occurance

  printf("Enter occurrence number -> "); //displays the prompt
  scanf("%d",&occur); //saves the occurance

  return occur;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:lastDate()
*
*  Function Return Type:int
*
*  Parameters (list data type, name, and comment one per line):
*    1.int occur //defines the occurance number
*
*  Function Description: This function calculates the last date using the occurance
*
***************************************************************************/

int lastDate(int occur)
{
  int lastDate; //defines a variable for the numerical year number
  
  lastDate = occur * 7;
  return lastDate;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:firstDate()
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int firstDate
*
*  Function Description: This function calculates the numerical value for the first date using the occurance.
*
***************************************************************************/

int firstDate(int occur)
{
  int firstDate; //defines a variable for the numerical year number
  
  firstDate = (occur - 1) * 7 + 1;
  return firstDate;
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
  printf("\nday start %lf",dayStart);
  return(dayStart); //returns the start day as an int
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
*    3.int *day   pass by variable defining the numerical day value
*    4. int tracker   this variable is calculated in a previous function to set the dates correctly when in between years
*

*  Function Description:  This program calculates what month the desired day is 
*                         using the numerical day and the inputted year.
*
***************************************************************************/

int month(int dayNumb, int year, int *day, int tracker)
{
  int month_num; //defines a variable for the value of the month
  
  if (tracker == 1) //adjusts the day value if the occurence is inbetween years
  {
    dayNumb = dayNumb - 1;
  } 
  dayNumb = dayNumb - 31; //subtracts the number of the days in the month from the total days
  
  if (dayNumb <= 0) //uses an if statement to see if the number of days is in the selected month
  {
    printf("January"); //displays the selected month
    printf(" %d",(dayNumb + 31)); //displays the date
    *day = dayNumb + 31;
    month_num = 1;
  }
  
  if ((!(year % 4) && (year % 100)) || !(year % 400)) //checks if the year is a leap year
  {
    dayNumb = dayNumb - 29;
    if (dayNumb <= 0 && dayNumb >= -29)
    {
      printf("February");
      printf(" %d",(dayNumb + 29));
      *day = dayNumb + 29;
      month_num = 2;
    }
  }
  
  else 
  {
    dayNumb = dayNumb - 28;
    if (dayNumb <= 0 && dayNumb >= -29)
    {
      printf("February");
      printf(" %d",(dayNumb + 28));
      *day = dayNumb + 28;
      month_num = 2;
    }
  }
  
  dayNumb = dayNumb - 31;
  if (dayNumb <= 0 && dayNumb >= -30)
  {
    printf("March");
    printf(" %d",(dayNumb + 31));
    month_num = 3;
    *day = dayNumb + 31;
  }
  
  dayNumb = dayNumb - 30;
  if (dayNumb <= 0 && dayNumb >= -30)
  {
    printf("April");
    printf(" %d",(dayNumb + 30));
    month_num = 4;
    *day = dayNumb + 30;
  }
  
  dayNumb = dayNumb - 31;
  if (dayNumb < 0 && dayNumb > -31)
  {
    printf("May");
    printf(" %d",(dayNumb + 31));
    month_num = 5;
    *day = dayNumb + 31;
  }
  
  dayNumb = dayNumb - 30;
  if (dayNumb <= 0 && dayNumb > -30)
  {
    printf("June");
    printf(" %d",(dayNumb + 30));
    month_num = 6;
    *day = dayNumb + 30;
  }
  
  dayNumb = dayNumb - 31;
  if (dayNumb <= 0 && dayNumb >= -30)
  {
    printf("July");
    printf(" %d",(dayNumb + 31));
    month_num = 7;
    *day = dayNumb + 31;
  }
  
  dayNumb = dayNumb - 31;
  if (dayNumb <= 0 && dayNumb >= -30)
  {
    printf("August");
    printf(" %d",(dayNumb + 31));
    month_num = 8;
    *day = dayNumb + 31;
  }
  
  dayNumb = dayNumb - 30;
  if (dayNumb <= 0 && dayNumb >= -30)
  {
    printf("September");
    printf(" %d",(dayNumb + 30));
    month_num = 9;
    *day = dayNumb + 30;
  }
  
  dayNumb = dayNumb - 31;
  if (dayNumb <= 0 && dayNumb >= -30)
  {
    printf("October");
    printf(" %d",(dayNumb + 31));
    month_num = 10;
    *day = dayNumb + 31;
  }
  
  dayNumb = dayNumb - 30;
  if (dayNumb <= 0 && dayNumb >= -30)
  {
    printf("November");
    printf(" %d",(dayNumb + 30));
    month_num = 11;
    *day = dayNumb + 30;
  }
  
  dayNumb = dayNumb - 31;
  if (dayNumb <= 1 && dayNumb >= -30)
  {
    printf("December");
    printf(" %d",(dayNumb + 31));
    month_num = 12;
    *day = dayNumb + 31;
  }
  
  return month_num;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:dayWeek()
*
*  Function Return Type:int
*
*  Parameters (list data type, name, and comment one per line):
*    1.int dayNumb //variable defining the numerical value for the date
*    2.int startDay //variable definining the numerical value for the start date
*
*  Function Description: This function displays the day of the week using inputted numerical day value and the first day
*
***************************************************************************/

int dayWeek(int dayNumb, int startDay)
{
  int dow; //defines a variable for the day of the week
  dow = dayNumb + startDay + 1; //calculates the day of the week using the first day of the week and the numerical value
  if (dow % 7 == 0) //checks which day of the week it is using an if statement and displays the corresponding day
  {
    printf("Saturday ");
  }
  if(dow % 7 == 1)
  {
    printf("Sunday ");
  }
  if(dow % 7 == 2)
  {
    printf("Monday ");
  }
  if(dow % 7 == 3)
  {
    printf("Tuesday ");
  }
  if(dow % 7 == 4)
  {
    printf("Wednesday ");
  }
  if(dow % 7 == 5)
  {
    printf("Thursday ");
  }
  if(dow % 7 == 6)
  {
    printf("Friday ");
  }
  dow = dow % 7;
  return(dow);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:output()
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*
*  Function Description: This function displays the the lines and days of the week in order.
*
***************************************************************************/

void output()
{
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-");
  printf("\nSun Mon Tue Wed Thu Fri Sat\n");
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:outputWeek()
*
*  Function Return Type:void
*
*  Parameters (list data type, name, and comment one per line):
*    1.int selector //
*
*  Function Description: Displays an output depending on the selector.
*
***************************************************************************/

void outputWeek(int selector)
{
  if (selector == 1) //checks the selector
  {
    printf("\nStart of week: "); //displays the an output
  }
  else
  {
    printf("\nEnd of week: ");
  }
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: outputYear()
*
*  Function Return Type:int
*
*  Parameters (list data type, name, and comment one per line):
*    1.int year //defines a variable for the year
*
*  Function Description: Displays the year
*
***************************************************************************/

void outputYear(int year)
{
  printf(", %d",year);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: monthCalc()
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1.int month_num  //variable for the number of the month
*
*  Function Description: Displays the month with formatting depending on the month function.
*
***************************************************************************/

void monthCalc(int month_num)
{
  printf("\n\n"); 
  if (month_num == 1) //checks what month depending on the number 
  {
    printf("          January"); //displays the month
  }
  if (month_num == 2)
  {
    printf("         February");
  }
  if (month_num == 3)
  {
    printf("           March");
  }
  if (month_num == 4)
  {
    printf("           April");
  }
  if (month_num == 5)
  {
    printf("            May");
  }
  if (month_num == 6)
  {
    printf("           June");
  }
  if (month_num == 7)
  {
    printf("           July");
  }
  if (month_num == 8)
  {
    printf("          August");
  }
  if (month_num == 9)
  {
    printf("         September");
  }
  if (month_num == 10)
  {
    printf("          October");
  }
  if (month_num == 11)
  {
    printf("          November");
  }
  if (month_num == 12)
  {
    printf("         December");
  }
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:printDates()
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int date //
*    2. int first_day //
*
*  Function Description:
*
***************************************************************************/

void printDates(int date, int first_day)
{
  int mod; //defines a variable for the modifier
  if (first_day == 0) //if first day is 0 then change it to 7
  {
    first_day = 7;
  }
  if (date > 10) //checks if the date is greater than 10
  {
    mod = 4 * first_day - 1; //defines the gap for the spaces before
    printf("%*d",mod,date); //displays the date
  }
  else
  {
    mod = 4 * first_day - 2; 
    printf("%*d",mod,date);
  }
}