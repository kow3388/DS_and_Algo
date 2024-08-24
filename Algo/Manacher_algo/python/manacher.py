class manacher:
    def __init__(self, s: str):
        #original string
        self.s = s

        self.new_s = '#'
        for i in range(len(self.s)):
            self.new_s += self.s[i]
            self.new_s += '#'

        self.n = len(self.new_s)
        self.lps_table = [0] * self.n

    def lps(self):
        #center: 我們能看到最右邊的palidrome的center
        center = 1
        #center_right: 我們能看到最遠的位置
        center_right = 2
        #max_len: current lps length
        max_len = 0
        #lps_center: current lps center
        lps_center = 0

        #start from index 1, because index 0 will always be 0
        for i in range(1, self.n):
            if i < center_right:
                #we can initial that the lps of i is case 1 or case 2
                self.lps_table[i] = min(self.lps_table[2*center - i], center_right - i)
            else:
                #i >= center_right means we cann't use the feature of palidrome to initalize lps
                self.lps_table[i] = 0

            #update the length of palidrome that i is the center
            while (i - self.lps_table[i] - 1 >= 0 and \
                   i + self.lps_table[i] + 1 < self.n and \
                   self.new_s[i - self.lps_table[i] - 1] == self.new_s[i + self.lps_table[i] + 1]):
                self.lps_table[i] += 1
            
            #update lps
            if self.lps_table[i] > max_len:
                max_len = self.lps_table[i]
                lps_center = i

            #update center and center_right
            if i + self.lps_table[i] - 1 > center_right:
                center_right = i + self.lps_table[i] - 1
                center = i

        start = int((lps_center - max_len) / 2)

        return self.s[start : start + max_len]
