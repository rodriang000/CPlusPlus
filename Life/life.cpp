// Angel Rodriguez 11/7/2017
#include <iostream>
#include <cstring> 
#include "lifeboard.h"
#include <unistd.h>
#include <stdlib.h> 
#include <string>
#include <vector>  
#include <fstream> 
 
using namespace std; 

int main (int argc, char*argv[]) {
  int j, i; 
  Lifeboard myArray;
  myArray.makeBlankboard(); 
  // Version where user enters the live points.  
   int q = 0; 
   char choice; 
  if (argc == 2){
    q = 1; 
  }           // Skip to bottom. 

    while (q == 0) {    
       cout << "Enter an option\n";
       cin >> choice; 
  
      switch (choice)
       {
         case 'a':
         cout << "Enter column, then row.\n"; 
	 cin >> j >> i;
           if ( j > 40 || i > 40 || j < 0 || i < 0 )  // Makes sure that it is within the boundires 
               {
             cout << "I need number between 0 and 40\n";
             break; 
               }      
         myArray.setLive(j,i);
         myArray.showBoard();      
	 break;
         
         case 'r': 

         cout << "Enter column, then row.\n";
         cin >> j >> i; 
           if ( j > 40 || i > 40 || j < 0 || i < 0)  // In bound
               {
             cout << " I need numbers between 0 and 40.\n"; 
             break; 
               }
         
        myArray.setDead(j,i);
        myArray.showBoard();
        break; 
 
         case 'q': 
         q = 1; 
         break; 
	 
	 case 'n':
         myArray.playLife(); 
         myArray.showBoard(); 
         break;
         case 'p': 
          int x = 0; 
            while (x == 0){  //Run forever with no chance of escape.
              myArray.playLife(); 
              myArray.showBoard();
              usleep(150000);
              } 
         break;
       }
     }
  string jstring, istring;   
  char blankchoice;
     if (argc == 2) { 
  	std::ifstream ifs;
  	string filename;
 	filename = argv[1];
  	ifs.open (filename, ifstream::in);
   	  while(!ifs.eof()) {  // Make a vector which has all the comands. 
             choice = ifs.get(); // First value is a command. 

               switch(choice){
                    case 'a':
                   blankchoice = ifs.get(); // Removes the whitespace between command and values
                   getline(ifs, jstring, ' '); // Gets the values of the j untill space
                   getline(ifs, istring, '\n'); // Gets the value of i until there is a space
                   j = atoi(jstring.c_str()); // Convert both to ints.
                   i = atoi(istring.c_str()); 
        	   myArray.setLive(j,i);
                   myArray.showBoard();
                    break;
                    case 'p':
                    int x = 0;
                       while (x == 0){  //Run forever with no chance of escape.
              	       myArray.playLife();
              	       myArray.showBoard();
              	       usleep(105000);
                      }
                   break; 
                 }
           }
      }
return 0;
  }
