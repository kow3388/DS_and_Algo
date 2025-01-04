# Moore Voting Algorithm

用於找出數組中存在majority element的演算法，其想法類似於投票，數組中數量最多的數在投票完的結果後會勝出

## Algorithm
1. Initialize two variable:
   candidate = arbitrary value (means the majority element candidate)
   count = 0 (means vote)
2. Traversal al array there are 3 case:

    case 1. if count == 0:
       candidate = current num[i] (the current most element)
       count += 1 (get one ballot)
       
    case 2. if candidate == nums[i]:
       count += 1 (get one more ballot)
       
    case 3. else:
       count -= 1 (remove one ballot)

The most vote will be the majority element

## Example
Given an array = [2, 2, 1, 1, 1, 2, 2]
Find the majority element

1. Initialize: candidate = 0, count = 0
2. [***2***, 2, 1, 1, 1, 2, 2]
   count == 0:
   candidate = 2, count = 1
3. [2, ***2***, 1, 1, 1, 2, 2]
   count == 1:
   candidate = 2, count = 2
4. [2, 2, ***1***, 1, 1, 2, 2]
   count == 2:
   candidate = 2, count = 1
5. [2, 2, 1, ***1***, 1, 2, 2]
   count == 1:
   candidate = 2, count = 0
6. [2, 2, 1, 1, ***1***, 2, 2]
   count == 0:
   candidate = 1, count = 1
7. [2, 2, 1, 1, 1, ***2***, 2]
   count == 1:
   candidate = 1, count = 0
8. [2, 2, 1, 1, 1, 2, ***2***]
   count == 0:
   candidate = 2, count = 1

## Implement
### C++
```cpp
# include <bits/stdc++.h>

using namespace std;

class voting
{
	public:
		int candidate, count;
		voting()
		{
			candidate = 0;
			count = 0;
		}

		int vote_algo(vector<int> &nums)
		{
			const int n = nums.size();

			for(int i = 0; i < n; i++)
			{
				if(count == 0)
				{
					candidate = nums[i];
					count++;
				}
				else if(candidate == nums[i])
					count++;
				else
					count--;
			}

			return candidate;
		}
};
```

### Python
```python
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
```