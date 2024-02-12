#include "moore_voting_algo.hpp"
#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
	voting v;

	int majority = v.vote_algo(nums);

	cout << "The input array is" << endl;
	for(int num : nums)
		cout << num << " ";
	cout << endl;

	cout << "The majority element is: " << majority << endl;

	return 0;
}
