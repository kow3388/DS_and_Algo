#include <bits/stdc++.h>
#include "tree_diameter.hpp"

using namespace std;

int main()
{
    vector<vector<int>> graph = {
        {1, 2, 3},
        {0},
        {0, 4, 5, 7},
        {0, 6},
        {2},
        {2},
        {3},
        {2}
    };

    TreeDiameter t;
    cout << "The diameter of graph is " << t.getDiameter(graph) << endl;

    return 0;
}