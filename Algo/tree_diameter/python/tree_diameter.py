import queue

class TreeDiameter:
    def getDiameter(self, graph: list[list[int]]) -> int:
        node, _ = self._bfs(graph, 0)
        _, diameter = self._bfs(graph, node)

        return diameter
    
    def _bfs(self, graph: list[list[int]], node: int) -> tuple[int, int]:
        n = len(graph)
        visited = [False for i in range(n)]
        q = queue.Queue()
        farest, dist = 0, 0

        q.put(node)
        visited[node] = True

        while not q.empty():
            s = q.qsize()

            for i in range(s):
                cur = q.get()

                for nextNode in graph[cur]:
                    if visited[nextNode]:
                        continue

                    visited[nextNode] = True
                    q.put(nextNode)
                
                farest = cur
            
            dist += 1
        
        return farest, dist - 1