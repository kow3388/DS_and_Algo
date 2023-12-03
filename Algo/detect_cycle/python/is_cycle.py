from collections import defaultdict

class check_cycle:
    def __init__(self, graph: list[list[int]]):
        self.graph = graph
        self.visited = defaultdict(bool)
        self.todo = defaultdict(bool)

    def _iscycle(self, point: int) -> bool:
        if not self.visited[point]:
            self.visited[point] = True
            self.todo[point] = True

            for p in self.graph[point]:
                if not self.visited[p] and self._iscycle(p):
                    return True
                elif self.todo[p]:
                    return True

        self.todo[point] = False

        return False

    def iscycle(self) -> bool:
        for i in range(len(self.graph)):
            if not self.visited[i] and self._iscycle(i):
                return True

        return False
