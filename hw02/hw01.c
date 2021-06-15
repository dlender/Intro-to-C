
/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. login@purdue.edu
*
*  Homework #:
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Day, Time, Location of Lab:
*
*  Program Description:
*
***************************************************************************/

#include <stdio.h> //includes standard input/output functions
#include <math.h> //includes standard math library functions

int main(){
    float mass_plane;
    float mass_glider1;
    float mass_glider2;
    float force_prop;
    float acceleration;
    float tension1;
    float tension2;

    printf("Enter mass of airplane (kg) -> ");
    scanf("%f",&mass_plane);
    printf("Enter mass of glider #1 (kg) -> ");
    scanf("%f",&mass_glider1);
    printf("Enter mass of glider #2 (kg) -> ");
    scanf("%f",&mass_glider2);
    printf("Enter force produced by propellers (N) -> ");
    scanf("%f",&force_prop);
   
    acceleration = force_prop / (mass_glider1+mass_glider2+mass_plane);
    tension2 = acceleration * mass_glider2;
    tension1 = acceleration * (mass_glider2 + mass_glider1);
    
    printf("\nAcceleration: %.2f",acceleration," m/s^2");
    printf(" m/s^2\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    printf("\nResulting tension on cable #1 %.2f",tension1);
    printf(" Newtons\nResulting tension on cable #2 %.2f",tension2);
    printf(" Newtons\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    
    return(0);
}
