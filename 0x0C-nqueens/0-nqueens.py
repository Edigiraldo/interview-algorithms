#!/usr/bin/python3
"""Program to solve Nqueens problem."""
import sys


def check__atacking(Queen1, Queen2):
    """Checks if Queen1 and Queen2 are attacking
    each other."""
    x1, y1 = Queen1
    x2, y2 = Queen2

    if x1 == x2 or y1 == y2 or abs(x1 - x2) == abs(y1 - y2):
        return True

    return False


def check_input(inp):
    """Checks for a valid input."""
    if len(inp) != 2:
        print("Usage: nqueens N")
        exit(1)

    N = 0
    try:
        N = int(inp[1])
    except ValueError:
        print("N must be a number")
        exit(1)

    if N < 4:
        print("N must be at least 4")
        exit(1)

    return N


def get_positions(N, variant):
    """Gets posible solutions to N-Queens problem."""
    positions = [[k, 0] for k in range(N)]
    positions[0][1] = variant

    i = 0
    while i < N:
        j = 0
        while j < i:
            if positions[i][1] > N - 1:
                positions[i][1] = 0
                positions[i - 1][1] += 1
                i -= 2
                break
            if check__atacking(positions[i], positions[j]):
                positions[i][1] += 1
                j = 0
            else:
                j += 1
        i += 1

    return positions


def rotate_board(positions):
    """Returns rotated positions."""
    N = len(positions)
    rotated = [[0, 0] for i in range(N)]

    for i in range(N):
        rotated[i][0] = positions[i][1]
        rotated[i][1] = - positions[i][0] + (N - 1)

    rotated = sorted(rotated, key=lambda x: x[0])

    return rotated


inp = sys.argv
N = check_input(inp)

variant = 0
all_pos = []
while variant < N:
    pos = get_positions(N, variant)
    y = pos[0][1]
    variant = y + 1
    valid = all([Queen[0] < N and Queen[1] < N for Queen in pos])
    if valid:
        pos = sorted(pos, key=lambda x: x[0])
        all_pos.append(pos)

for pos in all_pos:
    current_pos = pos
    for i in range(3):
        current_pos = rotate_board(current_pos)
        different = True
        for j in range(len(all_pos)):
            if all_pos[j] == current_pos:
                different = False
        if different is True:
            all_pos.append(current_pos)

for pos in all_pos:
    print(pos)
