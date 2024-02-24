#include "Dijkstra.hpp"
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
	Dijkstra dij(graph);
	int src = 0, dst = 4;
	//input src and dst
	int shortest_path = dij.find_shortest_path(src, dst);

	cout << "The shortest path from " << src << " to " << dst;
	cout << " is " << shortest_path << endl;

	return 0;
}
