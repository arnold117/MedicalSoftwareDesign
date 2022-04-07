def heapSort(arr):
    def sift_down(start, end):
        """最大堆调整"""
        root = start
        while True:
            child = 2 * root + 1
            if child > end:
                break
            if child + 1 <= end and arr[child] < arr[child + 1]:
                child += 1
            if arr[root] < arr[child]:
                arr[root], arr[child] = arr[child], arr[root]
                root = child
            else:
                break

    # 创建最大堆
    for start in range((len(arr) - 2) // 2, -1, -1):
        sift_down(start, len(arr) - 1)

    # 堆排序
    for end in range(len(arr) - 1, 0, -1):
        arr[0], arr[end] = arr[end], arr[0]
        sift_down(0, end - 1)
    return arr


if __name__ == '__main__':
    arr = [100, 16, 45, 46, 34, 75, 12, 3, 91, 10, 5]
    print(heapSort(arr))
