#include <iostream>
#include <ctime>
#include <random>
#include "QuickSort.h"
#include "ShakeSort.h"
#include <chrono>
#include <fstream>
#include "ArrayCreating.h"




int main()
{
	std::ofstream slow;
	slow.open("binary.txt");
	int* arr;
	for (int i = 1; i <= 10; i++)
	{
		arr = new int[i];
		makeListWithUniqueElements(arr, i);
		QuickSortMid(arr, i);
		for (int j = 0; j < i; ++j)
		{
			std::cout << arr[j] << std::endl;
		}
		std::cout << std::endl;
	}
	system("pause");
}