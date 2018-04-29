#pragma once


struct element
{
	int value;
	element * next = 0;
};

class list
{
private:
	element * first = 0;
public:
	void AddElement(int val);
	void PrintAllElements();
	list();
	~list();
};

