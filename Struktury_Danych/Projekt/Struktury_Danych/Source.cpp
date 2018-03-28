#include <iostream>
#include <ctime>
#include <random>
#include "QuickSort.h"
#include <chrono>
#include <fstream>
#include "ArrayCreating.h"




int main()
{
	std::ofstream slow;
	slow.open("binary2.txt");
	int* arr;
	for (int i = 10000; i <= 200000; i+=10000)
	{

		arr = new int[i];
		std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
		makeListWithUniqueElements(arr, i);
		QuickSortMid(arr, i);
		std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> time = end - start;
		slow << i << " " << time.count() << std::endl;
		std::cout << i << "done" << std::endl;

	}
	system("pause");
}