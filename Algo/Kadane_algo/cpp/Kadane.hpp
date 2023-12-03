#include <bits/stdc++.h>

template <typename T>
class Kadane
{
	public:
		std::vector<T> nums;
		Kadane(std::vector<T> arr)
		{
			nums.assign(arr.begin(), arr.end());
		}

		T algo()
		{
			if(nums.size() == 1)
				return nums[0];

			T max_ending_here = nums[0];
			T max_so_far = nums[0];

			for(T num : nums)
			{
				max_ending_here = std::max(num, max_ending_here + num);
				max_so_far = std::max(max_so_far, max_ending_here);
			}

			return max_so_far;
		}
};
