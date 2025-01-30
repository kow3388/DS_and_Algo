from tree_diameter import TreeDiameter

if __name__ == "__main__":
    graph = [
        [1, 2, 3],
        [0],
        [0, 4, 5, 7],
        [0, 6],
        [2],
        [2],
        [3],
        [2]
    ]

    t = TreeDiameter()
    print(f"The diameter of graph is {t.getDiameter(graph)}")