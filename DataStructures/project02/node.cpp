// node.cpp

#include"lsort.h"
#include<iostream>
#include<string>
#include<string.h>

bool node_number_compare(const Node *a, const Node *b){
	return(a->number < b->number);
}

bool node_string_compare(const Node *a, const Node *b){
	int comp = a->string.compare(b->string);

	if(comp < 0){
		 return true;
	}
	else{
		return false;
	}
}

int void_number_compare(const void *a, const void *b){
	return (((*(Node **)a)->number) - ((*(Node**)b)->number));
}

int void_string_compare(const void *a, const void *b){
	
	Node **ap = (Node **)a;
	Node **bp = (Node **)b;
	
	return(strcmp(((*ap)->string).c_str(),((*bp)->string).c_str()));	
}

void dump_node(Node *n){
	if(n){
		std::cout << n->string << std::endl;
		dump_node(n->next);
	}
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
