#include "Bellman_Ford.hpp"
#include <bits/stdc++.h>

using namespace std;

int main()
{
	//graph[i] means start from i
	//pair<i, j> means end to i and coast j
	vector<vector<pair<int, int>>> graph = {{{1, 4}, {2, 2}},
						{{0, 4}, {4, 3}},
						{{0, 2}, {3, 2}, {5, 4}},
						{{2, 2}, {4, 3}, {5, 1}},
						{{1, 3}, {3, 3}, {5, 1}},
						{{2, 4}, {3, 1}, {4, 1}}};
	bellman_ford bf(graph);
	int src = 0, dst = 4;
	//input src and dst
	int shortest_path = bf.find_shortest(src, dst);

	if(shortest_path == INT_MAX)
	{
		cout << "There is no path from " << src << " to " << "dst" << endl;
		return 0;
	}
	else if(shortest_path == -1)
	{
		cout << "There is negative cycle" << endl;
		return 0;
	}
	else
	{
		cout << "The shortest path from " << src << " to " << dst;
		cout << " is " << shortest_path << endl;

		return 0;
	}
}
