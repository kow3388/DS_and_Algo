#include <bits/stdc++.h>

using namespace std;

class topological_sort_kahn
{
	public:
		vector<vector<int>> graph;
		vector<int> degree;
		vector<int> target;
		queue<int> q;

		topological_sort_kahn(vector<vector<int>> g)
		{
			graph = g;

			degree.resize(g.size(), 0);
			for(int i = 0; i < graph.size(); i++)
				for(int n : graph[i])
					degree[n]++;

			for(int i = 0; i < degree.size(); i++)
				if(degree[i] == 0)
					q.push(i);
		}

		void print_res()
		{
			while(!q.empty())
			{
				int node = q.front();
				q.pop();
				target.emplace_back(node);

				for(int i : graph[node])
				{
					degree[i]--;
					if(degree[i] == 0)
						q.push(i);
				}
			}

			for(int node : target)
				cout << node << " ";
			cout << endl;
		}
};
