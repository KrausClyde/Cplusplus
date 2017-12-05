#include "algorithm.h"
#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


int quicksort(int arry[], int size, int low, int high)
{
	int key = arry[low];
	int i = low, j = high;
	if (low >= high)
		return 0;
	while (i < j)
	{
		while (i < j && key < arry[j])
			j--;
		arry[i] = arry[j];

		while (i < j && arry[i] < key)
			i++;
		arry[j] = arry[i];

	}
	arry[i] = key;
	quicksort(arry, size, low, i - 1);
	quicksort(arry, size, i + 1, high);
	return 0;
}