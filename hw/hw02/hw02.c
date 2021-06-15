/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. dlender@purdue.edu
*
*  Homework #:2
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Day, Time, Location of Lab:Monday 1:30 SC
*
*  Program Description:
* This program calculates the two tension forces and acceleration on mass hanging behind a plane
* using inputted masses and the force by the propeller.
***************************************************************************/

#include <stdio.h> //includes standard input/output functions
#include <math.h> //includes standard math library functions

int main()
{
  double mass_plane; //defines the mass of the plane (kg)
  double mass_glider1; //defines the mass of the first glider (kg)
  double mass_glider2; //defines the mass of the second glider (kg)
  double force_prop; //defines the force by the propeller (N)
  double acceleration; //defines the acceleration (m/s^2)
  double tension1; //defines the tension force on cable 1 (N)
  double tension2; //defines the tension force on cable 2 (N)
  int width_mod; //defines the width modifier as an integar

//the following lines prompt for and recieve the information for the variables above
  printf("Enter mass of airplane (kg) -> ");
  scanf("%lf",&mass_plane);
  printf("Enter mass of glider #1 (kg) -> ");
  scanf("%lf",&mass_glider1);
  printf("Enter mass of glider #2 (kg) -> ");
  scanf("%lf",&mass_glider2);
  printf("Enter force produced by propellers (N) -> ");
  scanf("%lf",&force_prop);

//the following lines use the log function to calculate how many digits there are in the force input and then sets to an integer so the value can be used as a modifier
  width_mod = log10(force_prop) + 7;

//the lines below calculate the acceleration and tension forces using the inputed values
  acceleration = force_prop / (mass_glider1 + mass_glider2 + mass_plane);
  tension2 = acceleration * mass_glider2;
  tension1 = acceleration * (mass_glider2 + mass_glider1);

//the lines below display the accerleration and tension forces calculated above
  printf("\nAcceleration: %.2lf", acceleration);
  printf(" m/s^2\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
  printf("\nResulting tension on cable #1:%*.2lf",width_mod,tension1);
  printf(" Newtons\nResulting tension on cable #2:%*.2lf",width_mod,tension2);
  printf(" Newtons\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
  return(0);
}