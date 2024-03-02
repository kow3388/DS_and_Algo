#include <bits/stdc++.h>

using namespace std;

class bellman_ford
{
	private:
		int n;
		bool neg_cycle;
		vector<vector<pair<int, int>>> graph;
		vector<vector<int>> dist;
		vector<bool> calculated;
	public:
		bellman_ford(vector<vector<pair<int, int>>> &g)
		{
			graph = g;
			n = g.size();
			neg_cycle = false;
			dist.resize(n, vector<int>(n, INT_MAX));
			for(int i = 0; i < n; i++)
				dist[i][i] = 0;

			calculated.resize(n, false);
		}

		int find_shortest(int src, int dst)
		{
			if(neg_cycle)
			{
				cout << "There is negative cycle!" << endl;
				return -1;
			}

			if(calculated[src])
				return dist[src][dst];

			calculated[src] = true;

			//do n-1 times
			for(int i = 1; i < n; i++)
			{
				for(int j = 0; j < n; j++)
				{
					for(pair<int, int> g : graph[j])
					{
						int v = g.first;
						int w = g.second;
						if(dist[src][v] > dist[src][j] + w && dist[src][j] != INT_MAX)
							dist[src][v] = dist[src][j] + w;
					}
				}
			}

			for(int i = 0; i < n; i++)
			{
				for(pair<int, int> g : graph[i])
				{
					int v = g.first;
					int w = g.second;
					if(dist[src][v] > dist[src][i] + w && dist[src][i] != INT_MAX)
					{
						cout << "There is negative cycle!" << endl;
						neg_cycle = true;
						return -1;
					}
				}
			}

			return dist[src][dst];
		}
};
