import sys

input = sys.stdin.readline
n = int(input())
dp = [-1] * (1 << n)

MAX = 10000000
arr = []

for _ in range(n):
    arr.append(list(map(int, input().split())))

string = input().rstrip()
count = working = 0

for i in range(len(string)):
    if string[i] == "Y":
        count += 1
        working |= 1 << i

p = int(input())


def solve(cnt, visit):
    if cnt >= p:
        return 0

    ret = dp[visit]

    if ret != -1:
        return ret

    ret = MAX

    for i in range(n):
        if visit & (1 << (i)):
            for j in range(n):
                if not (visit & (1 << (j))):
                    ret = min(ret, solve(cnt + 1, visit | (1 << (j))) + arr[i][j])

    dp[visit] = ret

    return ret


minimum_cost = solve(count, working)
if minimum_cost >= MAX:
    print(-1)
else:
    print(minimum_cost)
