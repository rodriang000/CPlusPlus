// Angel Rodriguez 11/29/2107 Animate
// animate.cpp
// use the gfx library to animate a color changing ball
// inlcude speedup/slowdown from the user. 
#include "gfx.h" 
#include <iostream> 
#include <unistd.h>
#include <math.h> // for cos and sin

using namespace std; 
void findCol(int &,int &,int &,float); // Determine where to change (c1,c2,c3); 
void plotPoly(int, int, float); // Plot changing figures inside the circles.  
void plotSquare(int,int,float); // Plot a square inside the circle

int main() {
 int ww = 500; // Window width (x) 
 int wh = 500; // Window height(y)
 int pausetime = 15000; // pausetime, 
 float dtheta = .006; // Change in speed, in radians
 float theta = 0; // Starting theta, 0; 

 int lineRad = 100; // radius of the path
 int ox = 250; //Center location x
 int oy = 250; 
 int nx = 250 + lineRad; 
 int ny = oy; // Start directly to the right of origin
 int nx2 = 250 - lineRad; 
 int ny2 = oy; 
 int circleRad = 40; // Radius of the circle
 int c = 0; // Character that is pressed

 int c1 = 244; // First color in rgb
 int c2 = 66; // Second.. etc. 
 int c3 = 66; 
 
 int choice = 0; // determine which color to change. 
 // Open a new window for drawing. 
 gfx_open(ww,wh,"Balls of fury"); 
 gfx_clear(); 
 
 cout << "Press 'b' to have a black background.\n";
 cout << "Prss 'w' to have a white background.\n"; 
 cout << "Press the UP key to speed that baby up.\n";
 cout << "Press the DOWN key to slow it down.\n"; 

 // While loop for animation
 while ( c != 113) {
 
  if ( theta >= 2* M_PI) {// Reset theta if it goes to 2pi
  theta = 0; 
  c1 = 244;  
  c2 = 66; 
  c3 = 66;
  }

  gfx_clear();
 
  gfx_circle(nx,ny,circleRad); // Circle on outer edge 1
  gfx_circle(nx2,ny2,circleRad); // Circle on outer edge 2
  gfx_circle(ox,oy,15); // Middle circle; 
  plotPoly(nx,ny,theta); // Plot poly in Circle 1    
  plotPoly(nx2,ny2,theta); // Plot poly in Circle 2
  plotSquare(ox,oy,theta); 
 
  gfx_flush(); 
  usleep(pausetime); 
  
  theta = theta + dtheta; // Incrament position 
  nx = lineRad*cos(theta) + ox;  
  ny = lineRad*sin(theta) + oy; 
  nx2 = -lineRad*cos(theta) + ox; 
  ny2 = -lineRad*sin(theta) + oy; 
 
  findCol(c1,c2,c3,theta); // Find and set col based on theta. 
  // Checks if a user enters an input. 
  if (gfx_event_waiting()) { // If there is an event
   c = gfx_wait(); // read it 
   if ( c == 82 ) // Ascii for Up arrow key
   dtheta = dtheta * 1.4; // Speed up
   if ( c == 84 ) // Ascii for Down arrow key
   dtheta = dtheta / 1.4; // Slow down
   if ( c == 119) // Ascii for w
   gfx_clear_color(255,255,255);
   if ( c == 98) // Ascii for b
   gfx_clear_color(0,0,0);
   }
  }
   
return 0;
}

void findCol(int & c1, int & c2 , int & c3 , float theta) {
 // Find out which color to change based on theta. 
 // Change is based on incraments of pi/3
 
 if (theta >= 0.000 && theta < (M_PI/3))
 c2++;

 if (theta >= (M_PI/3) && theta < 2*(M_PI/3))
 c1--;

 if (theta >= 2*(M_PI/3) && theta < M_PI)
 c3++; 

 if (theta >= M_PI && theta < 4*(M_PI/3))
 c2--;

 if (theta >= 4*(M_PI/3) && theta < 5*(M_PI/3))
 c1++;
 
 if (theta >= 5*(M_PI/3) && theta < 2*M_PI)
 c3--; 
 
 gfx_color(c1,c2,c3); //Set color 
}

void plotPoly(int nx, int ny, float theta) {
 int x1 = nx + 40; 
 int y1 = ny;
 int x2,y2;  
  for (int i = 1; i <= 9; i++) { 
    x2 = 40*cos(-theta*2*M_PI*i/5) + nx;
    y2 = 40*sin(-theta*2*M_PI*i/5) + ny; 
    gfx_line(x1,y1,x2,y2);
    x1 = x2; 
    y1 = y2; 
    }
}

void plotSquare(int ox, int oy, float theta) {
// int x1 = ox + 15; 
// int y1 = oy;
   int x1 = 15 + ox; 
   int y1 = oy;  
 int x2,y2; 
   for (int i = 1; i <= 4; i++) {
     x2 = 15*cos(2*M_PI*i/4) + ox; 
     y2 = 15*sin(2*M_PI*i/4) + oy; 
     gfx_line(x1,y1,x2,y2); 
     x1 = x2; 
     y1 = y2; 
    }
}
