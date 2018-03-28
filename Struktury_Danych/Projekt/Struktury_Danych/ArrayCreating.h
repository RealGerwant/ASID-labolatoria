#pragma once
#ifndef ArrayCrearing_h
#define ArrayCrearing_h

#include <iostream>
#include <ctime>
#include <random>
#include "ShakeSort.h"
#include <math.h>



bool IsVarInSortedArrayBinary(int* Array, int looking_for, int start_index, int end_index)
{
	if (start_index <= end_index)
	{
		int mid_index = start_index + ((end_index - start_index) / 2);

		if (Array[mid_index] == looking_for)
		{
			return true;
		}

		if (looking_for > Array[mid_index])
		{
			return IsVarInSortedArrayBinary(Array, looking_for, mid_index + 1, end_index);
		}

		if (looking_for < Array[mid_index])
		{
			return IsVarInSortedArrayBinary(Array, looking_for, start_index, mid_index - 1);
		}
	}
	return false;
}


int largeRandomInt(int left_border, int right_border)
{
	int tmp;
	tmp = rand() % (right_border - left_border) + left_border;
	tmp <<= 15;
	tmp = (tmp ^ rand()) % (right_border - left_border) + left_border;
	return tmp;
}
void makeListWithUniqueElements(int *A, int size)
{
	int right_border = size * 1;
	srand(time(NULL));
	int* B;
	B = new int[size];

	A[0] = largeRandomInt(0,right_border);
	B[0] = A[0];

	for (int i = 1; i < size; ++i)
	{
		int tmp = largeRandomInt(0, right_border);
		while (true)
		{
			if (IsVarInSortedArrayBinary(B, tmp, 0, i-1))
			{
				tmp = largeRandomInt(0,right_border);
			}
			else
			{
				A[i] = tmp;
				B[i] = tmp;
				ShakeSort(B, i+1);
				break;
			}

		}

	}
	delete[] B;
}


#endif // !ArrayCrearing_h
