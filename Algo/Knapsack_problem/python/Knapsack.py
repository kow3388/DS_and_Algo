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
