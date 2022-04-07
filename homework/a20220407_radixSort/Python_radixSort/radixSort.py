def radixSort(nums):
    # 遍历数组获取数组最大值和最大值对应的位数
    maxValue = nums[0]
    for n in nums:
        maxValue = max(n, maxValue)
    # 迭代次数
    iterCount = len(str(maxValue))
    for i in range(iterCount):
        # 定义桶，大小为10，对应0-9
        bucket = [[] for _ in range(10)]
        for n in nums:
            index = (n // 10 ** i) % 10
            bucket[index].append(n)
        # nums数组清零，并合并桶内元素至nums
        nums.clear()
        for b in bucket:
            nums.extend(b)
        print(nums)
    return nums


if __name__ == '__main__':
    nums = [334, 5, 67, 345, 7, 99, 4, 23, 78, 45, 1, 3453, 23424]
    radixSort(nums)
