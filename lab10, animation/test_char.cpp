// test_char.cpp
// an example to test the key press
// the key, if printable, will be displayed at the terminal
#include <iostream>
using namespace std;
#include "gfx.h"

int main()
{
  int wd = 500;  // window width
  int ht = 400;  // window height
  char c; 

  // Open a new window for drawing.
  gfx_open(wd, ht, "My window");

  while(true) {
    c = gfx_wait();       // wait for the user to hit a key
    cout << c << endl;    // display the key's character
    if (c == 'q') break;  // quit when a 'q' is pressed
  }

  return 0;
}

