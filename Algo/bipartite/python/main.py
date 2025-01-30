from Bipartite import BipartiteDFS, BipartiteBFS

def printResult(name: str, res: bool) -> None:
    if res:
        print(f"{name} is bipartite graph!")
    else:
        print(f"{name} isn't bipartite graph!")

if __name__ == "__main__":
    graph1 = [
        [1, 3, 4],
        [0, 2, 5],
        [1],
        [0, 5],
        [0],
        [1, 3]
    ]
    graph2 = [
        [1, 3, 4],
        [0, 2, 3, 5],
        [1],
        [0, 1, 5],
        [0],
        [1, 3]
    ]

    bipartiteDFS = BipartiteDFS()
    print("Method DFS: ")
    printResult("Graph1", bipartiteDFS.checkBipartite(graph1))
    printResult("Graph2", bipartiteDFS.checkBipartite(graph2))

    print("="*50)

    bipartiteBFS = BipartiteBFS()
    print("Method BFS: ")
    printResult("Graph1", bipartiteBFS.checkBipartite(graph1))
    printResult("Graph2", bipartiteBFS.checkBipartite(graph2))