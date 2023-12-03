#include "is_cycle.hpp"
#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector<vector<int>> graph = {{1, 2}, {2}, {0, 3}, {}};

	check_cycle check(graph);
	bool cycle = check.iscycle();

	if(cycle)
		cout << "There is cycle in graph." << endl;
	else
		cout << "There is no cycle in graph." << endl;

	return 0;
}
