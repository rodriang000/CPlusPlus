// Fractals.cpp
// Angel Rodriguez 12/4/2017 
#include <iostream>
#include "gfx.h" 
#include <cmath> 
#include <math.h> 
#include <unistd.h>
using namespace std;
 
void drawTriangle(int,int,int,int,int,int); 
void sierpinski(int,int,int,int,int,int); 
void lotsOsquares(int,int,int,int,int,int,int,int);
void drawSquare(int,int,int,int,int,int,int,int); 
void spiralSquare(float,int,int);
void circleLace(int,int,int);
void snowflake(int,int,int);
void tree(int,int,int,float); 
void fern(int,int,int,int,float); 
void dotception(float,float,float);  

int main() {
 int ww = 700; // Window width
 int wh = 700; // Window height
 int c; 

 // Open a new window for drawing
 gfx_open(ww,wh, "Trippy Fractals, recursive, Trippy Fractals, recursive, Trippy Fractals, revursive, Trippy Fractals, recursive, Tripp...."); 
 gfx_clear();
 
 int ox = 350; // Middle coordinates 
 int oy = 350; 

 int x1,x2,x3,x4,y1,y2,y3,y4,size,r; 
 float theta; 

 while (c != 113) { // q in ascii
  c = gfx_wait(); 
   switch(c) {
     case 49: // Sierpinski Triangle
     gfx_clear(); // Clear the old board 
      
     // Find coordinates for original triangle
     x1 = 0 + ox;  
     y1 = -300 + oy; 
     x2 = -260 + ox;
     y2 = 150 + oy; 
     x3 = 260 + ox; 
     y3 = 150 + oy; 
     sierpinski(x1,y1,x2,y2,x3,y3); 
     break; 
 
     case 50: // Shrinking Squares
     gfx_clear(); // Clear old board

     x1 = 200; 
     y1 = 200; 
     x2 = 500;
     y2 = 200; 
     x3 = 500; 
     y3 = 500;
     x4 = 200;
     y4 = 500; 
     lotsOsquares(x1, y1, x2, y2, x3, y3, x4, y4); 
     break; 

     case 51: // Spiral Squares
     gfx_clear(); 
     theta = 1; 
     size = 75; 
     r = 300; 
     spiralSquare(theta,r,size); 
     break; 
 
     case 52: // Circular Lace
     gfx_clear(); 
     r = 200; 
     circleLace(ox,oy,r);
     break;

     case 53: // Snowflake
     gfx_clear(); 
     r = 250;
     snowflake(ox,oy,r);
     break; 
 
     case 54: // Tree
     gfx_clear(); 
     x1 = ox;
     y1 = oy + 250; // Start in the middle towards the bottom 
     r = 190; 
     theta = 3 * M_PI/2;
     gfx_line(ox,oy,x1,y1); // Plot the first line
     tree(ox,oy,r,theta); 
     break; 
     
     case 55: // Fern
     gfx_clear(); 
     x1 = ox;
     y1 = oy + 300; 
     r = 300; 
     theta = 3 * M_PI/2; 
     size = abs(y1-(oy-100));
     gfx_line(ox,oy-100,x1,y1);  
     fern(x1,y1,r,size,theta); 
     break; 

     case 56: // Spiral of Spirals, make a function to draw 1 spiral, call it recursively.
     gfx_clear(); 
     theta = 14*M_PI;
     float x1,y1; 
     x1 = ox; 
     y1 = oy;  
     dotception(x1,y1,theta); 
     break; 
  }
 }
}

void sierpinski( int x1, int y1, int x2, int y2, int x3, int y3 )
{
  usleep(1000); 
  // Base case. 
  if( abs(x2-x1) < 5 ) return;
  // Draw the triangle
  drawTriangle( x1, y1, x2, y2, x3, y3 );
  // Recursive calls
  sierpinski( x1, y1, (x1+x2)/2, (y1+y2)/2, (x1+x3)/2, (y1+y3)/2 );
  sierpinski( (x1+x2)/2, (y1+y2)/2, x2, y2, (x2+x3)/2, (y2+y3)/2 );
  sierpinski( (x1+x3)/2, (y1+y3)/2, (x2+x3)/2, (y2+y3)/2, x3, y3 );
} 

void lotsOsquares( int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
  usleep(10); 
  int size = abs(x2-x1);
  int newp = size/4; 
  // Base case 
  if (abs(newp) < 1) return; 
 
  // Draw the square
  drawSquare(x1,y1,x2,y2,x3,y3,x4,y4);

  // Recursive calls
  
  //Topleft
  lotsOsquares(-newp + x1, -newp+y1, newp+x1, -newp+y1, newp+x1,newp+y1,-newp+x1,newp+y1); 
  // Topright
  lotsOsquares(-newp + x2, -newp+y2, newp+x2, -newp+y2, newp+x2,newp+y2,-newp+x2,newp+y2); 
  // Bottomleft
  lotsOsquares(-newp + x3, -newp+y3, newp+x3, -newp+y3, newp+x3,newp+y3,-newp+x3,newp+y3);
  // Bottomright 
  lotsOsquares(-newp + x4, -newp+y4, newp+x4, -newp+y4, newp+x4,newp+y4,-newp+x4,newp+y4);
}

void drawSquare( int x1 , int y1, int x2, int y2, int x3, int y3, int x4, int y4 ) 
{
 gfx_line(x1,y1,x2,y2);
 gfx_line(x2,y2,x3,y3);
 gfx_line(x3,y3,x4,y4);
 gfx_line(x4,y4,x1,y1); 
 gfx_flush(); 
}

void drawTriangle( int x1, int y1, int x2, int y2, int x3, int y3)
{
 // Draw the three lines. 
 gfx_line(x1,y1,x2,y2);
 gfx_line(x2,y2,x3,y3);
 gfx_line(x3,y3,x1,y1);
 gfx_flush(); 
}

void spiralSquare( float theta, int r,  int size) 
{
 usleep(1000); 
 // Center around center coordinates
 int ox = 350; // origin X
 int oy = 350; // Origin Y
 int x = r*cos(theta) + ox; 
 int y = r*sin(theta) + oy;
 
 // Base case
 if ( size < 2) return; 
 
 // Draw the square
 drawSquare(-size + x, -size + y, size + x, -size + y, size + x, size + y, -size + x, size + y);  

 // Change for the next recursion
 theta = theta + .7; // Theta changes by rad
 r = r * .9; 
 size = size *.9; 
 // Next recursion
 spiralSquare(theta,r,size);
}                   

void circleLace(int ox, int oy, int r) {

 int nx, ny; 
 float theta = 0; // Starts at 0 radians.  
 // Base Case
 if ( r < 2 ) return;  

 // Draw circle
 gfx_circle(ox,oy,r); 
 
 // Change for the next recursion 
 int newr = r; 
 for (int i = 0; i <= 5; i++) {
  theta = theta + M_PI/3; 
  nx = r*cos(theta) + ox;
  ny = r*sin(theta) + oy; 
  newr = r*.35;  
  gfx_circle(nx,ny,newr); 
  circleLace(nx,ny,newr);
  newr = r; 
  
  }
 }
 
void snowflake( int ox, int oy, int r) {
 float theta;
 int nx, ny; 
 // Base case  
 usleep(100); 
 if ( r < 2) return; 

 // Draw circles
 theta = M_PI/4; 
 nx = r*cos(theta) + ox; 
 ny = r*sin(theta) + oy; 
 gfx_line(ox,oy,nx,ny); // circle 1 
 snowflake(nx,ny,r*.35); 

 theta = 3*M_PI/4; 
 nx = r*cos(theta) + ox; 
 ny = r*sin(theta) + oy;
 gfx_line(ox,oy,nx,ny); // circle 2
 snowflake(nx,ny,r*.35); 

 theta= 9 * (M_PI/8);
 nx = r*cos(theta) + ox; 
 ny = r*sin(theta) + oy; 
 gfx_line(ox,oy,nx,ny); // circle 3
 snowflake(nx,ny,r*.35); 

 theta = 3 * (M_PI/2); 
 nx = r*cos(theta) + ox; 
 ny = r*sin(theta) + oy; 
 gfx_line(ox,oy,nx,ny); // circle 4
 snowflake(nx,ny,r*.35); 

 theta = 15 * (M_PI/8); 
 nx = r*cos(theta) + ox; 
 ny = r*sin(theta) + oy; 
 gfx_line(ox,oy,nx,ny); // circle 5 
 snowflake(nx,ny,r*.35); 
  
}

void tree(int ox, int oy, int r, float theta) {
 int nx, ny; 
 // Base case
 usleep(10); 
 if ( r < 1) return;

 // Find other two points, do recursive
 r = (2*r)/3; // Change size of next points
 nx = r*cos(-(M_PI/5)+theta) + ox; 
 ny = r*sin(-(M_PI/5)+theta) + oy;
 gfx_line(ox,oy,nx,ny);  
 tree(nx,ny,r,-(M_PI/5)+theta); 

 nx = r*cos((M_PI/5)+theta) + ox; 
 ny = r*sin((M_PI/5)+theta) + oy; 
 gfx_line(ox,oy,nx,ny);
 tree(nx,ny,r,(M_PI/5)+theta); 
}

void fern(int ox, int oy, int r, int size, float theta) {
 int nx, ny;
 int newx, newy;
 int branch = size/4; // Each fourth is a new branch
 // Base case
 if ( r < 1) return; 
 // Recursive for loop, go through every 4th of the stem  
   r = (2*r)/6; 
   for (int i = 1; i < 5; i++) { // Draw the three lines. 4 times.  
   nx = (i*branch) * cos(theta) + ox; // Middle Stem;  
   ny = (i*branch) * sin(theta) + oy; 
 
   newx = nx; 
   newy = ny;  

   nx = r * cos(-(M_PI/5) + theta) + newx; // Left stem 
   ny = r * sin(-(M_PI/5) + theta) + newy; 
   gfx_line(newx,newy,nx,ny); 
   fern(newx,newy,r,r,-(M_PI/5) + theta);  
  
   nx = r * cos((M_PI/5) + theta) + newx;  // Right stem
   ny = r * sin((M_PI/5) + theta) + newy;
   gfx_line(newx,newy,nx,ny);  
   fern(newx,newy,r,r,(M_PI/5) + theta); 
    }
}

void dotception(float x1, float y1, float theta) {
 // Center around middle coordinates
 gfx_point(x1,y1); 
 float r; // Radius
 // Base case
 if (exp(theta / (2 * M_PI)) < 1)  return; 
 // Change for next iteration
 
 for (float i = 0; i <= theta; i+= (M_PI/5))
 {
 r = exp(i/(2*M_PI)); 
 dotception(x1+r*cos(i), y1 - r * sin(i),(i - (M_PI * 2) - (M_PI/5))); 
 }
}

