# Kadane's algo
- 用於找尋maximum subarray value
- 是DP (Dynamic programming) 的一種演算法
- Time complexity : O(n)
- Space complexity : O(1)

## Step
1. 創建兩個variable
   (1) max_ending_here : 用於紀錄以目前數值為subarray結尾的maximum subarray value
       max_ending_here = max(max_ending_here + val, val)
   (2) max_so_far : 用於紀錄目前的maximum subarray value
       max_so_far = max(max_so_far, max_ending_here)
2. 掃過array中的所有值


## Example
Given an array nums = **[−2, 1, −3, 4, −1, 2, 1, −5, 4]**, find the maximum subarray value

1. Initial
   **max_ending_here = -2, max_so_far = -2**  
   [**<font color="#f00">−2</font>**, 1, −3, 4, −1, 2, 1, −5, 4]
   
2. Swing all array
   **max_ending_here = 1, max_so_far = 1**  
   [−2, **<font color="#f00">1</font>**, −3, 4, −1, 2, 1, −5, 4]
   
   **max_ending_here = -2, max_so_far = 1**  
   [−2, 1, **<font color="#f00">−3</font>**, 4, −1, 2, 1, −5, 4]
   
   **max_ending_here = 4, max_so_far = 4**  
   [−2, 1, −3, **<font color="#f00">4</font>**, −1, 2, 1, −5, 4]
   
   **max_ending_here = 3, max_so_far = 4**  
   [−2, 1, −3, 4, **<font color="#f00">−1</font>**, 2, 1, −5, 4]
   
   **max_ending_here = 5, max_so_far = 5**  
   [−2, 1, −3, 4, −1, **<font color="#f00">2</font>**, 1, −5, 4]
   
   **max_ending_here = 6, max_so_far = 6**  
   [−2, 1, −3, 4, −1, 2, **<font color="#f00">1</font>**, −5, 4]
   
   **max_ending_here = 1, max_so_far = 6**  
   [−2, 1, −3, 4, −1, 2, 1, **<font color="#f00">-5</font>**, 4]
   
   **max_ending_here = 5, max_so_far = 6**  
   [−2, 1, −3, 4, −1, 2, 1, -5, **<font color="#f00">4</font>**]
   
3. Return maximum subarray
   **return max_so_far = 6**

## Implement
### C++
```cpp=
template <typename T>
class Kadane
{
    public:
        std::vector<T> nums;
        Kadane(std::vector<T> arr)
        {
            nums.assignt(arr.begin(), arr.end())
        }
    
        T algo()
        {
            if(nums.size() == 1)
                return nums[0];
            
            T max_ending_here = nums[0];
            T max_so_far = nums[0];
            
            for(T num : nums)
            {
                max_ending_here = std::max(num, max_ending_here + num);
                max_so_far = std::max(max_so_far, max_ending_here);
            }
            
            return max_so_far;
        }
}
```

### Python
```python=
class Kadane:
    def algo(self, nums: list[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        
        max_ending_here = nums[0]
        max_so_far = nums[0]
        
        for num in nums[1:]:
            max_ending_here = max(num, max_ending_here + num)
            max_so_far = max(max_so_far, max_ending_here)
        
        return max_so_far
```

## Extend problem
leetcode 152 : Maximum Product Subarray
[https://leetcode.com/problems/maximum-product-subarray](https://leetcode.com/problems/maximum-product-subarray/)

###### tags : `DP`
