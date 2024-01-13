# Knapsack problem
此題目為我們有一個背包，可負重K
有n件物品，其價值為 $V_{1}$, $V_{2}$, ..., $V_{n}$
此n件物品重量為 $W_{1}$, $W_{2}$, ..., $W_{n}$
背包可裝的最大價值為多少？

此問題分為兩種
1. Fractional knapsack problem
2. 0-1 knapsack problem

## Fractional knapsack problem
Fractional意思是說我們可以選擇要拿多少，例如說第一件物品重量為5kg，我們可以選擇拿1到5kg

此類問題可以用greedy algorithm來解，一直裝最有價值的物品，直到背包無法再裝

### Fractional example
假設包包可負重5kg
物品價值及其重量如下表

| Item    | Value | Weight |
| ------- | ----- | ------ |
| $I_{1}$ | 6     | 1      |
| $I_{2}$ | 10    | 2      |
| $I_{3}$ | 12    | 3      |

可獲得最大價值？

Step:
1. Calculate value/weight for each item
   $I_{1} \ \frac{v}{p} = \frac{6}{1} = 6$
   $I_{2} \ \frac{v}{p} = \frac{10}{2} = 5$
   $I_{3} \ \frac{v}{p} = \frac{12}{3} = 4$
2. Select the largest $\frac{v}{p}$ sequentially
3. Chose $I_{1}$ first, 5 > 1, take it all, knapsack can still carry 4kg, knapsack value = 6
4. Chose $I_{2}$, 4 > 2, take it all, Knapsack can still carry 2kg, Knapsack value = 16
5. Chose $I_{3}$, 3 > 2, so we take 2kg, knapsack can't carry anymore, knapsack value = 24


## 0-1 knapsack problem
此問題則稍做改變，要馬全拿，要馬不拿，無法只拿部份
這題無法再繼續使用greedy algorithm，因為無法保證每次挑選的最佳解為全域最佳解

以上題的範例為示範
Step:
1. Chose $I_{1}$, 5 > 1, knapsack can still carry 4kg, knapsack value = 6
2. Chose $I_{2}$, 4 > 2, knapsack can still carry 2kg, knapsack value = 16
3. 2 < 3, we can't chose $I_{3}$, knapsack value = 16

但實際上這個簡單範例，我們可以得知最佳解為拿 $I_{2}$ 及 $I_{3}$ ，可得knapsack value = 10+12 = 22

因此0-1 knapsack problem要用dp來解，去紀錄所有的情況
dp[i][k]表示在有前i件物品的情況下，我們負重為k能獲得的最大利益

我們令物品 $I_{i}$ 的價值為 $V_{i}$ ，重量為 $W_{i}$ 

dp[i][k]有三種情況
1. i = 0 or k = 0 (此情況表示沒有物品或是無法負重)
   => dp[i][k] = 0
2. i >= 1 and $W_{i}$ > k (此情況表示我們無法獲取當前的物品 $I_{i}$ )
   => dp[i][k] = dp[i-1][k]
   (因為無法獲取 $I_{i}$ ，所以最大利益為不考慮 $I_{i}$ 的情況)
3. i >= 1 and $W_{i} <= k$ (此情況表示我們可以考慮選 $I_{i}$ )
   => dp[i][k] = max($V_{i}$ + dp[i-1][k-$W_{i}$], dp[i-1][k])
   (考慮拿了 $I_{i}$ 是否會比不拿的價值來的高)

### 0-1 example
題目同Fraction example差別只在只能拿與不拿

Create dp table
   
|   | 0  | 1  | 2  | 3  | 4  | 5  |
| - | -- | -- | -- | -- | -- | -- |
| 0 | 0  | 0  | 0  | 0  | 0  | 0  |
| 1 | 0  | 6  | 6  | 6  | 6  | 6  |
| 2 | 0  | 6  | 10 | 16 | 16 | 16 |
| 3 | 0  | 6  | 10 | 16 | 18 | 22 |

Explanation for each case
1. Take dp[0][1] and dp[1][0] for examples
   dp[0][1] there is no item so value = 0
   dp[1][0] knapsack can't carry anything so value = 0
2. Take dp[2][1] for example, knapsack can carry 1kg, so we can't carry $I_{2}$
   so dp[2][1] = dp[1][1] = 6
3. Take dp[2][2] for example, knapsack can carry $I_{2}$
   so dp[2][2] = max(10+dp[1][0], dp[1][2]) = 10

## Implement
### C++
```cpp=
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
```

### Python
```python=
class knapsack:
    def __init__(self):
        self.dp = [] 

    def max_value_frac(self, item: list[list[int]], k: int) -> int:
        n = len(item)
        max_val = 0

        for i in range(n):
            item[i][0] /= item[i][1]

        item = sorted(item, reverse=True)
        for i in range(n):
            if k >= item[i][1]:
                max_val += item[i][0]*item[i][1]
                k -= item[i][1]
            else:
                max_val += item[i][0]*k
                break

        return int(max_val)

    def max_value_01(self, item: list[list[int]], k: int) -> int:
        n = len(item)
        self.dp = [[0]*(k+1) for i in range(n+1)]

        for i in range(1, n+1):
            for j in range(1, k+1):
                if j < item[i-1][1]:
                    self.dp[i][j] = self.dp[i-1][j]
                else:
                    self.dp[i][j] = max(item[i-1][0] + self.dp[i-1][j-item[i-1][1]], self.dp[i-1][j])

        return int(self.dp[n][k])
```

###### `DP` `greedy`
