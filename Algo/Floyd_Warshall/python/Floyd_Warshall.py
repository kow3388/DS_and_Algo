class floyd_warshall:
    def __init__(self, graph):
        self.n = len(graph)
        self.dist = [[float("inf") for i in range(self.n)] for j in range(self.n)]

        for i in range(self.n):
            self.dist[i][i] = 0
            for edge in graph[i]:
                self.dist[i][edge[0]] = edge[1]

    def calculate_shortest(self):
        for k in range(self.n):
            for i in range(self.n):
                for j in range(self.n):
                    if self.dist[i][j] > self.dist[i][k] + self.dist[k][j] and self.dist[i][k] != float("inf") and self.dist[k][j] != float("inf"):
                        self.dist[i][j] = self.dist[i][k] + self.dist[k][j]

    def shortest(self, src, dst):
        return self.dist[src][dst]
