#include "graf.h"
#include "list.h"
#include "LIFO.h"
#include <Windows.h>
#include <iostream>

int main() {
	graf G(4, 0.4f);
	G.PrintAdjacenceyMatrix();
	G.CheckAdjacencyMatrixDensity();
	G.PrintListOfSucessor();
	G.PrintListOfArches();
	G.DFSsort();
	G.PrintLabelsArray();
	G.PrintTopologyOrder();
	
	system("pause");
	

}