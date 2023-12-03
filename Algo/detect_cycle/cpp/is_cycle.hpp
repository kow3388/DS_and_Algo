#include <bits/stdc++.h>

using namespace std;

class check_cycle
{
	public:
		vector<vector<int>> graph;
		vector<bool> visited;
		vector<bool> todo;
		
		check_cycle(vector<vector<int>> g)
		{
			graph = g;
			visited.resize(g.size(), false);
			todo.resize(g.size(), false);
		}

		bool _iscycle(int point)
		{
			if(!visited[point])
			{
				visited[point] = true;
				todo[point] = true;

				for(int p : graph[point])
					if(!visited[p] && _iscycle(p))
						return true;
					else if(todo[p])
						return true;
			}

			todo[point] = false;

			return false;
		}

		bool iscycle()
		{
			const int n = graph.size();
			
			for(int i = 0; i < n; i++)
				if(!visited[i] && _iscycle(i))
					return true;

			return false;
		}
};
