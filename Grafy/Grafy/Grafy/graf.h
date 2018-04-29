#pragma once
class graf
{
public:
	int size;
	bool ** AdjacencyMatrix;
	void SetSize(int size);
	void RandGraphInMatrix( int density);
	void CheckAdjacencyMatrixDensity();
	graf();
	~graf();
};

