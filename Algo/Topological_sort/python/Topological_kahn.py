import queue

class topological_sort_kahn:
    def __init__(self, g: list[list[int]]):
        self.graph = g
        self.target = []

        self.degree = [0]*len(g)
        for node in g:
            for n in node:
                self.degree[n] += 1

        self.q = queue.Queue()
        for i in range(len(g)):
            if self.degree[i] == 0:
                self.q.put(i)

    def print_res(self):
        while not self.q.empty():
            node = self.q.get()
            self.target.append(node)

            for n in self.graph[node]:
                self.degree[n] -= 1
                if self.degree[n] == 0:
                    self.q.put(n)

        print(self.target)
