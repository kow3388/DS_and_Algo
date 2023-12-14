#include "heap.hpp"
#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector<int> arr = {1, 4, 5, 6, 8, 2, 9, 3, 7};
	heap h(arr);

	h.push(10);
	h.push(-1);

	h.heap_sort();

	return 0;
}
