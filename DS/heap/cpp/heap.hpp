#include <bits/stdc++.h>

using namespace std;

class heap
{
	public:
		vector<int> h;
		heap(vector<int> arr)
		{
			heapify(arr);
		}

		void heapify(vector<int> arr)
		{
			for(int i = 0; i < arr.size(); i++)
			{
				int new_idx = i;
				int parent_idx = (i+1)/2 - 1;
				h.emplace_back(arr[i]);
				while(parent_idx >= 0)
				{
					if(h[new_idx] > h[parent_idx])
					{
						swap(h[new_idx], h[parent_idx]);
						new_idx = parent_idx;
						parent_idx = (new_idx+1)/2 - 1;
					}
					else
						break;
				}
			}
		}

		void push(int v)
		{
			h.emplace_back(v);
			int new_idx = h.size() - 1;
			int parent_idx = (new_idx+1)/2 - 1;

			while(parent_idx >= 0)
			{
				if(h[new_idx] > h[parent_idx])
				{
					swap(h[new_idx], h[parent_idx]);
					new_idx = parent_idx;
					parent_idx = (new_idx+1)/2 - 1;
				}
				else
					break;
			}

			cout << v << " has been inserted in heap!" << endl;
		}

		int pop()
		{
			if(h.size() == 0)
			{
				cout << "There is no element in heap!" << endl;
				return INT_MIN;
			}

			swap(h.front(), h.back());
			int v = h.back();
			h.pop_back();

			int i = 0;
			int idx = -1;

			while(i < h.size())
			{
				int child_idx1 = 2*i + 1;
				int child_idx2 = 2*i + 2;

				if(child_idx1 >= h.size())
					break;
				else if(child_idx2 >= h.size())
					idx = child_idx1;
				else
					idx = (h[child_idx1] > h[child_idx2])?child_idx1:child_idx2;

				if(h[i] < h[idx])
				{
					swap(h[i], h[idx]);
					i = idx;
				}
				else
					break;
			}

			return v;
		}

		void heap_sort()
		{
			while(h.size() != 0)
			{
				int tmp = this->pop();
				cout << tmp << " ";
			}

			cout << endl;
			cout << "Heap has been empty!" << endl;
		}

};
