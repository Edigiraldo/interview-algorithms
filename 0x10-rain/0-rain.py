#!/usr/bin/python3
"""Function rain."""


def rain(walls):
    """
    Given a list of non-negative integers representing walls of
    width 1, this function calculate how much water will be
    retained after it rains.

    - walls is a list of non-negative integers.

    Return: Integer indicating total amount of rainwater retained.
    """
    if len(walls) == 0:
        return 0

    return rainwater(0, walls, 1)


def rainwater(accumulated, walls, level):
    """
    - accumulated is the accumulated volume of first levels.
    - walls is a list representing the walls.
    - level is the current height where we want to compute the
      enclosed volume for the walls of that height.
    """
    n = len(walls)
    for left in range(n):
        if walls[left] >= level:
            break

    for right in range(n - 1, -1, -1):
        if walls[right] >= level:
            break

    level_volume = right - 1 - left
    if level_volume <= 0:
        return accumulated

    # each wall with volume 1.
    for i in range(left + 1, right):
        if walls[i] >= level:
            level_volume -= 1

    accumulated += level_volume
    level += 1

    return rainwater(accumulated, walls, level)
