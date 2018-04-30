#include "list.h"
#include <iostream>
element::element() {
	this->next = 0;
}

void list::AddElement(int val) {
	element * nowy = new element;
	nowy->value = val;
	if (!this->first){
		first = nowy;
	}
	else {
		element * tmp = new element;
		tmp->next = this->first;
		this->first = nowy;
		nowy->next = tmp->next;
	}
}

void list::PrintAllElements()
{
	element * tmp = first;
	while (tmp){
		std::cout << tmp->value<<" ";
		tmp = tmp->next;
	}
}

list::list()
{
	this->first = 0;
	this->last = 0;
}


list::~list()
{
}
