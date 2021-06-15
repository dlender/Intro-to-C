#include <stdio.h>
#include <math.h> //Math library is included with a preprocessor directive
#define PI 3.1416 //The mathematical value of PI is created as a defined constant
int main()
{
 //Local declarations are made for all the essential variables
  float radius; //Radius of the circle
  float pentarea; //Area of the pentagon
  float pentside; //Length of a side of the pentagon
  float height; //Height of the equilateral triangles inside the pentagon
  float circlearea; //Area of the circle
  printf("Please enter the value of the radius ->"); //User is asked for any value for the radius
  scanf("%f", &radius); //Input value is assigned to "radius"
  pentside = 2 * radius * sin(PI / 5); //Calculated using the given equation
  height = sqrt((pow(radius,2) - .25 * pow(pentside,2))); //Calculated using the Pythagorean Theorem
  pentarea = 5 * .5 * pentside * height;
  circlearea = PI * pow(radius,2);
  printf("\nCircle Area: %.2f\n", circlearea);
  printf("Pentagon Side: %.2f\n", pentside);
  printf("Pentagon Area: %.2f\n", pentarea);
  return(0);
}
