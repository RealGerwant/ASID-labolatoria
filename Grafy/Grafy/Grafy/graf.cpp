#include "graf.h"
#include <random>
#include <ctime>


void graf::SetSize(int s)
{
	this->size = s;
}

graf::graf()
{
}


graf::~graf()
{
}


void graf::RandGraphInMatrix(int density)
{
	AdjacencyMatrix = new bool *[this->size];
	for (int i = 0; i < this->size; i++)
	{
		AdjacencyMatrix[i] = new bool[this->size];
	}
	srand(time(NULL));

	for ( int i = 0; i < this->size; i++)
		for (int j = 0; j < this->size; ++j) {
			AdjacencyMatrix[j][i] = 0;
		}
	
	int m = (int)((density * this->size * (this->size - 1)) *0.5f);

	int i, j;
	while (!m == 0) {
		i = rand() % (this->size + 1);
		j = rand() % (this->size + 1);
		if ((i != j) && (AdjacencyMatrix[j][i] == 0)) {
			AdjacencyMatrix[i][j] = 1;
			--m;
		}
	}

}