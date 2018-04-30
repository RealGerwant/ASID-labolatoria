#pragma once


struct element
{
	int value;
	element * next = 0;
	element();
};

class list
{
private:
	element * first;
	element * last;
public:
	void AddElement(int val);
	void PrintAllElements();
	list();
	~list();
};

