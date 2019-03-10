// Angel Rodriguez, 11/7/2017, lifeboard.cpp
#include <iostream> 
#include <cstring>  
#include <cstdlib> 
#include "lifeboard.h"
#include <fstream>  
using namespace std; 
 const int size = 41; // Global variable, change this and in main and size of board changes. 
 const int playsize = size - 1; // Size that the user interacts with
Lifeboard::Lifeboard()
{
  char array[size][size] = {};
  char newarray[size][size] = {};
}

Lifeboard::~Lifeboard()
{   }

void Lifeboard::setLive(int j, int i) 
{ array[j][i] = 'X';  
}

void Lifeboard::setDead(int j, int i)
{ array[j][i] = ' ';
}

void Lifeboard::playLife() // Check if alive or dead in next gen.
{    
 
     int j = 0; 
     int col = 0;
 for (int i = 0; i <= playsize; i++)
  {
    for (int j = 0; j <= playsize; j++)
     { 
     newarray[j][i] = ' ';     
     checkLife(j,i);  
     }
    }
    newBoard();    // Have some sort of copy function 
}

void Lifeboard::checkLife(int j,int i) // See if the cell is alive or dead in the next iteration.   
{
 char value = ' '; 
 int alivearound = 0; // Tally to see how many cells are alive around target cell
 
 // Corner cases 
 if (j == 0 && i == 0) {   //Topleft corner
   value = array[1][1]; 
   if ( value == 'X') { 
     alivearound++;      
    }
   value = array[1][0]; 
   if ( value == 'X') {
     alivearound++; 
    }
   value = array[0][1];
   if (value = 'X') {
     alivearound++; 
    }
   setLife(j,i,alivearound);
   }
   
 else if (j == 0 && i == playsize){ // Bottom left corner
   value = array[0][playsize-1]; 
     if (value == 'X') {
       alivearound++; 
      }
    value = array[1][playsize-1]; 
       if (value == 'X'){
        alivearound++;
       }
    value = array[1][playsize];
      if (value == 'X'){
        alivearound++;
       } 
     setLife(j,i,alivearound);
   }
  
 else if (j == playsize && i == 0){ // Top right corner
    value = array[playsize-1][0]; 
     if (value == 'X') {
       alivearound++;
      }
     
     value = array[playsize-1][1];
     if (value == 'X') {
       alivearound++;
      }
 
     value = array[playsize][1];
     if (value == 'X') {
       alivearound++;
      }
   setLife(j,i,alivearound); 
  }  
  
 else if (j == playsize && i == playsize) { //Bottom right corner.
   value = array[playsize][playsize-1];
     if (value == 'X') {
       alivearound++;
      }
    value = array[playsize-1][playsize-1];
     if (value == 'X') {
       alivearound++;
      }
    value = array[playsize-1][playsize];
     if (value == 'X') {
       alivearound++;
      }
   setLife(j,i,alivearound);
 }

 // Edge cases
 else if (( j == 0 || j == playsize) || (i == 0 || i == playsize)){
    if ( i == 0 ) {         // Cases where row = 0.
      value = array[j-1][0];
     	if (value == 'X') {
       	   alivearound++;
           }
       value = array[j+1][0];
         if (value == 'X') {
          alivearound++;
          }
       value = array[j-1][1];
         if (value == 'X') {
          alivearound++;
          }
       value = array[j][1];
         if (value == 'X') {
          alivearound++;
          }
       value = array[j+1][1];
         if (value == 'X') {
          alivearound++;
          }
       setLife(j,i,alivearound);
     }

    else if ( i == playsize ) { //Last row, row = 40. 
       value = array[j-1][playsize-1];
         if (value == 'X') {
          alivearound++;
          }
       value = array[j][playsize-1];
         if (value == 'X') {
          alivearound++;
          }
       value = array[j+1][playsize-1];
         if (value == 'X') {
          alivearound++;
          }
       value = array[j-1][playsize];
         if (value == 'X') {
          alivearound++;
          }
       value = array[j-1][playsize];
         if (value == 'X') {
          alivearound++;
          }
     setLife(j,i,alivearound);
    }

    else if( j == 0 ) { // Cases where coloumn = 0. 
       value = array[1][i-1];
         if (value == 'X') {
          alivearound++;
          }
       value = array[1][i];
         if (value == 'X') {
          alivearound++;
          }
       value = array[1][i+1];
         if (value == 'X') {
          alivearound++;
          }
       value = array[0][i-1];
         if (value == 'X') {
          alivearound++;
          }
        value = array[0][i+1];
         if (value == 'X') {
          alivearound++;
          }
     setLife(j,i,alivearound); 
    }

    else  { // Last edge, column = 40.
       value = array[playsize-1][i-1];
         if (value == 'X') {
          alivearound++;
          }    
       value = array[playsize-1][i];
         if (value == 'X') {
          alivearound++;
          }
       value = array[playsize-1][i+1];
         if (value == 'X') {
          alivearound++;
          }
       value = array[playsize][i-1];
         if (value == 'X') {
          alivearound++;
          }
       value = array[playsize][i+1];
         if (value == 'X') {
          alivearound++;
          }
    setLife(j,i,alivearound); 
    }
   }
     
 // Everything else
 else {
 value = array[j-1][i-1];     // Check around the cell and count the tally
   if ( value == 'X') {     
      alivearound++; }
 
      value = array[j][i-1]; 
   if ( value == 'X') {
      alivearound++; }
     
      value = array[j+1][i-1]; 
   if ( value == 'X') {
       alivearound++;}

   value = array[j-1][i]; 
   if ( value == 'X') {
       alivearound++; }

   value = array[j+1][i]; 
   if ( value == 'X') {
       alivearound++;
     }

   value = array[j-1][i+1]; 
   if ( value == 'X') {
      alivearound++; }
   
   value = array[j][i+1]; 
   if ( value == 'X') {
      alivearound++; }
  
   value = array[j+1][i+1];
   if ( value == 'X') {
      alivearound ++; } // Done with alive around cases. 
    setLife(j,i,alivearound); 
   }      
}

void Lifeboard::setLife(int j, int i, int alivearound)
{  
   char value = ' '; // takes the position of cells around and the amount of alive cells
   value = array[j][i]; // To determine the new state in the next board. 

   if ( alivearound < 2 && value == 'X') {
     newarray[j][i] = ' ';
     }
  else if ( value == 'X' && alivearound == 2)
    {
    newarray[j][i] = 'X';
    }
  else if (value == 'X' && alivearound == 3)
    {
    newarray[j][i] = 'X';
   }
  else if ( value == 'X' && alivearound > 3)
   {
   newarray[j][i] = ' '; 
   }
  else if (value == ' ' && alivearound == 3) 
   {
   newarray[j][i] = 'X';
   }
}

void Lifeboard::makeBlankboard()  //Sets up a blank board
{
     int j = 0;  
 for (int i = 0; i < size; i++)
  {
  for (int j = 0; j < size; j++)
   {
     array[j][i] = ' ';
     }
   }
}

void Lifeboard::showBoard() 
{
   system("clear"); // Clear the old board
 
     for (int l = 0; l < size+1; l++) {  // Set up border
      cout << "-" << " "; 
       }
   cout << endl; 
 
   int j = 0; 
     for (int i = 0; i < size; i++)
        {
         for (int j = 0; j < size; j++)
           {
           cout << array[j][i] << " ";  
           }
        cout << " |" << endl; // Creates a right edge
     }    
}

void Lifeboard::newBoard()
{
  for (int i = 0; i < size; i++) //copies the boards. 
     {
       for ( int j= 0; j < size; j++)
       {    
              array[j][i] = newarray[j][i];
         }  
    } 
}    
