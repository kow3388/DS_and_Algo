import heapq

class Dijkstra:
    def __init__(self, graph: list[list[list[int]]]):
        self.graph = graph
        self.n = len(graph)
        self.min_heap = []

    def find_shortest_path(self, src: int, dst: int) -> int:
        shortest = [float("inf") for i in range(self.n)]
        shortest[0] = 0

        heapq.heappush(self.min_heap, [src, 0])

        while len(self.min_heap) != 0:
            curr, dist = heapq.heappop(self.min_heap)

            if dist > shortest[curr]:
                continue

            shortest[curr] = dist

            for g in self.graph[curr]:
                post = g[0]
                coast = g[1] + dist

                heapq.heappush(self.min_heap, [post, coast])

        return int(shortest[dst])
