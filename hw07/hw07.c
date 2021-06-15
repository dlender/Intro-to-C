/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. dlender@purdue.edu
*
*  Homework #:7
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Day, Time, Location of Lab: Monday, 1:30 PM, SC231
*
*  Program Description:This program takes in up to 35 integer values and 
*  repeatedly calculates the iterations of the formula needed for it to reach 0. 
*  The program also calculates the first power of 2 each value reaches. 
*  Then according to user selection it displays the values in order.
*
***************************************************************************/

#include<stdio.h>
#include<math.h>
#define ROWS 2
#define COLM 35

int getSort(); 
int inputInt(int inp[][35]);
int calcVals(int value, int sortOption);
void sortFunc(int inp[][35], int elements, int option);
void output(int inp[][35],int max,int sortOption);
void setZeros(int inp[][35],int max);

int main()
{
  int inp[ROWS][COLM]; //defines an array of row size 2 and column size 35 for the input
  int sortOption; //defines a variable for the sorting option number
  int i = 0; //defines a variable used for iterations in loops
  int max; //defines a variable for the maximum size

  //do while loop to keep prompting for input until it is one of the two acceptable inputs
  do
  {
    sortOption = getSort();
  } while ((sortOption != 1) && (sortOption != 2));

  max = inputInt(inp);
  setZeros(inp,max);

  //for loop to iterate the user defined function calculating the second dimension of the array
  for(i = 0; i < COLM; i++)
  {
    if ((inp[0][i] == 0) || (inp[0][i] == -1))
    {
      max = i;
      i = COLM;
    }
    else
    {
      inp[1][i] = calcVals(inp[0][i],sortOption);
    }
  }

  sortFunc(inp,COLM,0);
  sortFunc(inp,COLM,1);
  output(inp,max,sortOption);
  return(0);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: setZeros
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int inp[][35] - 2-dimensional array for the input values
*    2. int max //defines the maximum size of the array
*
*  Function Description: This function removes all extra values after the correct values in the array.
*
***************************************************************************/

void setZeros(int inp[][35],int max)
{
  int i = 0; //variable to keep track of iterations in the while loop
  do
  {
    inp[0][max] = 0;
    ++max;
  } while (max < COLM);
  do
  {
    inp[1][i] = 0;
    ++i;
  } while(i < COLM);

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getSort
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int sort //defines the sorting type

*
*  Function Description: This function takes in the input values for the sort type and checks it it is valid.
*
***************************************************************************/

int getSort()
{
  int sort; //variable defining the sort type
  printf("Enter sorting option (1) count or (2) power of two -> ");
  scanf("%d",&sort);
  if((sort != 1) && (sort != 2))
  {
    printf("\nError! Enter option 1 or 2 only!\n\n");
  }
  return(sort);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: inputInt
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int inp[][35] - 2-dimensional array for the input values

*
*  Function Description: This function takes in the input values as an array.
*
***************************************************************************/

int inputInt(int inp[][35])
{
  int x = 0; //variable iterating the index within the columns
  int i = 0; //variable to keep track of iterations in the for loop 
  printf("Enter up to 35 integer values -> ");
  //do while loop is used to get an input and then replace each index in the array with the new value
  do
  {
    scanf("%d",&inp[0][x]);
    //if statement is used to end the loop if -1 s inputted
    if(inp[0][x] == -1)
    {
      x = 36;
    }
    x++;
  } while (x < 35);
  //x = 0;

  for(i = 0; i < 35; i++)
  {
    if(inp[0][i] == -1)
    {
      x = i;
    }
  }
  return(x);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: calcVals
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int value //defines the input value from the input array
*    2. int sortOption //defines the value of the sorting option
*
*  Function Description: This function calculates the values for the second row based on the sorting option.
*
***************************************************************************/

int calcVals(int value, int sortOption)
{
  int counter = 0; //variable to keep track of the number of applications
  int x = 0; //variable to keep track of iterations in the for loop
  int power; //varible for the power value reached
  if (sortOption == 1)
  {
    while(value > 1)
    {
      if (value % 2 == 1)
      {
        value = value * 3 + 1;
      }
      else
      {
        value = value / 2;
      }
      ++counter;
    }
  }
  if (sortOption == 2)
  {
    while(value > 1)
    {
      for (x = 11;x >= 0; x--)
      {
        power = pow(2,x);
        if(value == power)
        {
          counter = value;
          value = 0;
        }
      }
      if (value % 2 == 1)
      {
        value = value * 3 + 1;
      }
      else
      {
        value = value / 2;
      }
    }
  }
  return(counter);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: output
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int inp[][35] - 2-dimensional array for the input value 
*    2. int max //defines the maximum size value
*    3. int sortOption //defines the value of the sorting option
*
*  Function Description: This function outputs the sorted values
*
***************************************************************************/

void output(int inp[][35],int max,int sortOption)
{
  int i;  //variable to keep track of iterations in the for loop
  if (sortOption == 2)
  {
    printf("\nSorted data by power of two: ");
  }
  if (sortOption == 1)
  {
    printf("Sorted data by count: ");
  }
  if (max == 36)
  {
    --max;
  }
  for(i = (35 - max); i < 35;i++)
  {
    printf("%d ",inp[0][i]);
  }
  printf("\n");
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: sortFunc
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int inp[][35] - 2-dimensional array for the input value 
*    2. int elements //defines the number of elements in a row
*    3. int option //defines an option variable

*
*  Function Description: This function uses the insertion sorting method to correctly sort the values in the array.
*
***************************************************************************/

void sortFunc(int inp[][35], int elements, int option)
{
  int walk; //variable used for insertion sorting
  int temp; //variable for a temporary placeholder
  int smallest; //variable for the smallest index of the list 
  int current; //variable for the current index of the list
  
  for(current = 0; current < elements; current++)
  {
    smallest = current;
    for(walk = current + 1; walk < elements; walk++)
    {
      if (option == 1)
      {
        if((inp[0][walk] < inp[0][smallest]) && (inp[1][walk] == inp[1][smallest]))
        {
          smallest = walk;
        }
      }
      else
      {
        if(inp[1][walk] < inp[1][smallest])
        {
          smallest = walk;
        }
      }
    }
    temp = inp[1][current];
    inp[1][current] = inp[1][smallest];
    inp[1][smallest] = temp;

    temp = inp[0][current];
    inp[0][current] = inp[0][smallest];
    inp[0][smallest] = temp;  
  }
}