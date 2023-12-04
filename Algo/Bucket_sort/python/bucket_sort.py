import collections

class Bucket_sort:
    def __init__(self):
        self.bucket = collections.defaultdict(list)

    def Sort(self, nums: list[int]) -> list[int]:
        low, high, n = min(nums), max(nums), len(nums)

        for num in nums:
            idx = n-1 if num == high else (num - low)*n//(high - low)
            self.bucket[idx].append(num)

        for i in range(len(self.bucket)):
            self.bucket[i] = sorted(self.bucket[i])

        index = 0
        for i in range(len(nums)):
            for j in range(len(self.bucket[i])):
                nums[index] = self.bucket[i][j]
                index += 1

        print(nums)

        return nums
