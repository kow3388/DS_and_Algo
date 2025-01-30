#include <bits/stdc++.h>

using namespace std;

class BipartiteDFS{
    public:
        bool checkBipartite(vector<vector<int>> &graph){
            const int n = graph.size();
            vector<int> color(n, -1);

            for(int i = 0; i < n; i++)
            {
                if(color[i] == -1)
                {
                    if(!dfs(graph, color, i, 1))
                        return false;
                }
            }

            return true;
        }
    
    private:
        bool dfs(vector<vector<int>> &graph, vector<int> &color, int node, int curColor = 1){
            if(color[node] != -1 && color[node] != curColor)
                return false;
            else if(color[node] != -1 && color[node] == curColor)
                return true;
            
            color[node] = curColor;
            for(int nextNode : graph[node])
                if(!dfs(graph, color, nextNode, 1 - curColor))
                    return false;
            
            return true;
        }
};

class BipartiteBFS{
    public:
        bool checkBipartite(vector<vector<int>> &graph)
        {
            const int n = graph.size();
            vector<int> color(n, -1);

            for(int i = 0; i < n; i++)
            {
                if(color[i] == -1)
                {
                    if(!bfs(graph, color, i))
                        return false;
                }
            }

            return true;
        }

    private:
        bool bfs(vector<vector<int>> &graph, vector<int> &color, int node)
        {
            queue<int> q;

            int curColor = 1;
            q.push(node);
            color[node] = curColor;

            while(!q.empty())
            {
                int s = q.size();

                for(int i = 0; i < s; i++)
                {
                    int cur = q.front();
                    q.pop();

                    for(int nextNode : graph[cur])
                    {
                        if(color[nextNode] == -1)
                        {
                            color[nextNode] = 1 - curColor;
                            q.push(nextNode);
                        }
                        else
                        {
                            if(color[nextNode] == curColor)
                                return false;
                        }
                    }
                }

                curColor = 1 - curColor;
            }

            return true;
        }
};