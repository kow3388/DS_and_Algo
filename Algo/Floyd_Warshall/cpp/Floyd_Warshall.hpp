#include <bits/stdc++.h>

using namespace std;

class floyd_warshall
{
	private:
		vector<vector<int>> dist;
		int n;
	public:
		floyd_warshall(vector<vector<pair<int, int>>> &g)
		{
			n = g.size();
			dist.resize(n, vector<int>(n, INT_MAX));
			for(int i = 0; i < n; i++)
			{
				dist[i][i] = 0;
				for(pair<int, int> edge : g[i])
					dist[i][edge.first] = edge.second;
			}
		}

		void calculate_shortest()
		{
			for(int k = 0; k < n; k++)
				for(int i = 0; i < n; i++)
					for(int j = 0; j < n; j++)
						if(dist[i][j] > (dist[i][k] + dist[k][j]) && dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
							dist[i][j] = dist[i][k] + dist[k][j];
		}

		int shortest(int src, int dst)
		{
			return dist[src][dst];
		}
};
