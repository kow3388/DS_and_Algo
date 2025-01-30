#include <bits/stdc++.h>

using namespace std;

class TreeDiameter{
    public:
        int getDiameter(vector<vector<int>> &graph)
        {
            //node y and length from 0
            auto [node, dist] = bfs(graph, 0);
            auto [tmp, diameter] = bfs(graph, node);

            return diameter;
        }
    
    private:
        pair<int, int> bfs(vector<vector<int>> &graph, int node)
        {
            const int n = graph.size();
            vector<bool> visited(n, false);
            queue<int> q;
            int farest = 0, dist = 0;

            q.push(node);
            visited[node] = true;

            while(!q.empty())
            {
                int s = q.size();

                for(int i = 0; i < s; i++)
                {
                    int cur = q.front();
                    q.pop();

                    for(int nextNode : graph[cur])
                    {
                        if(visited[nextNode])
                            continue;
                        
                        q.push(nextNode);
                        visited[nextNode] = true;
                    }

                    farest = cur;
                }

                dist++;
            }

            return {farest, dist - 1};
        }
};