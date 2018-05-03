#include "graf.h"
#include "list.h"
#include <random>
#include <ctime>
#include <iostream>
#include "LIFO.h"

graf::graf(int s, float d)
{
	SetSize(s);
	RandGraphInMatrix(d);
	FillListOfSucessorFormMatrix();
	FillListOfArchesFromMatrix();

}

graf::~graf()
{
}

void graf::PrintLabelsArray() {
	for (int i = 0; i < size; ++i) {
		std::cout << Labes[i][0] << " " << Labes[i][1] << std::endl;
	}
}

void graf::DFSsort() {
	int * holder = new int;
	*holder = 0;
	int * count = new int;
	*count = 0;
	Sort( holder, count);
}

void graf::PrintTopologyOrder() {
	std::cout << "################" << std::endl;
	std::cout << "Topology Order" << std::endl;
	for (int i = 0; i < size; ++i) {
		std::cout << Sorted[i] << " ";
	}
}

void graf::Sort( int * hel, int* c) {
	element * tmp = new element;
	for (int i = 0; i < size; ++i) {
		if (Labes[i][0] == -1)	{
			Labes[i][0] = (*hel)++;
			tmp =ListOfSucessor[i].first;
			while (tmp != 0){
				if (Labes[tmp->value][0] == -1) {
					Sort( hel, c);
				}
				tmp = tmp->next;
			}
			Labes[i][1] = (*hel)++;
			Sorted[(*c)++] = i;
		}
	}
	
}

void graf::FillListOfArchesFromMatrix() {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (AdjacencyMatrix[j][i] == 1) {
				ListOfArches.AddElement(i, j);
			}
		}
	}
}

void graf::FillListOfSucessorFormMatrix() {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (AdjacencyMatrix[j][i] == 1){
				ListOfSucessor[i].AddElement(j);
			}
		}
	}
}

void graf::PrintListOfArches() {
	std::cout << "List of arches" << std::endl;
	ListOfArches.PrintAllElements();
}

void graf::PrintListOfSucessor() {
	for (int i = 0; i < size; i++)
	{
		std::cout << "Vertex " << i<< ": ";
		ListOfSucessor[i].PrintAllElements();
	}
}

void graf::SetSize(int s)
{
	size = s;

	AdjacencyMatrix = new bool *[size];
	for (int i = 0; i < size; i++)
	{
		AdjacencyMatrix[i] = new bool[size];
	}

	this->ListOfSucessor = new ListOfSucssesor[size];

	Labes = new int*[size];
	for (int i = 0; i < size; ++i) {
		Labes[i] = new int[2];
		Labes[i][0] = -1;
		Labes[i][1] = -1;
	}
	Sorted = new int[size];
}

void graf::CheckAdjacencyMatrixDensity()
{
	int  m = 0;
	for ( int i = 0; i < size; i++)	{
		for (int j = 0; j < size; j++) {
			if (AdjacencyMatrix[j][i] == 1){
				++m;
			}
		}

	}
	float density = (2.0f * m) / (size * (size - 1));
	std::cout <<"Graph density: "<< density << std::endl;
}

void graf::PrintAdjacenceyMatrix() {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			std::cout << AdjacencyMatrix[j][i] << " ";
		}
		std::cout << std::endl;
	}
}

void graf::RandGraphInMatrix(float density)
{

	srand(time(NULL));

	for ( int i = 0; i < size; i++)
		for (int j = 0; j < size; ++j) {
			AdjacencyMatrix[j][i] = 0;
		}
	
	int m = (int)((density * size * (size - 1)) *0.5f);

	int i, j;
	while (!m == 0) {
		i = rand() % (size);
		j = rand() % (size);
		if ((i != j) && (AdjacencyMatrix[j][i] == 0)) {
			AdjacencyMatrix[j][i] = 1;
			--m;
		}
	}

}