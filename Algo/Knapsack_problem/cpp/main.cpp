#include "Knapsack.hpp"
#include <bits/stdc++.h>

using namespace std;

int main()
{
	//item[i][0] means value, item[i][1] means weight
	vector<vector<int>> item = {{6, 1},
				    {10, 2},
				    {12, 3}};
	//Ther knapsack load-bearing
	int k = 5;
	knapsack K;
	
	int max_val_frac = K.max_value_frac(item, k);
	int max_val_dp = K.max_value_01(item, k);
	cout << "The fraction knapsack problem (greedy)" << endl;
	cout << "The max profit is " << max_val_frac << endl;
	cout << "The 0-1 knapsack problem (DP)" << endl;
	cout << "The max profit is " << max_val_dp << endl;

	return 0;
}
