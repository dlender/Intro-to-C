
/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. dlender@purdue.edu
*
*  Homework #:01
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Day, Time, Location of Lab: Monday, 11:30, WTHR
*
*  Program Description:
*  This program calculates the resulting tension and acceleration of a glider 
*  using inputed mass of airplane, mass of glider, and the force produced by the propellers.
***************************************************************************/

#include <stdio.h> //includes standard input/output functions
#include <math.h> //includes standard math library functions

int main() //begins main function
{ //local declerations are made for all essential variables
  float mass_plane; /*defines mass of plane (kg)*/
  float mass_glider; /*defines mass of glider (kg)*/
  float force_prop; /*defines the amount of force produced by the propeller (N)*/
  float accel; /*defines the acceleration of the glider m/s^2*/
  float tension; /*defines the resulting tension (N)*/

  printf("Enter mass of airplane (kg) ->\n"); //prints out prompt asking for the mass of the airplane in kg
  scanf("%f",&mass_plane); //looks for an input in response to the previous line
  printf("Enter mass of glider (kg) \n"); //prints out prompt asking for the mass of the glider in kg
  scanf("%f",&mass_glider); //looks for an input in response to the previous line
  printf("Enter force produced by propellers (N) - \n"); //prints out prompt asking for the force produced by propellers (N)
  scanf("%f",&force_prop); //looks for an input in response to the previous line

  accel = force_prop / (mass_plane + mass_glider); //calculates the acceleration using the force of the propellers and masses of the plane and glider
  tension = accel * mass_glider; //calculates the tension by multiplying acceleration and the mass of the glider

  printf("Resulting tension: %.2lf Newtons \n", tension); //prints out the resulting tension force
  printf("Acceleration of glider: %.2lf m/s^2 \n", accel); //prints out the resulting acceleration
  return(0); //ends main function
}
