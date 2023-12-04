#include "bucket_sort.hpp"
#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector<int> arr1 = {11, 51, 11, 32, 7, 68, 93, 44, 87, 78};

	Bucket_sort bucket;
	bucket.Sort(arr1);

	return 0;
}
