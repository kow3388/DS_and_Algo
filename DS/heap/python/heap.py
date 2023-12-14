class heap:
    def __init__(self, arr):
        self.h = self.heapify(arr)

    def heapify(self, arr):
        new_arr = []

        for i in range(len(arr)):
            new_idx = i
            parent_idx = (i+1)//2 - 1
            new_arr.append(arr[i])

            while parent_idx >= 0:
                if new_arr[new_idx] > new_arr[parent_idx]:
                    new_arr[new_idx], new_arr[parent_idx] = new_arr[parent_idx], new_arr[new_idx]
                    new_idx = parent_idx
                    parent_idx = (new_idx+1)//2 - 1
                else:
                    break

        return new_arr

    def push(self, val) -> None:
        self.h.append(val)
        new_idx = len(self.h) - 1
        parent_idx = (new_idx+1)//2 - 1

        while parent_idx >= 0:
            if self.h[new_idx] > self.h[parent_idx]:
                self.h[new_idx], self.h[parent_idx] = self.h[parent_idx], self.h[new_idx]
                new_idx = parent_idx
                parent_idx = (new_idx+1)//2 - 1
            else:
                break

        print("{} has been inserted in heap!".format(val))

    def pop(self):
        if len(self.h) == 0:
            print("There is no element in heap!")
        else:
            self.h[0], self.h[-1] = self.h[-1], self.h[0]

            val = self.h[-1]
            self.h.pop()

            i, idx = 0, -1
            while i < len(self.h):
                child_idx1, child_idx2 = 2*i+1, 2*i+2

                if child_idx1 >= len(self.h):
                    break
                elif child_idx2 >= len(self.h):
                    idx = child_idx1
                else:
                    idx = child_idx1 if self.h[child_idx1] > self.h[child_idx2] else child_idx2

                if self.h[i] < self.h[idx]:
                    self.h[i], self.h[idx] = self.h[idx], self.h[i]
                    i = idx
                else:
                    break

        return val

    def heap_sort(self):
        res = []
        while len(self.h) != 0:
            res.append(self.pop())

        print(res)
