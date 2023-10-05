def swap(arr, i, j):
        temp = arr[i]
        arr[i] = arr[j]
        arr[j] = temp
def selection_sort(arr: list):
    
    for i in range(len(arr) - 1):
        min_idx = i
        for j in range(i + 1, len(arr)):
            if arr[j] < arr[min_idx]:
                min_idx = j
        if i != min_idx:
            swap(arr, i, min_idx)
    return arr
def bubble_sort(arr: list):
    i = len(arr) - 1
    while i > 0:
        for j in range(i):
            if arr[j] > arr[j + 1]:
                swap(arr, j, j + 1)
        i -= 1
    return arr
def insertion_sort(arr: list):
    for i in range(len(arr)):
        for j in range(i):
            if arr[j] > arr[i]:
                swap(arr, i, j)
    return arr
def merge_sort(arr, low, high):
    mid = (low + high)//2
    if low >= high:
        return
    merge_sort(arr, low, mid)
    merge_sort(arr, mid + 1, high)
    merge(arr, low, mid, high)
    return arr
def merge(arr, low, mid, high):
        temp = []
        left = low
        right = mid + 1
        while left <= mid and right <= high:
            if arr[left] <= arr[right]:
                temp.append(arr[left])
                left += 1
            else:
                temp.append(arr[right])
                right += 1
        while left <= mid:
            temp.append(arr[left])
            left += 1
        while right <= high:
            temp.append(arr[right])
            right += 1
        for i in range(len(temp)):
            arr[low + i] = temp[i]
def partitionArray(arr: list[int], startIndex: int, endIndex: int) -> int:
    pivot = arr[startIndex]

    count = 0
    
    for i in range(startIndex + 1, endIndex + 1):
        if arr[i] <= pivot:
            count += 1
    pivotIndex = startIndex + count
    temp = arr[startIndex]
    arr[startIndex] = arr[pivotIndex]
    arr[pivotIndex] = temp

    i = startIndex
    j = endIndex
    while i <= pivotIndex and j >= pivotIndex:
        while i<= pivotIndex and arr[i] <= pivot:
            i += 1
        while j>= pivotIndex and arr[j] > pivot:
            j -= 1
        if i < pivotIndex and j > pivotIndex:
            temp = arr[i]
            arr[i] = arr[j]
            arr[j] = temp
            i += 1
            j -= 1

    return pivotIndex
def quickSort(arr: list[int], startIndex: int, endIndex: int):
    if startIndex >= endIndex:
        return
    pivotIndex = partitionArray(arr, startIndex, endIndex)
    quickSort(arr, startIndex, pivotIndex - 1)
    quickSort(arr, pivotIndex + 1, endIndex)
def heapify(arr, n, i):
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2

   
    if left < n and arr[left] > arr[largest]:
        largest = left

    
    if right < n and arr[right] > arr[largest]:
        largest = right

    
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        
        heapify(arr, n, largest)

def heap_sort(arr):
    n = len(arr)

    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]  
        heapify(arr, i, 0)  
    return arr
