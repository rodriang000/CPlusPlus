// Angel Rodriguez 11/7/2017
// lifeboard.h
#include <cstring>  

class Lifeboard {
  public: 
  Lifeboard();  
  ~Lifeboard();  
  void setLive(int, int);
  void setDead(int, int); 
  void makeBlankboard(); 
  void playLife();
  void checkLife(int, int);
  void setLife(int,int,int);    
  void showBoard(); 
  void newBoard(); 
  private: 
  char array[41][41];
  char newarray[41][41];
  };
