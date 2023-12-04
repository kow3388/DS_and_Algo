#include <bits/stdc++.h>

using namespace std;

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
