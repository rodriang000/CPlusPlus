// Implementation for the state class

#include "state.h" 

State::State() {  }

State::State(string abb, string name, string cap, int pop, int year, int reps)
{ StateAbb = abb; StateName = name; StateCap = cap;  StatePop = pop; StateYear = year; StateReps = reps; } 

State::~State() { }

void State::setAbb(string abb)
{ StateAbb = abb; }

void State::setName(string name)
{ StateName = name; }

void State::setCap(string cap) 
{ StateCap = cap; }

void State::setPop(int pop)
{  StatePop = pop; } 

void State::setYear(int year) 
{  StateYear = year; }

void State::setReps(int reps)
{  StateReps = reps; }

string State::getAbb()
{ return StateAbb; }

string State::getName() 
{ return StateName; }

string State::getCap() 
{ return StateCap; }

int State::getPop()
{ return StatePop; }

int State::getYear()
{ return StateYear; }

int State::getReps()
{ return StateReps; }


