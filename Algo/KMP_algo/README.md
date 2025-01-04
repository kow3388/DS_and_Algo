# KMP algo

KMP是想出這套演算法的三位教授名字的字首縮寫，無特別含意

- 用於string matching
- 一般在進行string matching如果比對失敗，就向右1格繼續比對
  EX: soruce = 'abcababaa', target = 'ababaa'  
  
      step 1:
        abcababaa
        ababaa
        oox
      step 2:
        abcababaa
         ababaa
- 但實際上'ab'我們已經比對過了，因此我們可以再多往右2格  

      step 1:
        abcababaa
        ababaa
        oox
      step 2:
        abcababaa
           ababaa
- LPS(Longest Prefix Suffix) 最長的相等前後綴，也有人稱為Prefix function
  abab不論是從前看還是從後看都有相同substring 'ab'
  EX:  
  
      ababaa
      001231
- 由於先計算LPS將結果存起來，因此可視為dp的一種

## Implement
### C++
```cpp
class KMP
{
	public:
		bool search(string s, string t)
		{
			int n = s.length();
			int m = t.length();

			vector<int> lps = LPS(t, m);

			//index for s and t
			int i = 0, j = 0;
			while((n-i) >= (m-j))
			{
				if(s[i] == t[j])
				{
					i++;
					j++;
				}


				if(j == m)
					return true;

				else if(i < n && s[i] != t[j])
				{
					if(j != 0)
					{
						j = lps[j-1];
						cout << "target string index start from " << j << endl;
					}
					else
						i++;
				}
			}
			
			return true;
		}

		//logest prefix suffix
		vector<int> LPS(string t, int m)
		{
			vector<int> lps(m, 0);
			//length of the previous lps
			int len = 0;
			int i = 1;

			while(i < m)
			{
				if(t[i] == t[len])
				{
					len++;
					lps[i] = len;
					i++;
				}
				else
				{
					if(len != 0)
						len = lps[len-1];
					else
					{
						lps[i] = 0;
						i++;
					}
				}
			}

			return lps;
		}
};
```

### Python
```python
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
```

###### `DP`