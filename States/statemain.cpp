// A driver that will test the school class.
// Reads info and makes a vector of it, then it displays the data. 


#include <iostream> 
#include <string> 
#include <fstream> 
#include <vector> 
using namespace std; 
#include "state.h" 

void displayall(vector<State> &); 
void displayname(vector<State> &); 
void stateInfo(vector<State> &, string); 
void stateEstab(vector<State> &, int); 

int main() 
{
  cout << endl; // Make it look nice. 
  ifstream ifs; 
  string file; 
  string abb, name, cap, pop_s, year_s, reps_s; 
  int pop, year, reps; 
  vector <State> states; 
  State stt;

  cout << "Enter the name of the file my good sir/madame: "; 
  cin >> file; 
  ifs.open(file); 
  if (!ifs) {
   cout << "Gimme a good file, " << file << " isn't valid :( " << endl; 
   return 1; 
  }

  while(ifs.peek() != EOF)  {
   getline(ifs, abb, ','); 
   getline(ifs, name, ','); 
   getline(ifs, cap, ','); 
   getline(ifs, pop_s, ','); 
   getline(ifs, year_s, ','); 
   getline(ifs, reps_s, '\n'); 
   pop = stoi(pop_s); 
   year = stoi(year_s); 
   reps = stoi(reps_s); 
   stt = State(abb, name, cap, pop, year, reps); 
   states.push_back(stt); 
   }

 // Menu options for user 
 cout << "Pick an option to learn more about states.. n' stuff\n"; 
 int q = 0;
 int choice; 

   while (q == 0) 
   {
   cout << endl; 
   cout << "0: End the program.\n"; 
   cout << "1: Display all the information, I MEAN ALL the information.\n"; 
   cout << "2: Show all state names and abbreviations.\n"; 
   cout << "3: Show information on a specific state.\n"; 
   cout << "4: See if a state was established in a certain year.\n";
   cin >> choice; 

   // Switch choices
   string Userstate; 
   int Useryear;  
     switch (choice) 
       {
         case 0: 
         q = 1; 
         cout << "Adios amigo.\n"; 
         break; 
   
         case 1: 
         displayall(states); 
         break;
 
         case 2:
         displayname(states); 
         break;

         case 3: 
         cout << "Enter the state's abbreviation, ALL CAPS please.\n"; 
         cin >> Userstate; 
         stateInfo(states, Userstate); 
         break; 
        
         case 4:
         cout << "Yo dawg, can you help a homeboy out and gimme a year.\n";   
         cin >> Useryear;
         cout << endl; 
	 stateEstab(states, Useryear);
         break; 
 
         default: 
         break; 
       }
    } 
    return 0; 
 
  }

// Show the states 
void displayall(vector<State> &s)  
{ 
  for (auto it = s.begin(); it != s.end(); it++) {
     cout << "Name:" << it->getName() << "(";  
     cout <<  it->getAbb() << "):";  
     cout <<  it->getCap() << " "; 
     cout << "Population:" << it->getPop() << " "; 
     cout << "Year:" <<  it->getYear() << " "; 
     cout << "# of Reps:" <<  it->getReps() << endl << endl; 
   }
}

void displayname(vector<State> &n)
{
  for (auto it = n.begin(); it != n.end(); it++) {
     cout << "Name:" << it->getName() << "("; 
     cout << it->getAbb() << ") "; 
     cout <<  endl; 
  }
}

void stateInfo(vector<State> &s, string Abr) 
{
  int validAbb = 0; 
  for (auto it = s.begin(); it != s.end(); it++) {
    if ( Abr == it->getAbb())
      {
     cout << "Name:" << it->getName() << "(";
     cout <<  it->getAbb() << "):";
     cout <<  it->getCap() << " ";
     cout << "Population:" << it->getPop() << " ";
     cout << "Year:" <<  it->getYear() << " ";
     cout << "# of Reps:" <<  it->getReps() << endl << endl;
     validAbb = 1;  
     break;
      }
   }
    if (validAbb == 0)
    { 
    cout << "That wasn't a valid abbriviation my dude.\n"; 
    }
}

void stateEstab(vector<State> &s, int Useryear) 
{ 
   int validYear = 0;   
   for (auto it = s.begin(); it != s.end(); it++) {
    if ( Useryear == it->getYear())
      {
     cout << "Name:" << it->getName() << "(";
     cout <<  it->getAbb() << "): ";
     cout << "Year:" <<  it->getYear() << "\n"; 
     validYear = 1; // Saying that there was a valid year found
      }
  }
  if (validYear == 0)
  { 
  cout << "Sorry bruv that ain't a valid year.\n"; 
  }
}

