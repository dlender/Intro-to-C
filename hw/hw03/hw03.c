/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. dlender@purdue.edu
*
*  Homework #3:
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Day, Time, Location of Lab: Monday 1:30 SC
*
*  Program Description:
*  This program calculates the time it takes for a projectile to reach its
*  maximum height, the maximum height, the time it takes it to hit the ground
*  and the total distance traveled. It calculates these using inputted
*  initial height, velocity and angles.
***************************************************************************/

#include <stdio.h> //includes standard input/output functions
#include <math.h> //includes standard math library functions

double max_t_calc(double vel0, double angle); //defines the function used to calculate max time
void max_h_calc(double vel0, double angle, double max_time,double l_height); //defines the function used to calculate max height
double time_ground(double vel0, double angle, double l_height); //defines the function used to calculate the time it takes to hit the ground
void total_travel(double vel0, double angle, double l_height); //defines the function that calculates the total distance traveled
double h_input(); //defines the function used to get the height input
double v_input(); //defines the function used to get the velocity input
double a_input(); //defines the function used to get the angle input

int main()
{
  double l_height; //defines the launch height
  double vel0; //defines the intial velocity
  double angle; //defines the initial angle
  double max_time; //defines how long it takes to reach the max height 
  double time_to_ground; //defines how long it takes to hit the ground 

  //uses UDFs to recieve user inputs
  l_height = h_input();
  vel0 = v_input();
  angle = a_input() * M_PI / 180; //converts angle from degress to radians
  
  //executes user defined functions that calculate all the parts and displays the answers
  max_time = max_t_calc(vel0,angle);
  max_h_calc(vel0, angle, max_time,l_height);
  time_to_ground = time_ground(vel0, angle, l_height);
  total_travel(vel0,angle,time_to_ground);

  return(0);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: h_input
*
*  Function Return Type:double
*
*  Parameters (list data type, name, and comment one per line):
*
*  Function Description:
*  This function displays a statement and saves the input for launch height.
*
***************************************************************************/

double h_input()
{
  double l_height; //defines the launch height
  //displays a prompt and looks for input
  printf("Enter height of launch [m] -> ");
  scanf("%lf",&l_height);
  return(l_height);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: v_input
*
*  Function Return Type:double
*
*  Parameters (list data type, name, and comment one per line):
*
*  Function Description:
*  This function displays a statement and saves the input for initial velocity.
*
***************************************************************************/

double v_input()
{
  double vel0; //defines the initial velocity
  //displays a prompt and looks for input
  printf("Enter initial velocity [m/s] -> ");
  scanf("%lf",&vel0);
  return(vel0);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: a_input
*
*  Function Return Type:double
*
*  Parameters (list data type, name, and comment one per line):
*
*  Function Description:
*  This function displays a statement and saves the input for input angle.
*
***************************************************************************/

double a_input()
{
  double angle; //defines the angle
  //displays a prompt and looks for input
  printf("Enter angle to the horizontal [degrees] -> ");
  scanf("%lf",&angle);
  return(angle);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: max_t_calc
*
*  Function Return Type:double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double vel0 //variable for the initial velocity
*    2.double angle //variable for the angle 
*
*  Function Description:
*  This function calculates the time it takes for the projectile to reach its 
*  maximum height. 
***************************************************************************/

double max_t_calc(double vel0, double angle)
{
  double time_m; //defines the variable for time
  //calculates the time it takes to reach the max height
  time_m = vel0 * sin(angle) / 9.8;
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
  printf("\nTime to max height:%20.2lf s",time_m);
  return(time_m);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:max_h_calc
*
*  Function Return Type:void
*
*  Parameters (list data type, name, and comment one per line):
*    1. double vel0 //variable for the inital velocity
*    2. double angle //variable for the angle
*    3. double max_time //variable for the time to max height
*    4. double l_height //variable for initial launch height
*
*  Function Description:
*  This function calculates the maximum height the projectile reaches.
***************************************************************************/

void max_h_calc(double vel0, double angle, double max_time,double l_height)
{
  double max_h; //defines the max height
  //calculates the max height the projectile reaches
  max_h = vel0 * sin(angle) * max_time - .5 * 9.8 * pow(max_time,2) + l_height;
  printf("\nMaximum height reached:%16.2lf m",max_h);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: time_ground
*
*  Function Return Type:double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double vel0 //variable for the initial velocity
*    2.double angle //variable for the angle 
*    3. double l_height //variable for initial launch height
*
*  Function Description:
*  This function calculates the time it would take the projectile to 
*  hit the ground.
***************************************************************************/

double time_ground(double vel0, double angle, double l_height)
{
  double a; //defines a for the quadratic equation
  double b; //defines b for the quadratic equation
  double c; //defines c for the quadratic equation
  double quad_reg; //defines the answer for the quadratic equation

  //executse the quadratic equation and returns the results using the numbers 
  //to find the time it takes to hit the ground
  a = -.5 * 9.8;
  b = sin(angle) * vel0;
  c = l_height;
  quad_reg = (-b - sqrt(pow(b,2) - 4 * a *c )) / (2 * a);
  printf("\nTime to hit ground:%20.2lf s",quad_reg);
  return(quad_reg);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: total_travel
*
*  Function Return Type:void
*
*  Parameters (list data type, name, and comment one per line):
*    1.double vel0 //variable for the initial velocity
*    2.double angle //variable for the angle 
*    3.double l_height //variable for initial launch height
*
*  Function Description:
*  This function calculates the total distance traveled by the projectile.
***************************************************************************/

void total_travel(double vel0, double angle, double l_height)
{
  double dist; //defines the total distance traveled
  //calculates the total distance traveled and displays the results
  dist = vel0 * cos(angle) * l_height;
  printf("\nTotal distance traveled:%15.2lf m",dist);
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}