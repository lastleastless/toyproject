#include "quicksort.h"
#include <iostream>
using namespace std;

int main()
{
	vector<int> arr = {1,3,4,5,2,4};
	quicksort(arr, 0, (unsigned int)arr.size() - 1);
	for (auto& i : arr)
	{
		cout << i << " ";
	}
	cout << endl;
}