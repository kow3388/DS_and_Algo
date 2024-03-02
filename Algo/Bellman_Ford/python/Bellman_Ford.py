class bellman_ford:
    def __init__(self, graph):
        self.n = len(graph)
        self.neg_cycle = False
        self.graph = graph
        self.dist = [[float("inf") for i in range(self.n)] for j in range(self.n)]
        self.check = [False for i in range(self.n)]

        for i in range(self.n):
            self.dist[i][i] = 0

    def find_shortest(self, src, dst):
        if self.neg_cycle:
            print("There is negative cycle")
            return -1

        if self.check[src]:
            return self.dist[src][dst]

        for i in range(1, self.n):
            for j in range(self.n):
                for e in self.graph[j]:
                    v, w = e[0], e[1]
                    if self.dist[src][v] > self.dist[src][j] + w and self.dist[src][j] != float("inf"):
                        self.dist[src][v] = self.dist[src][j] + w;

        for i in range(self.n):
            for e in self.graph[i]:
                v, w = e[0], e[1]
                if self.dist[src][v] > self.dist[src][i] + w and self.dist[src][i] != float("inf"):
                    print("There is negative cycle")
                    return -1

        return self.dist[src][dst]
