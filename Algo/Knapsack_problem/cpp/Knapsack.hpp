#include <bits/stdc++.h>

using namespace std;

class knapsack
{
	public:
		vector<vector<int>> dp;
		//greedy
		int max_value_frac(vector<vector<int>> item, int k)
		{
			const int n = item.size();
			int max_val = 0;
			//calculate value per weight of each item
			for(int i = 0; i < n; i++)
				item[i][0] /= item[i][1];
			//sort the value per weight (descending order)
			sort(item.begin(), item.end(), [](vector<int> &a, vector<int> &b){return a[0] > b[0];});
			//chose the most largest value of each time
			for(int i = 0; i < n && k > 0; i++)
			{
				if(k >= item[i][1])
				{
					max_val += item[i][0]*item[i][1];
					k -= item[i][1];
				}
				else
				{
					max_val += item[i][0]*k;
					k = 0;
				}
			}

			return max_val;
		}
		//DP
		int max_value_01(vector<vector<int>> &item, int k)
		{
			const int n = item.size();
			//initial all dp table to 0
			dp.resize(n+1, vector<int>(k+1, 0));

			for(int i = 1; i <= n; i++)
				for(int j = 1; j <= k; j++)
					if(j < item[i-1][1])
						dp[i][j] = dp[i-1][j];
					else
						dp[i][j] = max(item[i-1][0]+dp[i-1][j-item[i-1][1]], dp[i-1][j]);

			return dp[n][k];
		}
};
