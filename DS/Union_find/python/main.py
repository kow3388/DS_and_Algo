from union_find import quick_find, quick_union
from union_find import weighted_quick_union, quick_union_path_compression
from union_find import weighted_quick_union_path_compression

def print_res(res: bool, node1: int, node2: int) -> None:
    if res:
        print("{} and {} is connected!".format(node1, node2))
    else:
        print("{} and {} isn't connected!".format(node1, node2))

if __name__ == "__main__":
    graph = [[0, 1], [0, 5], [1, 2],
             [1, 6], [2, 7], [3, 4],
             [3, 8], [4, 9], [5, 6]]
    n = 10
    #q = quick_find(n)
    #q = quick_union(n)
    #q = weighted_quick_union(n)
    #q = quick_union_path_compression(n)
    q = weighted_quick_union_path_compression(n)

    for g in graph:
        q.union_set(g[0], g[1])

    print("Is node0 and node7 connected?")
    print_res(q.is_connected(0, 7), 0, 7)
    print("Is node8 and node9 connected?")
    print_res(q.is_connected(8, 9), 8, 9)
    print("Is node2 and node9 connected?")
    print_res(q.is_connected(2, 9), 2, 9)
