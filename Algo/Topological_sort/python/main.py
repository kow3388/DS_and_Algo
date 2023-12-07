from Topological_dfs import topological_sort_dfs as dfs
from Topological_kahn import topological_sort_kahn as bfs

if __name__ == '__main__':
    graph = [[], [], [3], [1], [0, 1], [0, 2]]

    top_dfs = dfs(graph)
    top_bfs = bfs(graph)
    print('Using dfs res: ')
    top_dfs.print_res()
    print('Using Kahn(bfs) res: ')
    top_bfs.print_res()
