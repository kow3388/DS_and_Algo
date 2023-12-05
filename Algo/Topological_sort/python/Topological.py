class topological_sort:
    def __init__(self, graph: list[list[int]]):
        self.graph = graph
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
            print(i, end = ' ')
        print()
