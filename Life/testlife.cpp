// A main file to test my board before incorperating into larger production
#include <iostream> 
#include <fstream>
#include <string>
#include <vector> 

using namespace std; 

int main(){

string command, jstring, istring;
ifstream ifs; 
vector<string> v; 

 ifs.open("cross.txt"); 
 while(ifs.peek() !=EOF) {
   getline(ifs, command, ' '); 
   v.push_back(command);
   getline(ifs, jstring, ' '); 
   v.push_back(jstring);
   getline(ifs, istring, '\n'); 
   v.push_back(istring);
   }
  v.pop_back; 
 for (auto it=v.begin(); it < v.end(); it++) {
    cout << *it;
   }
return 0; 
}

