#include <string> 
using namespace std; 

class State {
  public: 
   State(); 
   State(string, string, string, int, int, int); 
   ~State (); 
   void setAbb(string); 
   void setName(string); 
   void setCap(string); 
   void setPop(int); 
   void setYear(int); 
   void setReps(int);
   string getAbb(); 
   string getName(); 
   string getCap(); 
   int getPop(); 
   int getYear(); 
   int getReps(); 
  private: 
   string StateAbb; 
   string StateName;
   string StateCap;  
   int StatePop; 
   int StateYear; 
   int StateReps; 
};
