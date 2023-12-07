#include "Topological_dfs.hpp"
#include "Topological_kahn.hpp"
#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector<vector<int>> graph = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};

	topological_sort_dfs t_dfs(graph);
	topological_sort_kahn t_bfs(graph);

	cout << "Using dfs res: " << endl;
	t_dfs.print_res();
	cout << "Using Kahn(bfs) res: " << endl;
	t_bfs.print_res();

	return 0;
}
