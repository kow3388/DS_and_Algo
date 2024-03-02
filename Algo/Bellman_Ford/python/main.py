from Bellman_Ford import bellman_ford as BF

if __name__ == "__main__":
    graph = [[[1, 4], [2, 2]],
             [[0, 4], [4, 3]],
             [[0, 2], [3, 2], [5, 4]],
             [[2, 2], [4, 3], [5, 1]],
             [[1, 3], [3, 3], [5, 1]],
             [[2, 4], [3, 1], [4, 1]]]

    bf = BF(graph)
    src, dst = 0, 4
    shortest = bf.find_shortest(src, dst)

    if shortest == float("inf"):
        print("There is no path from {} to {}".format(src, dst))
    elif shortest == -1:
        print("There is negative cycle")
    else:
        print("The shortest path from {} to {} is {}".format(src, dst, shortest))
