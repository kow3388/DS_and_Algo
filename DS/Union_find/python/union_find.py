class quick_find:
    def __init__(self, n: int):
        self.parent = [i for i in range(n)]

    def find_root(self, node: int) -> int:
        return self.parent[node]

    def union_set(self, node1: int, node2: int) -> None:
        root1 = self.find_root(node1)
        root2 = self.find_root(node2)

        if root1 != root2:
            for i in range(len(self.parent)):
                if self.parent[i] == root1:
                    self.parent[i] = root2
            
            print("{} and {} have been union!".format(node1, node2))
        else:
            print("{} and {} already be union!".format(node1, node2))

    def is_connected(self, node1: int, node2: int) -> bool:
        return self.find_root(node1) == self.find_root(node2)

class quick_union:
    def __init__(self, n: int):
        self.parent = [i for i in range(n)]

    def find_root(self, node: int) -> int:
        if node != self.parent[node]:
            return self.find_root(self.parent[node])
        return node

    def union_set(self, node1: int, node2: int) -> None:
        root1 = self.find_root(node1)
        root2 = self.find_root(node2)

        if root1 != root2:
            self.parent[root1] = root2
            print("{} and {} have been union!".format(node1, node2))
        else:
            print("{} and {} already be union!".format(node1, node2))

    def is_connected(self, node1: int, node2: int) -> bool:
        return self.find_root(node1) == self.find_root(node2)

class weighted_quick_union:
    def __init__(self, n: int):
        self.parent = [i for i in range(n)]
        self.size = [1 for i in range(n)]

    def find_root(self, node: int) -> int:
        if node != self.parent[node]:
            return self.find_root(self.parent[node])
        return node

    def union_set(self, node1: int, node2: int) -> None:
        root1 = self.find_root(node1)
        root2 = self.find_root(node2)

        if root1 != root2:
            if self.size[root1] > self.size[root2]:
                self.parent[root2] = root1
                self.size[root1] += self.size[root2]
            else:
                self.parent[root1] = root2
                self.size[root2] += self.size[root1]
            print("{} and {} have been union!".format(node1, node2))
        else:
            print("{} and {} already be union!".format(node1, node2))

    def is_connected(self, node1: int, node2: int) -> bool:
        return self.find_root(node1) == self.find_root(node2)

class quick_union_path_compression:
    def __init__(self, n: int):
        self.parent = [i for i in range(n)]

    def find_root(self, node: int) -> int:
        if node != self.parent[node]:
            self.parent[node] = self.find_root(self.parent[node])

        return self.parent[node]

    def union_set(self, node1: int, node2: int) -> None:
        root1 = self.find_root(node1)
        root2 = self.find_root(node2)

        if root1 != root2:
            self.parent[root1] = root2
            print("{} and {} have been union!".format(node1, node2))
        else:
            print("{} and {} already be union!".format(node1, node2))

    def is_connected(self, node1: int, node2: int) -> bool:
        return self.find_root(node1) == self.find_root(node2)

class weighted_quick_union_path_compression:
    def __init__(self, n: int):
        self.parent = [i for i in range(n)]
        self.size = [1 for i in range(n)]

    def find_root(self, node: int) -> int:
        if node != self.parent[node]:
            self.parent[node] = self.find_root(self.parent[node])
        return self.parent[node]

    def union_set(self, node1: int, node2: int) -> None:
        root1 = self.find_root(node1)
        root2 = self.find_root(node2)

        if root1 != root2:
            if self.size[root1] > self.size[root2]:
                self.parent[root2] = root1
                self.size[root1] += self.size[root2]
            else:
                self.parent[root1] = root2
                self.size[root2] += self.size[root1]
            print("{} and {} have been union!".format(node1, node2))
        else:
            print("{} and {} already be union!".format(node1, node2))

    def is_connected(self, node1: int, node2: int) -> bool:
        return self.find_root(node1) == self.find_root(node2)
