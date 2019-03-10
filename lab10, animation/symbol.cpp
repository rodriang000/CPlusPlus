// Angel Rodriguez 11/27/2017 Symbolic Typewritter
// symbol.cpp
//

#include "gfx.h" 
#include <iostream> 
#include <math.h> 

using namespace std; 
void plotSquare(); // For use of plotting a four sided polyon. 
void plotTriangle(); // For use of plotting a tringle. 
void plotCircle(); // Plot dat circle
void plotPoly(int); // It's in the name
int main(){

  int ww = 500; // Window width
  int wh = 500; // Window height. 
  int c; 
  int poly;  
  // Open a new window for drawing. 
  gfx_open(ww, wh, "Symbolic Typewritter");
  gfx_clear(); 

  while(c != 113) { //113 is q in ascii
  c = gfx_wait();  
    switch(c) {
       case 1:  // Mouse click, int is 1
        gfx_color(68,243,252); // Lines are blue
        plotSquare();  
        break;
    
       case 116: // t
        gfx_color(56,224,72); // Lines are green
        plotTriangle(); 
        break;
 
        case 99: // c
        gfx_color(255,255,255); // White circle
        plotCircle();
        break;

        case 27: //Escp
        gfx_clear();
        break; 
      
        case 51: //3
        case 52: //4
        case 53: //5
        case 54: //6
        case 55: //7
        case 56: //8
        case 57: //9
        poly = c - 48; // Number of sides
        plotPoly(poly);
        break; 
     } 
 }
 return 0;
}

void plotSquare() {  // Get coordinates of mouse and plot a triangle
 int xm = gfx_xpos(); // Coordinates
 int ym = gfx_ypos(); 
 gfx_line(xm+21,ym-21,xm-21,ym-21); // Horizontal line. 
 gfx_line(xm-21,ym-21,xm-21,ym+21);
 gfx_line(xm-21,ym+21,xm+21,ym+21);
 gfx_line(xm+21,ym+21,xm+21,ym-21); 
 } 

void plotTriangle() { // See plotSquare(), but with a triangle
 int xm = gfx_xpos(); 
 int ym = gfx_ypos();  
 gfx_line(xm,ym-30,xm-26,ym+15); 
 gfx_line(xm-26,ym+15,xm+26,ym+15); 
 gfx_line(xm+26,ym+15,xm,ym-30); 
 }

void plotCircle() {
 int xm = gfx_xpos(); 
 int ym = gfx_ypos();
 gfx_circle(xm,ym,30); 
}

void plotPoly(int poly){
 gfx_color(221,137,219);
 int xm = gfx_xpos(); 
 int ym = gfx_ypos();
 int x1,y1,x2,y2; 
 x1 = xm+30; // 30 is my radius
 y1 = ym; 
 
 for ( int i = 1; i <=poly; i++) {
        x2 =30*cos(2*M_PI*i/poly) + xm;
        y2 = 30*sin(2*M_PI*i/poly) + ym;
        gfx_line(x1,y1,x2,y2);
        x1=x2;
        y1=y2;
        }
}
