count = 0
n = int(input())
arr = list(map(int, input().split()))


def mergeSort(start, end):
    global count
    if start < end:
        mid = (start + end) // 2
        mergeSort(start, mid)
        mergeSort(mid + 1, end)

        a = start
        b = mid + 1
        tmp = []

        while a <= mid and b <= end:
            if arr[a] <= arr[b]:
                tmp.append(arr[a])
                a += 1
            else:
                tmp.append(arr[b])
                b += 1
                count += mid - a + 1

        if a <= mid:
            tmp += arr[a : mid + 1]

        if b <= end:
            tmp += arr[b : end + 1]

        for i in range(len(tmp)):
            arr[start + i] = tmp[i]


mergeSort(0, len(arr) - 1)
print(count)
