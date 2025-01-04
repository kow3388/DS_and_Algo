class z_function:
    def __init__(self, s: str):
        self.s = s
        self.len = len(s)
        self.z = [0] * self.len
    
    def cal_z(self) -> None:
        l, r = 0, 0
        for i in range(1, self.len):
            if i < r:
                self.z[i] = min(r- i, self.z[i - l])
            
            while i + self.z[i] < self.len and self.s[self.z[i]] == self.s[i + self.z[i]]:
                self.z[i] += 1
            
            if i + self.z[i] > r:
                l = i
                r = i + self.z[i]
    
    def show_res(self) -> None:
        s_show = " ".join(self.s)
        z_show = " ".join(map(str, self.z))
        
        print(f"string: {s_show}")
        print(f"z_func: {z_show}")