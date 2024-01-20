#include "union_find.hpp"
#include <bits/stdc++.h>

using namespace std;

void print_res(bool res, int n, int m)
{
	if(res)
		cout << "node" << n << " and node" << m << " is connected!" << endl;
	else
		cout << "node" << n << " and node" << m << " isn't connected!" << endl;
}

int main()
{
	vector<vector<int>> graph = {{0, 1}, {0, 5}, {1, 2},
				     {1, 6}, {2, 7}, {3, 4},
				     {3, 8}, {4, 9}, {5, 6}};
	int n = 10;

	//quick_find q(n);
	//quick_union q(n);
	//weighted_quick_union q(n);
	//quick_union_path_compression q(n);
	weighted_quick_union_path_compression q(n);
	for(auto g : graph)
		q.union_set(g[0], g[1]);

	cout << "Is node0 and node7 connected?" << endl;
	print_res(q.is_connected(0, 7), 0, 7);
	cout << "Is node8 and node9 connected?" << endl;
	print_res(q.is_connected(8, 9), 8, 9);
	cout << "Is node2 and node9 connected?" << endl;
	print_res(q.is_connected(2, 9), 2, 9);

	return 0;
}
