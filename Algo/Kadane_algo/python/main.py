import Kadane as K

if __name__ == '__main__':
    arr1 = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
    arr2 = [-2.5, 1.4, -3.9, 4.0, -1.2, 2.2, 1.5, -5.6, 4.1]

    k_int = K.Kadane(arr1)
    k_float = K.Kadane(arr2)

    print("The maximum subarray of array1 = ", k_int.algo())
    print("The maximum subarray of array2 = ", k_float.algo())
