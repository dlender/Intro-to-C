
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

#include <stdio.h>
#include <math.h>
#define M_PI 3.1416

int main()
{
    double small_circle_radius;
    double small_circle_area;
    double hexagon_side_length;
    double hexagon_area;
    double large_circle_area;
    double pentagon_side_length;
    double pentagon_area;


    printf("Enter the radius of the small circle ->");
    scanf("%lf",&small_circle_radius);
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    small_circle_area = M_PI * pow(small_circle_radius,2);
    printf("\nArea of small circle: %13.2lf\n", small_circle_area);
    hexagon_side_length = 2 * small_circle_radius * tan(M_PI / 6);
    printf("Hexagon side length: %14.2lf\n", hexagon_side_length);
    
    
    


    

    return(0);
}

