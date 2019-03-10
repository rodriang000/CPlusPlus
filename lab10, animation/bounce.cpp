// Angel Rodriguez 11/28/2017 Bounce
// bounce.cpp
//

#include <iostream> 
#include "gfx.h"   // For graphics
#include <cstdlib> // For srand() and rand()
#include <unistd.h> // For usleep
#include <time.h> // For a random srand()

using namespace std; 


int main () {
 int ww = 500; // Window width
 int wh = 500; // Window height
 int dx = 1; // Change in x
 int dy = 1; // Change in y
 int mx, my; // Mouse x and y position
 int pausetime = 15000; // What it says
 int c = 0;  // Character that is pressed
 int rad = 30; // Radius of circle
 int cx, cy; // Coordinate for edge of circle

 // Open a new window for drawing. 
 gfx_open(ww,wh,"Jump up, jump up and get down"); 
 gfx_clear(); 
  
 // Set the first ball velocity
 srand(time(NULL)); // Set randomizer
 dx = rand() % 10 + 1; 
 dy = rand() % 10 + 1; 
   if ( dx < 5 )
   dx = -dx; // Dx becomes negative
   if ( dy < 5 )
   dy = -dy;

 // While loop for animation
 while (c != 113) {  // Escape condition, 'q' is pressed
   gfx_clear(); 
   gfx_circle( mx+dx, my+dy , rad); // Draw circle
   gfx_flush(); 
   usleep(pausetime); // Pause
   mx = mx+dx; 
   my = my+dy; 

   cx = mx+dx+rad; // Where the right edge of circle is
   cy = my+dy+rad; // where the bottom of circle is
   
   // Checks to see if it hits the edge. 
   // Case 1, right edge. 
   if (cx >= wh) dx = - dx; // Flip the change in x
   // Case 2, left edge
   if (cx - (rad*2) <= 0) dx= -dx; 
   // Case 3, top 
   if (cy - (rad*2) <= 0) dy= -dy; 
   // Case 4, bottom
   if (cy >= ww) dy = -dy; 

   if (gfx_event_waiting()) { // If there is an event
     c = gfx_wait(); // Read it
       if ( c == 1 ) { // A click 
         gfx_clear(); 
         dx = rand() % 10 + 1;
         dy = rand() % 10 + 1; // New velocity
         if ( dx < 5 ) dx = - dx; 
         if ( dy < 5)  dy = - dy; // Have a case for negative velcoity
         mx = gfx_xpos(); 
         my = gfx_ypos(); // New position
         // Add check to see if user tries to put circle out of bounds
         if (mx + rad >= wh) mx = mx-rad; // Push it to the left
         if (mx - rad <= 0) mx = mx+rad; // Push it to the right
         if (my - rad <= 0) my = my+rad; //Push it down
         if (my + rad >= ww) my = my-rad; // Push it up
         gfx_circle(mx,my,rad); 
         usleep(pausetime);
 
        }
   }  
}

 return 0; 
}

