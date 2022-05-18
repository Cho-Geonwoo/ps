gears = [list(map(int, list(input()))) for i in range(4)]
visited = [0, 0, 0, 0]


def move_gear(gear_number, direction):
    current_gear = gears[gear_number]
    if direction == -1:
        gears[gear_number] = current_gear[1 : len(current_gear)] + [current_gear[0]]
    else:
        gears[gear_number] = [current_gear[-1]] + current_gear[
            0 : len(current_gear) - 1
        ]


def rotate(gear_number, direction):
    if visited[gear_number] == 1:
        return
    visited[gear_number] = 1
    left_gear = gear_number - 1
    right_gear = gear_number + 1

    if (left_gear >= 0) and (gears[gear_number][6] != gears[left_gear][2]):
        move_gear(left_gear, -direction)
    if (right_gear <= 3) and (gears[gear_number][2] != gears[right_gear][6]):
        move_gear(right_gear, -direction)

    move_gear(gear_number, direction)


K = int(input())
while K > 0:
    gear_number, direction = list(map(int, input().split()))
    rotate(gear_number - 1, direction)
    K -= 1
    visited = [0, 0, 0, 0]

sum = 0
score = 1
for gear in gears:
    if gear[0] == 0:
        pass
    else:
        sum += score
    score *= 2

print(sum)
