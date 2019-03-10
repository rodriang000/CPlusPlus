// list.cpp

#include"lsort.h"
#include<memory>

List::List(){
	head = nullptr;
	size = 0;
}


List::~List(){
	Node *next = new Node{};
	for (Node *curr = head; curr != nullptr; curr = next){
		next = curr->next;
		delete curr;
	}
}

void List::push_front(const std::string &s){
	
	Node *newNode = new Node{};
	newNode ->string = s;
	
	// Check if string is an int
	try{
		newNode->number = std::stoi(s);
	}
	catch(const std::invalid_argument &ia){
		newNode ->number = 0;
	}

	if(head){
		newNode->next = this->head;
	}
	else{
		newNode->next = nullptr;
	}

	head = newNode;
	size++;
	
}
