//stl.cpp

#include"lsort.h"
#include<algorithm>
#include<iostream>
#include<vector>

void stl_sort(List &l, bool numeric){
	Node** d = new Node*[l.size];
	auto compare = (numeric ? node_number_compare : node_string_compare);
	size_t i = 0;

	// Fill array with nodes
	for (auto curr = l.head; curr != nullptr; curr = curr->next){
		d[i++] = curr;
	}
	
	// Sort arry
	std::sort(d, d + l.size, compare);
	
	// Link all these nodes
	for (size_t i = 0; i < l.size; i++){
		d[i]->next = (i + 1 < l.size ? d[i + 1] : nullptr);
	}
	l.head = d[0];
	
	delete [] d;
}
