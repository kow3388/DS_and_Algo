#include <bits/stdc++.h>
#include "Bipartite.hpp"

using namespace std;

void printResult(string name, bool res)
{
    if(res)
        cout << name << " is bipartite graph!" << endl;
    else
        cout << name << " isn't bipartite graph!" << endl;
}

int main()
{
    vector<vector<int>> graph1 = {
        {1, 3, 4},
        {0, 2, 5},
        {1},
        {0, 5},
        {0},
        {1, 3}
    };
    vector<vector<int>> graph2 = {
        {1, 3, 4},
        {0, 2, 3, 5},
        {1},
        {0, 1, 5},
        {0},
        {1, 3}
    };

    BipartiteDFS bipartiteDFS;
    cout << "Method DFS: " << endl;
    printResult("Graph1", bipartiteDFS.checkBipartite(graph1));
    printResult("Graph2", bipartiteDFS.checkBipartite(graph2));

    cout << "=============================================" << endl;

    BipartiteBFS bipartiteBFS;
    cout << "Method BFS: " << endl;
    printResult("Graph1", bipartiteBFS.checkBipartite(graph1));
    printResult("Graph2", bipartiteBFS.checkBipartite(graph2));

    return 0;
}