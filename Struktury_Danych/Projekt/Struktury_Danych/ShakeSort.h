 #pragma once
#ifndef ShakeSort_h
#define ShakeSort_h


void ShakeSort(int *Array, int size_of_array, bool reverse = false)
{
	int bottom = 0, top = size_of_array - 1;
	bool change = true;
	if (reverse == false)
	{
		while (change == true)
		{
			change = false;
			for (int i = bottom; i < top; ++i)
			{
				if (Array[i] >Array[i + 1])
				{
					int tmp = Array[i];
					Array[i] = Array[i + 1];
					Array[i + 1] = tmp;
					change = true;
				}
			}
			top--;
			for (int i = top - 1; i > bottom; --i)
			{
				if (Array[i] > Array[i + 1])
				{
					int tmp = Array[i];
					Array[i] = Array[i + 1];
					Array[i + 1] = tmp;
					change = true;
				}
			}
		}
	}
	else
	{
		while (change == true)
		{
			change = false;
			for (int i = bottom; i < top; ++i)
			{
				if (Array[i] <Array[i + 1])
				{
					int tmp = Array[i];
					Array[i] = Array[i + 1];
					Array[i + 1] = tmp;
					change = true;
				}
			}
			top--;
			for (int i = top - 1; i > bottom; --i)
			{
				if (Array[i] < Array[i + 1])
				{
					int tmp = Array[i];
					Array[i] = Array[i + 1];
					Array[i + 1] = tmp;
					change = true;
				}
			}
		}
	}

}

#endif // !ShakeSort_h
