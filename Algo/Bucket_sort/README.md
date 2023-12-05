# Bucket Sort
- 又稱**bin sort**
- **穩定排序** : 排序後相同key值的元素相對位置不改變
  EX: [5, 3, 3*, 1] => [1, 3, 3*, 5]
- **分配式排序** : 分析key value來排序而非兩兩比較

|         | Time Complexity  |
|:-------:|:----------------:|
|  Worst  |  ***O($n^2$)***  |
|  Best   | ***O($n + k$)*** |
| Average | ***O($n + k$)*** |

- **Space Complexity** : ***O($n + k$)***

## Step
1. **Create buckets** : 建立k個buckets，期望所有key值被平均分散在各個buckets
2. **Scatter** : 將elements按照value放入對應的bucket
3. **Inner sort** : sort所有non-empty bucket
4. **Gather** : 將bucket內的elements放回array

## Example
Given a array **[11, 51, 11, 32, 7, 68, 93, 44, 87, 78]** using bucket sort to sort array as ascending order

1. Create k buckets (we use k = 10 in this case)
   So we separated [7 to 93] into k(10) groups : 
   [7 to 15], [16 to 24], ..., [85 to 93]

| b0   | b1   | b2   | b3  | b4  | b5  | b6  | b7  | b8  | b9  |
| ---- | ---- | ---- | --- | --- | --- | --- | --- | --- | --- |
|      |      |      |     |     |     |     |     |     |     |

2. Scatter all elements into buckets

| b0   | b1   | b2   | b3  | b4  | b5  | b6  | b7  | b8  | b9  |
| ---- | ---- | ---- | --- | --- | --- | --- | --- | --- | --- |
| 7    |      | 32   |     | 44  | 51  |     | 68  | 78  | 87  |
| 11   |      |      |     |     |     |     |     |     | 93  |
| 11   |      |      |     |     |     |     |     |     |     |

3. Sort each buckets (no matter use which sort method)

| b0   | b1   | b2   | b3  | b4  | b5  | b6  | b7  | b8  | b9  |
| ---- | ---- | ---- | --- | --- | --- | --- | --- | --- | --- |
| 11   |      | 32   |     | 44  | 51  |     | 68  | 78  | 93  |
| 11   |      |      |     |     |     |     |     |     | 87  |
| 7    |      |      |     |     |     |     |     |     |     |

4. Return each element in array
   **[7, 11, 11, 32, 44, 51, 68, 78, 87, 93]**

## Implement
### C++
```cpp=
class Bucket_sort
{
    public:
        vector<vector<int>> bucket;
        
        void Sort(vector<int> &nums)
        {
            int n = nums.size();
            int min_val = *min_element(nums.begin(), nums.end());
            int max_val = *max_element(nums.begin(), nums.end());
            bucket.resize(n);
            
            for(int num : nums)
            {
                //compute bucket index for num and make sure max val will be in last bucket
                int idx = (num == max_val) ? n-1 : (num - min_val)*n/(max_val - min_val);
                bucket[idx].emplace_back(num);
            }
            
            for(int i =0 ; i < n; i++)
                //you can use wathever sort you like
                sort(bucket[i].begin(), bucket[i].end());
            
            //return value to nums's index
            int index = 0;
            for(int i = 0; i < n; i++)
                for(int j = 0; j < bucket[i].size(); j++)
                {
                    cout << bucket[i][j] << endl;
                    nums[index++] = bucket[i][j];
                }
        }
};
```

### python
```python=
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
    
    return nums
```

## Extend problem
leetcode 164 : Maximum Gap
[https://leetcode.com/problems/maximum-gap](https://leetcode.com/problems/maximum-gap)

###### tags : `Sort`
