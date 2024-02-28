from Floyd_Warshall import floyd_warshall as FW

if __name__ == "__main__":
    graph = [[[1, 4], [2, 2]],
             [[0, 4], [4, 3]],
             [[0, 2], [3, 2], [5, 4]],
             [[2, 2], [4, 3], [5, 1]],
             [[1, 3], [3, 3], [5, 1]],
             [[2, 4], [3, 1], [4, 1]]]

    fw = FW(graph)
    src, dst = 0, 4
    fw.calculate_shortest()
    shortest = fw.shortest(src, dst)

    if shortest == float("inf"):
        print("There is no path from {} to {}".format(srt, dst))
    else:
        print("The shortest path from {} to {} is {}".format(src, dst, shortest))
