from Topological import topological_sort as T

if __name__ == '__main__':
    graph = [[], [], [3], [1], [0, 1], [0, 2]]

    top = T(graph)
    top.print_res()
