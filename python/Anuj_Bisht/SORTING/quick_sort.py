# Program to perform quick sort

# function to perform partition
def partition(array_1, p, r):
    i = p - 1
    pivot = array_1[r]
    for j in range(p, r):
        if array_1[j] <= pivot:
            i += 1
            array_1[i], array_1[j] = array_1[j], array_1[i]
    array_1[i + 1], array_1[r] = array_1[r], array_1[i + 1]
    return i+1


# function to perform quick sort
def quickSort(array_1, p, r):
    if p < r:
        q = partition(array_1, p, r)
        quickSort(array_1, p, q-1)
        quickSort(array_1, q+1, r)


if __name__ == '__main__':
    # scanning the size of the array
    size = int(input("Enter the size of the array: "))
    array = []

    # scanning the elements of the array
    for i in range(size):
        element = int(input(f"Element [{i}]: "))
        array.append(element)

    # assigning the zeroth index to low and last index to high
    low, high = 0, size-1

    # printing the array
    print("Array:", array)

    # calling quickSort function
    quickSort(array, low, high)

    # printing the sorted array
    print("Sorted Array:", array)
