# include <bits/stdc++.h>

using namespace std;

class voting
{
	public:
		int candidate, count;
		voting()
		{
			candidate = 0;
			count = 0;
		}

		int vote_algo(vector<int> &nums)
		{
			const int n = nums.size();

			for(int i = 0; i < n; i++)
			{
				if(count == 0)
				{
					candidate = nums[i];
					count++;
				}
				else if(candidate == nums[i])
					count++;
				else
					count--;
			}

			return candidate;
		}
};
