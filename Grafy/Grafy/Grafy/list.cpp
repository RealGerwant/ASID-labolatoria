#include "list.h"
#include <iostream>

void list::AddElement(int val) {
	element * nowy = new element;
	nowy->value = val;
	nowy->next = 0;
	if ( this-> first == 0){
		this->first = nowy;
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
	if (!first->next == 0){
		std::cout << first->value << std::endl;
	}
	element * tmp = new element;
	tmp->next = this->first;
	while (!tmp->next == 0){
		std::cout << tmp->value<<" ";
		tmp = tmp->next;
	}
}

list::list()
{
}


list::~list()
{
}
