/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. cpoukey@purdue.edu
*  2. zrohm@purdue.edu
*  3. dlender@purdue.edu
*
*  Lab #: 5
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Day, Time, Location of Lab: Monday, 13:30 ET, SC 231
*
*  Program Description: This program calculates the angles and quadrilateral 
*                       areas using user inputted coordinates for the vertices of a triangle
*
***************************************************************************/

//Imports math and stdio libraries for later use
#include<stdio.h>
#include<math.h>

//GLOBAL DECLARATIONS
double getCoord(char axis, int num);
double calcDist(double x1, double y1, double x2, double y2);
double calcCenter(double coord1, double coord2, double coord3, double dist12, double dist23, double dist31);
double law_cos(double a, double b, double c);
double areaQuad(double kiteLength, double angle);
void output2(void);
void outputAngle(double angle,char comma);
void outputAreas(double areaA, double areaB, double areaC);

int main()
{
  //LOCAL DECLARATIONS
  double x1; //Variable for the first x coordinate 
  double y1; //Variable for the first y coordinate
  double x2; //Variable for second x coordinate
  double y2; //Variable for second y coordinate
  double x3; //Variable for third x coordinate 
  double y3; //Variable for third y coordinate
  double distAB; //Variable for distance between points A and B
  double distBC; //Variable for distance between points B and C
  double distCA; //Variable for distance between points C and A
  double xCenter; //Variable for x coord of centroid of triangle
  double yCenter; //Variable for y coord of centroid of triangle
  double kiteLengthA; //Variable for kite length A of triangle
  double kiteLengthB; //Variable for kite length B of triangle
  double kiteLengthC; //Variable for kite length C of triangle
  double angleA; //Variable for angle A of triangle
  double angleB; //Variable for angle B of triangle
  double angleC; //Variable for angle C of triangle
  double areaA; //Variable for the area of quadrilateral A
  double areaB; //Variable for the area of quadrilateral B
  double areaC; //Variable for the area of quadrilaterla C

  //EXECUTABLE STATEMENTS
  //Gets (X, Y) of point 1 of the triangle as user input
  x1 = getCoord('X', 1);
  y1 = getCoord('Y', 1);

  //Gets (X, Y) of point 2 of the triangle as user input
  x2 = getCoord('X', 2);
  y2 = getCoord('Y', 2);

  //Gets (X, Y) of point 3 of the triangle as user input
  x3 = getCoord('X', 3);
  y3 = getCoord('Y', 3);

  //Uses distance formula to calculate triangle side lengths
  distAB = calcDist(x1, y1, x2, y2);
  distBC = calcDist(x2, y2, x3, y3);
  distCA = calcDist(x3, y3, x1, y1);

  //Calculates centroid of triangle using X or Y coords of points and side lengths
  xCenter = calcCenter(x1, x2, x3, distAB, distBC, distCA);
  yCenter = calcCenter(y1, y2, y3, distAB, distBC, distCA);

  //Uses distance formula to calculate kite height lengths
  kiteLengthA = calcDist(x1, y1, xCenter, yCenter);
  kiteLengthB = calcDist(x2, y2, xCenter, yCenter);
  kiteLengthC = calcDist(x3, y3, xCenter, yCenter);

  //Calculates main angles of triangle
  angleB = law_cos(distAB, distBC, distCA);
  angleA = law_cos(distCA, distAB, distBC);
  angleC = law_cos(distBC, distCA, distAB);

  //Calls function to print outputs
  output2();
  outputAngle(angleA,',');
  outputAngle(angleB,',');
  outputAngle(angleC,' ');

  areaA = areaQuad(kiteLengthA, angleA);
  areaB = areaQuad(kiteLengthB, angleB);
  areaC = areaQuad(kiteLengthC, angleC);

  outputAreas(areaA, areaB, areaC);
  
  //Returns the integer 0, effectively terminating the main function
  return(0);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getCoord
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. char axis - Informs user of whether to input the X or Y coordinate
*    2. int num - Informs user of which point the coordinate refers to
*
*  Function Description: This function takes integer user input that
*                        corresponds to a specified X or Y of a single
*                        coordinate. This integer is then returned to
*                        main function.
*
***************************************************************************/
double getCoord(char axis, int num)
{
  double coord; //Declares variable for user-inputted X or Y coordinate

  //Gets X or Y of specified coordinate from user
  printf("Enter %c coordinate #%d -> ", axis, num);
  scanf("%lf", &coord);

  //Returns X or Y coordinate integer to the main function
  return coord;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: calcDist
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double x1 - X coordinate of first point
*    2. double y1 - Y coordinate of first point
*    3. double x2 - X coordinate of second point
*    4. double y2 - Y coordinate of second point
*
*  Function Description: This function calculates the distance between two
*                        point via a straight line. The equation used is
*                        derived from the pythagorean theorem. The distance
*                        is then returned.
*
***************************************************************************/
double calcDist(double x1, double y1, double x2, double y2)
{
  double dist; //Declares variable for calculated distance

  //Calculates the distance between two points
  dist =  sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

  //Returns the distance to the main function
  return(dist);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: calcCenter
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double coord1 - Stores either X or Y coord of point 1
*    2. double coord2 - Stores either X or Y coord of point 2
*    3. double coord3 - Stores either X or Y coord of point 3
*    4. double dist12 - Distance between points 1 and 2
*    5. double dist23 - Distance between points 2 and 3
*    6. double dist31 - Distance between points 3 and 1
*
*  Function Description: This function uses a standard weighted midpoint
*                        equation to calculate the incenter of either the
*                        X or Y coordinate depending on the values passed.
*                        The incenter X or Y coordinate is then returned.
*
***************************************************************************/
double calcCenter(double coord1, double coord2, double coord3, double dist12, double dist23, double dist31)
{
  double center; //Declares variable for either X or Y center coordinate
  
  //Calculates either X or Y center coordinate
  center = (dist23 * coord1 + dist31 * coord2 + dist12 * coord3) / (dist12 + dist23 + dist31);

  //Returns either X or Y center coordinate
  return(center);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: law_cos
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double a - Length of the side opposite angle A
*    2. double b - Length of the side opposite angle B
*    3. double c - Length of the side opposite angle C
*
*  Function Description: This function calculates an angle of a triangle
*                        given the side lengths of the triangle by using the
*                        law of cosine.
*
***************************************************************************/
double law_cos(double a, double b, double c)
{
  double angle; //Defines the calculated angle

  //Calculates the final angle using the law of cosines
  angle = acos((pow(a, 2) + pow(b , 2) - pow(c , 2)) / (2 * a * b)) * 180 / M_PI;

  return angle;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: output_angle
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. double angle
*
*  Function Description: This function calculates the respective
*                        minutes and seconds given an angle in degrees.
*                        The calculations and the angle are then outputted.
*
***************************************************************************/

void outputAngle(double angle, char comma)
{
  int min; //defines variable for angle minutes
  double sec; //defines variable for angle seconds
  int angle_int; //defines a variable to set the angle to an integer
  
  //calculates the angle minutes and seconds
  angle_int = angle;
  min = (angle - angle_int) * 60;
  sec = (angle - angle_int - min / 60.0) * 3600;

  //Uses print statements to output passed parameters
  printf("%d%c%c %d’ %.2lf\"%c ", (int) angle_int, 0xc2, 0xB0, (int) min, sec,comma);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: areaQuad
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double kiteLength
*    2. double angle
*
*  Function Description: This function calculates the area of a quadrilateral
*                        using inputted the inputted diagonal of the kite and angle.
*
***************************************************************************/

double areaQuad(double kiteLength, double angle)
{
  double area; //defines the variable for calculated area
  //calculates area using diagonal length and the angle
  area = pow(kiteLength, 2) * sin(angle * M_PI / 360) * cos(angle * M_PI / 360);
  return(area);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: outputAreas
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. double areaA
*    2. double areaB
*    3. double areaC
*
*  Function Description: This program displays the area of the quadrilaterals.
*
***************************************************************************/

void outputAreas(double areaA, double areaB, double areaC)
{
  //displays the quadrilateral areas
  printf("\nArea of quadrilaterals: %.2lf, %.2lf, %.2lf\n\n", areaA, areaB, areaC);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: output2
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. void
*
*  Function Description: This program displays the text for the internal triangle angles.
*
***************************************************************************/

void output2(void)
{
  //displays the text for internal triangle angles
  printf("Internal triangle angles: ");
}