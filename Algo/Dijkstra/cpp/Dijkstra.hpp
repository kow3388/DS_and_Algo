#include <bits/stdc++.h>

using namespace std;

class Dijkstra
{
	private:
		int n;
		vector<vector<pair<int, int>>> graph;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
	public:
		Dijkstra(vector<vector<pair<int, int>>> &g)
		{
			graph = g;
			n = g.size();
		}

		int find_shortest_path(int src, int dst)
		{
			vector<int> shortest_path(n, INT_MAX);
			shortest_path[src] = 0;

			min_heap.push({src, 0});
			
			while(!min_heap.empty())
			{
				int curr = min_heap.top().first;
				int dist = min_heap.top().second;
				min_heap.pop();

				if(dist > shortest_path[curr])
					continue;

				shortest_path[curr] = dist;

				for(pair<int, int> g : graph[curr])
				{
					int post = g.first;
					int coast = g.second + dist;

					min_heap.push({post, coast});
				}
			}

			return shortest_path[dst];
		}
};
