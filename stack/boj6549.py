arr = list(map(int, input().split()))

while True:
    N = arr[0]
    del arr[0]

    if N == 0:
        break

    sum = 0
    stack = []
    for i in range(len(arr)):
        while (len(stack) != 0) and (arr[stack[-1]] > arr[i]):
            height = arr[stack[-1]]
            del stack[-1]
            width = i
            if len(stack) > 0:
                width = i - stack[-1] - 1
            sum = max(sum, height * width)
        stack.append(i)

    while len(stack) != 0:
        height = arr[stack[-1]]
        del stack[-1]
        width = N
        if len(stack) > 0:
            width = N - stack[-1] -1
        sum = max(sum, height * width)

    print(sum)
    arr = list(map(int, input().split()))
