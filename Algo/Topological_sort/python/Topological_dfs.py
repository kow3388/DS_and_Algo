class topological_sort_dfs:
    def __init__(self, graph: list[list[int]]):
        self.graph = graph
        self.target = []
        self.visited = [False]*len(self.graph)
        self.stk = []
    
    def _sort(self, point: int):
        if not self.visited[point]:
            self.visited[point] = True
            for p in self.graph[point]:
                if not self.visited[p]:
                    self._sort(p)
                    
        self.stk.append(point)
    
    def print_res(self):
        for i in range(len(self.graph)):
            if not self.visited[i]:
                self._sort(i)
        
        for i in reversed(self.stk):
            self.target.append(i)

        print(self.target)
