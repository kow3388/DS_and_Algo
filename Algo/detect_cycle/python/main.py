import is_cycle

if __name__ == '__main__':
    graph = [[1, 2], [2], [0, 3], []]

    check = is_cycle.check_cycle(graph)

    if check.iscycle():
        print('The graph has cycle.')
    else:
        print('The graph has no cycle.')
