from Knapsack import knapsack

if __name__ == '__main__':
    item1 = [[6, 1],
            [10, 2],
            [12, 3]]
    item2 = [[6, 1],
            [10, 2],
            [12, 3]]
    K = 5
    k = knapsack()
    max_val_frac = k.max_value_frac(item1, K)
    max_val_dp = k.max_value_01(item2, K)

    print("The fraction knapsack problem (greedy)")
    print("The max profit is ", max_val_frac)
    print("The 0-1 knapsack problem (DP)")
    print("The max profit is ", max_val_dp)
