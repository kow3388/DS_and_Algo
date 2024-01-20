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
