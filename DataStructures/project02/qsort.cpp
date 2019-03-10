//qsort.cpp

#include"lsort.h"
#include<cstdlib>
#include<array>

void qsort_sort(List &l, bool numeric){

	Node** d = new Node*[l.size];
	auto compare = (numeric ? void_number_compare : void_string_compare);
	size_t i = 0;
	
	// Fill array with Nodes
	for (auto curr = l.head; curr != nullptr; curr = curr->next){
		d[i++] = curr;
	}

	// Sort the dang thing
	qsort(d, l.size, sizeof(Node *), compare);
	
	//Link the nodes again
	for(size_t i = 0; i < l.size; i++){
		d[i]->next = (i + 1 < l.size ? d[i + 1] : nullptr);
	}
	l.head = d[0];

	delete [] d;
}

