class KMP:
    def search(self, s: str, t: str) -> bool:
        n, m = len(s), len(t)
        lps = self.LPS(t, m)

        #index of s and t
        i, j = 0, 0
        while (n-i) >= (m-j):
            if s[i] == t[j]:
                i += 1
                j += 1

            if j == m:
                return True
            elif i < n and s[i] != t[j]:
                if j != 0:
                    print("target string index start from", lps[j-1])
                    j = lps[j-1]
                else:
                    i += 1

    def LPS(self, t: str, m: int) -> list[int]:
        lps = [0]*m
        #length of the previous lps
        l = 0
        i = 1

        while i < m:
            if t[i] == t[l]:
                l += 1
                lps[i] = l
                i += 1
            else:
                if l != 0:
                    l = lps[l-1]
                else:
                    lps[i] = 0
                    i += 1

        return lps
