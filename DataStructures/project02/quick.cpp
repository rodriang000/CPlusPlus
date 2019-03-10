// quick.cpp

#include "lsort.h"

#include <iostream>

// Prototypes

Node *qsort(Node *head, CompareFunction compare);
void  partition(Node *head, Node *pivot, Node *&left, Node *&right, CompareFunction compare);
Node *concatenate(Node *left, Node *right);

// Implementations

void quick_sort(List &l, bool numeric) {
  if(numeric){
    l.head = qsort(l.head, node_number_compare);
}
  else{
      l.head = qsort(l.head, node_string_compare);
  }
}

Node *qsort(Node *head, CompareFunction compare) {
  if (head == nullptr || head -> next == nullptr){
      return head;
  }

  Node *left = nullptr;
  Node *right = nullptr;

  partition(head, head, left, right, compare);
  left = qsort(left, compare);
  right = qsort(right, compare);
  return concatenate(left, concatenate(head, right));

}

void partition(Node *head, Node *pivot, Node *&left, Node *&right, CompareFunction compare) {
	
	pivot = head;
	Node *lptr = nullptr;
	Node * rptr = nullptr;
	head = head -> next;
	while (head != nullptr){
    	if(compare(head, pivot)){
        	if (left != nullptr ) {
            	lptr->next = head;
            	lptr = lptr->next;
        	}
        	else{
            	left = head;
            	lptr = head;
        	}

    	}
    	else {
        	if ( right != nullptr) {

            	rptr->next = head;
            	rptr = rptr->next;
        	}
        	else {
            	right = head;
            	rptr = head;
        	}
		}
		head = head-> next;
    	
    	pivot->next = nullptr;
    	if(lptr){
        	lptr->next = nullptr;
    	}
    	if(rptr){
       		rptr->next = nullptr;
    	}
	}
}
Node *concatenate(Node *left, Node *right){
    Node *head = left;
    if(!left){ // Could be just left, need to check
        return right;
    }

    while(left -> next != nullptr) {
        left = left ->next;
    }
    left -> next = right;
    return head;
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
