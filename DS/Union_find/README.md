# Union-find
Union-find(並查集，又稱不相交集)
在initial時會有一堆樹，且每一棵樹只有一個node，透過這些node尋找哪些樹具有共通的root
此data structure具有兩個動作
1. Find : 判斷是否在同一個集合中
2. Union : 合併不同集合

經常用於判斷graph是否連通

## Example
有一個graph(如下圖)，其edge為
[[0, 1], [0, 5], [1, 2], [1, 6], [2, 7], [3, 4], [3, 8], [4, 9]. [5, 6]]
![graph](https://hackmd.io/_uploads/HyZEssMK6.jpg)

1. node 0和node 7是否connected?
2. node 8和node 9是否connected?
3. node 2和node 9是否connected?

Step:
1. initial vector
   [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
2. union [0, 1]
   [0, 0, 2, 3, 4, 5, 6, 7, 8, 9]
3. union [0, 5]
   [0, 0, 2, 3, 4, 0, 6, 7, 8, 9]
4. union [1, 2]
   [0, 0, 0, 3, 4, 0, 6, 7, 8, 9]
5. union [1, 6]
   [0, 0, 0, 3, 4, 0, 0, 7, 8, 9]
6. union [2, 7]
   [0, 0, 0, 3, 4, 0, 0, 0, 8, 9]
7. union [3, 4]
   [0, 0, 0, 3, 3, 0, 0, 0, 8, 9]
8. union [3, 8]
   [0, 0, 0, 3, 3, 0, 0, 0, 3, 9]
9. union [4, 9]
   [0, 0, 0, 3, 3, 0, 0, 0, 3, 3]

Question:
1. node 0和node 7是否connected?
   find(0, 7), node 0 root => 0, node 7 root => 0, yes
2. node 8和node 9是否connected?
   find(8, 9), node 8 root => 3, node 9 root => 3, yes
3. node 2和node 9是否connected?
   find(2, 9), node 2 root => 0, node 9 root => 3, no

## Different Union-find type
### Quick find
Quick find就是讓同一個集合中的所有值皆為root值，因此find就可以達到time complexity O(1)
但為了讓集合中的每一個值皆相同，因此在union時要把愈合併的set裡的每一個elements皆改為root，time complexity O(n)

example:
set1 = [1, 1, 1, 1], set2 = [2, 2, 2, 2, 2]
合併為[1, 1, 1, 1, 1, 1, 1, 1, 1] or [2, 2, 2, 2, 2, 2, 2, 2, 2]
union比須把每一個set全部改變，但find很快

### Quick union
和quick find相反，在union時直接將其值設為另外一個值，time complexity O(1)
但find就必須一直traversal直到找到target，time complexity O(n)

example:
[0, 1, 9, 4, 9, 6, 6, 7, 8, 9]
find(2, 3)
node 2 root => 2 -> 9 -> 9, root = 9
node 3 root => 3 -> 4 -> 9 -> 9, root 9
find(2, 3) = true

union(1, 3) node 1 = 3
[0, 3, 9, 4, 9, 6, 6, 7, 8, 9]

### Weighted quick union
上一個方法是在union時是固定將左邊union到右邊 or 固定將右邊union到左邊
此方法差別是會去判斷左set和右set哪邊大，將小的union到大的那邊

### Quick union with path compression
此方法即quick union在traversal時將traversal的node全部改成root value

example:
[0, 1, 9, 4, 9, 6, 6, 7, 8, 9]
find(2, 3)
node 2 root => 2 -> 9 -> 9, root = 9
node 3 root => 3 -> 4 -> 9 -> 9, root 9
find(2, 3) = true

after find change node 3 to value 9
[0, 1, 9, 9, 9, 6, 6, 7, 8, 9]

## Implement
### C++

```cpp=
#include <bits/stdc++.h>

using namespace std;

class quick_find
{
	private:
		vector<int> parent;

	public:
		quick_find(int n)
		{
			parent.resize(n);
			for(int i = 0; i < n; i++)
				parent[i] = i;
		}

		int find_root(int node)
		{
			return parent[node];
		}

		void union_set(int node1, int node2)
		{
			cout << node1 << " and " << node2 << " have been union!" << endl;
			int root1 = find_root(node1);
			int root2 = find_root(node2);

			if(root1 != root2)
				for(int i = 0; i < parent.size(); i++)
					if(parent[i] == root1)
						parent[i] = root2;
		}

		bool is_connected(int node1, int node2)
		{
			return find_root(node1) == find_root(node2);
		}
};

class quick_union
{
	private:
		vector<int> parent;

	public:
		quick_union(int n)
		{
			parent.resize(n);
			for(int i = 0; i < n; i++)
				parent[i] = i;
		}

		int find_root(int node)
		{
			if(node == parent[node])
				return node;
			return find_root(parent[node]);
		}

		void union_set(int node1, int node2)
		{
			cout << node1 << " and " << node2 << " have been union!" << endl;
			int root1 = find_root(node1);
			int root2 = find_root(node2);

			parent[root1] = root2;
		}

		bool is_connected(int node1, int node2)
		{
			return find_root(node1) == find_root(node2);
		}
};

class weighted_quick_union
{
	private:
		vector<int> parent;
		vector<int> Size;

	public:
		weighted_quick_union(int n)
		{
			parent.resize(n);
			Size.resize(n, 1);
			for(int i = 0; i < n; i++)
				parent[i] = i;
		}

		int find_root(int node)
		{
			if(node == parent[node])
				return node;
			return find_root(parent[node]);
		}

		void union_set(int node1, int node2)
		{
			cout << node1 << " and " << node2 << " have been union!" << endl;
			int root1 = find_root(node1);
			int root2 = find_root(node2);

			if(root1 != root2)
				if(Size[root1] > Size[root2])
				{
					parent[root2] = root1;
					Size[root1] += Size[root2];
				}
				else
				{
					parent[root1] = root2;
					Size[root2] += Size[root1];
				}
		}

		bool is_connected(int node1, int node2)
		{
			return find_root(node1) == find_root(node2);
		}
};

class quick_union_path_compression
{
	private:
		vector<int> parent;

	public:
		quick_union_path_compression(int n)
		{
			parent.resize(n);
			for(int i = 0; i < n; i++)
				parent[i] = i;
		}

		int find_root(int node)
		{
			if(node != parent[node])
				parent[node] = find_root(parent[node]);
			return parent[node];
		}

		void union_set(int node1, int node2)
		{
			cout << node1 << " and " << node2 << " have been union!" << endl;
			int root1 = find_root(node1);
			int root2 = find_root(node2);

			parent[root1] = root2;
		}

		bool is_connected(int node1, int node2)
		{
			return find_root(node1) == find_root(node2);
		}
};

class weighted_quick_union_path_compression
{
	private:
		vector<int> parent;
		vector<int> Size;

	public:
		weighted_quick_union_path_compression(int n)
		{
			parent.resize(n);
			Size.resize(n, 1);
			for(int i = 0; i < n; i++)
				parent[i] = i;
		}

		int find_root(int node)
		{
			if(node != parent[node])
				parent[node] = find_root(parent[node]);
			return parent[node];
		}

		void union_set(int node1, int node2)
		{
			cout << node1 << " and " << node2 << " have been union!" << endl;
			int root1 = find_root(node1);
			int root2 = find_root(node2);

			if(root1 != root2)
				if(Size[root1] > Size[root2])
				{
					parent[root2] = root1;
					Size[root1] += Size[root2];
				}
				else
				{
					parent[root1] = root2;
					Size[root2] += Size[root1];
				}
		}

		bool is_connected(int node1, int node2)
		{
			return find_root(node1) == find_root(node2);
		}
};
```

### Python
```python=
class quick_find:
    def __init__(self, n: int):
        self.parent = [i for i in range(n)]

    def find_root(self, node: int) -> int:
        return self.parent[node]

    def union_set(self, node1: int, node2: int) -> None:
        root1 = self.find_root(node1)
        root2 = self.find_root(node2)

        if root1 != root2:
            for i in range(len(self.parent)):
                if self.parent[i] == root1:
                    self.parent[i] = root2
            
            print("{} and {} have been union!".format(node1, node2))
        else:
            print("{} and {} already be union!".format(node1, node2))

    def is_connected(self, node1: int, node2: int) -> bool:
        return self.find_root(node1) == self.find_root(node2)

class quick_union:
    def __init__(self, n: int):
        self.parent = [i for i in range(n)]

    def find_root(self, node: int) -> int:
        if node != self.parent[node]:
            return self.find_root(self.parent[node])
        return node

    def union_set(self, node1: int, node2: int) -> None:
        root1 = self.find_root(node1)
        root2 = self.find_root(node2)

        if root1 != root2:
            self.parent[root1] = root2
            print("{} and {} have been union!".format(node1, node2))
        else:
            print("{} and {} already be union!".format(node1, node2))

    def is_connected(self, node1: int, node2: int) -> bool:
        return self.find_root(node1) == self.find_root(node2)

class weighted_quick_union:
    def __init__(self, n: int):
        self.parent = [i for i in range(n)]
        self.size = [1 for i in range(n)]

    def find_root(self, node: int) -> int:
        if node != self.parent[node]:
            return self.find_root(self.parent[node])
        return node

    def union_set(self, node1: int, node2: int) -> None:
        root1 = self.find_root(node1)
        root2 = self.find_root(node2)

        if root1 != root2:
            if self.size[root1] > self.size[root2]:
                self.parent[root2] = root1
                self.size[root1] += self.size[root2]
            else:
                self.parent[root1] = root2
                self.size[root2] += self.size[root1]
            print("{} and {} have been union!".format(node1, node2))
        else:
            print("{} and {} already be union!".format(node1, node2))

    def is_connected(self, node1: int, node2: int) -> bool:
        return self.find_root(node1) == self.find_root(node2)

class quick_union_path_compression:
    def __init__(self, n: int):
        self.parent = [i for i in range(n)]

    def find_root(self, node: int) -> int:
        if node != self.parent[node]:
            self.parent[node] = self.find_root(self.parent[node])

        return self.parent[node]

    def union_set(self, node1: int, node2: int) -> None:
        root1 = self.find_root(node1)
        root2 = self.find_root(node2)

        if root1 != root2:
            self.parent[root1] = root2
            print("{} and {} have been union!".format(node1, node2))
        else:
            print("{} and {} already be union!".format(node1, node2))

    def is_connected(self, node1: int, node2: int) -> bool:
        return self.find_root(node1) == self.find_root(node2)

class weighted_quick_union_path_compression:
    def __init__(self, n: int):
        self.parent = [i for i in range(n)]
        self.size = [1 for i in range(n)]

    def find_root(self, node: int) -> int:
        if node != self.parent[node]:
            self.parent[node] = self.find_root(self.parent[node])
        return self.parent[node]

    def union_set(self, node1: int, node2: int) -> None:
        root1 = self.find_root(node1)
        root2 = self.find_root(node2)

        if root1 != root2:
            if self.size[root1] > self.size[root2]:
                self.parent[root2] = root1
                self.size[root1] += self.size[root2]
            else:
                self.parent[root1] = root2
                self.size[root2] += self.size[root1]
            print("{} and {} have been union!".format(node1, node2))
        else:
            print("{} and {} already be union!".format(node1, node2))

    def is_connected(self, node1: int, node2: int) -> bool:
        return self.find_root(node1) == self.find_root(node2)
```

###### `Union-find`