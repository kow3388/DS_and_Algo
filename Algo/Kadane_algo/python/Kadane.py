class Kadane:
    def __init__(self, nums):
        self.nums = nums

    def algo(self):
        if len(self.nums) == 1:
            return self.nums[0]

        max_ending_here = self.nums[0]
        max_so_far = self.nums[0]

        for num in self.nums[1:]:
            max_ending_here = max(num, max_ending_here + num)
            max_so_far = max(max_so_far, max_ending_here)

        return max_so_far
