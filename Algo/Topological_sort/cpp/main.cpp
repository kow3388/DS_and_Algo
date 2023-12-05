#include "Topological.hpp"
#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector<vector<int>> graph = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};

	topological_sort t(graph);

	t.print_res();

	return 0;
}
