from Dijkstra import Dijkstra as D

if __name__ == "__main__":
    graph = [[[1, 4], [2, 2]],
             [[0, 4], [4, 3]],
             [[0, 2], [3, 2], [5, 4]],
             [[2, 2], [4, 3], [5, 1]],
             [[1, 3], [3, 3], [5, 1]],
             [[2, 4], [3, 1], [4, 1]]]

    dij = D(graph)
    src, dst = 0, 4
    shortest = dij.find_shortest_path(src, dst)

    print("The shortest path from {} to {} is {}".format(src, dst, shortest))
