#include "quicksort.h"
#include <iostream>


int partition(std::vector<int>& arr, int left, int right)
{
	int pivot = arr[right];
	int idx = left;
	for (int i = left; i < right; i++)
	{
		if (arr[i] <= arr[right])
		{
			int temp = arr[idx];
			arr[idx] = arr[i];
			arr[i] = temp;
			idx++;
		}
	}
	int temp = arr[right];
	arr[right] = arr[idx];
	arr[idx] = temp;
	return idx;

}

void quicksort(std::vector<int>& arr, int left, int right)
{
	if (left < right)
	{
		int pivot = partition(arr, left, right);
		quicksort(arr, left, pivot - 1);
		quicksort(arr, pivot + 1, right);
	}
}