// Thomas Plummer and Angel Rodriguez
// merge.cpp

#include "lsort.h"
#include<iostream>

// Prototypes

Node *msort(Node *head, CompareFunction compare);
void split(Node *head, Node *&left, Node *&right);
Node *merge(Node *left, Node *right, CompareFunction compare);

//Implementations

void merge_sort(List &l, bool numeric){
	if(numeric){
		l.head = msort(l.head, node_number_compare);
	}
	else{
		l.head = msort(l.head, node_string_compare);
	}
}

Node *msort(Node *head, CompareFunction compare){
	if(head == nullptr || head -> next == nullptr){
		return head;
	}
		Node *left = new Node{}, * right = new Node{};
		left = nullptr;
		right = nullptr;
		split(head, left, right);
		left = msort(left, compare);
		right = msort(right, compare);
		head = merge(left, right, compare);
		return head;
}

void split(Node *head, Node *&left, Node *&right){
	Node *fast;
	Node *slow;
	Node *prev = head;
	fast = head;
	slow = head;
	while(fast && fast->next){
		fast = fast->next;
		if(fast){
			fast = fast->next;
			prev = slow;
			slow = slow->next;
		}
	}
	
	left = head;
	right = slow;

	// Sets node after previous to null, so left will stop at midpoint
	prev->next=nullptr;
}


Node *merge(Node *left, Node *right, CompareFunction compare){
	
	if(left == nullptr) return right;
	else if (right == nullptr) return left;
	else if(compare(left, right)){
		left->next = merge(left->next, right, compare);
		return left;
	}
	else{
		right->next = merge(left, right->next, compare);
		return right;
	}

}
