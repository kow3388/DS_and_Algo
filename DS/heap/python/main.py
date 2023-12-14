from heap import heap

if __name__ == "__main__":
    arr = [1, 4, 5, 6, 8, 2, 9, 3, 7]

    h = heap(arr)
    h.push(10)
    h.push(-1)

    h.heap_sort()
