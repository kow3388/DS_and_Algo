#include <bits/stdc++.h>

using namespace std;

class topological_sort
{
    public:
        vector<vector<int>> graph;
        vector<bool> visited;
        stack<int> stk;

        topological_sort(vector<vector<int>> g)
        {
            graph = g;
            visited.resize(g.size(), false);
        }

        void _sort(int point)
        {
            if(!visited[point])
            {
                visited[point] = true;

                for(int p : graph[point])
                    if(!visited[p])
                        _sort(p);
            }

            stk.push(point);
        }

        void print_res()
        {
            for(int i = 0; i < graph.size(); i++)
                if(!visited[i])
                    _sort(i);

            while(!stk.empty())
            {
                cout << stk.top() << " ";
                stk.pop();
            }
            cout << endl;
        }
};
