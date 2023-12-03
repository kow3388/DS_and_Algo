#include "Kadane.hpp"
#include <bits/stdc++.h>

//maximum subarray
int main()
{
	std::vector<int> arr1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	std::vector<float> arr2 = {-2.5, 1.4, -3.9, 4.0, -1.2, 2.2, 1.5, -5.6, 4.1};

	Kadane<int> k1(arr1);
	Kadane<float> k2(arr2);
	int ans1 = k1.algo();
	float ans2 = k2.algo();

	std::cout << "The maximum subarray of array1 = " << ans1 << std::endl;
	std::cout << "The maximum subarray of array2 = " << ans2 << std::endl;

	return 0;
}
