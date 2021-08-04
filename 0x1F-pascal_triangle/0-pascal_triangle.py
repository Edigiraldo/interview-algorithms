#!/usr/bin/python3
"""Function pascal_triangle."""


def pascal_triangle(n):
    """
    Function that returns a list of lists of integers representing
    the Pascal’s triangle of n.
    """
    pascal = []

    if n <= 0:
        return pascal

    pascal.append([1])
    for i in range(n - 1):
        row = pascal[i]
        next_row = row.copy()
        next_row = next_row + [1]

        next_row_original = next_row.copy()
        for j in range(1, len(next_row) - 1):
            next_row[j] = next_row_original[j - 1] + next_row_original[j]

        pascal.append(next_row)

    return pascal
