class voting:
    def __init__(self):
        self.candidate = 0
        self.count = 0

    def vote_algo(self, nums: list) -> int:
        for n in nums:
            if self.count == 0:
                self.candidate = n
                self.count += 1
            elif self.candidate == n:
                self.count += 1
            else:
                self.count -= 1

        return self.candidate
