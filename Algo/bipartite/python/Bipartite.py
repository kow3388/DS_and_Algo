import queue

class BipartiteDFS:
    def checkBipartite(self, graph: list[list[int]]) -> bool:
        n = len(graph)
        color = [-1 for i in range(n)]

        for i in range(n):
            if color[i] == -1:
                if not self._dfs(graph, color, i, 1):
                    return False
        
        return True
    
    def _dfs(self,
             graph: list[list[int]],
             color: list[int],
             node: int,
             curColor: int) -> bool:
        
        if color[node] != -1 and color[node] != curColor:
            return False
        elif color[node] != -1 and color[node] == curColor:
            return True
        
        color[node] = curColor
        for nextNode in graph[node]:
            if not self._dfs(graph, color, nextNode, 1 - curColor):
                return False
        
        return True

class BipartiteBFS:
    def checkBipartite(self, graph: list[list[int]]) -> bool:
        n = len(graph)
        color = [-1 for i in range(n)]

        for i in range(n):
            if color[i] == -1:
                if not self._bfs(graph, color, i):
                    return False
        
        return True
    
    def _bfs(self,
             graph: list[list[int]],
             color: list[int],
             node: int) -> bool:
        
        q = queue.Queue()

        curColor = 1
        q.put(node)
        color[node] = curColor

        while not q.empty():
            s = q.qsize()

            for i in range(s):
                cur = q.get()

                for nextNode in graph[cur]:
                    if color[nextNode] == -1:
                        color[nextNode] = 1 - curColor
                        q.put(nextNode)
                    else:
                        if color[nextNode] == curColor:
                            return False
                
            curColor = 1 - curColor
        
        return True