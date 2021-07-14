#!/usr/bin/python3
"""Function island_perimeter."""


def island_perimeter(grid):
    """
    Function that returns the perimeter of the island described in grid.

    - grid is a list of list of integers:
        - 0 represents water.
        - 1 represents land.
        - Each cell is square, with a side length of 1.
        - Cells are connected horizontally/vertically (not diagonally).
        - grid is rectangular, with its width and height not exceeding 100.

    Return: the perimeter of the island.
    """
    m, n = len(grid), len(grid[0])

    perimeter = 0
    for i in range(m):
        for j in range(n):
            if grid[i][j] == 1:
                # not superior column.
                if i > 0:
                    if grid[i - 1][j] == 0:
                        perimeter += 1
                else:
                    perimeter += 1

                # not inferior column.
                if i < m - 1:
                    if grid[i + 1][j] == 0:
                        perimeter += 1
                else:
                    perimeter += 1

                # not left column.
                if j > 0:
                    if grid[i][j - 1] == 0:
                        perimeter += 1
                else:
                    perimeter += 1

                # not right colum.
                if j < n - 1:
                    if grid[i][j + 1] == 0:
                        perimeter += 1
                else:
                    perimeter += 1

    return perimeter
