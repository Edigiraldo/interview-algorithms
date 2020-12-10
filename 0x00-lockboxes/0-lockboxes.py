#!/usr/bin/python3
"""Determines if all boxes can be opened."""


def canUnlockAll(boxes):
    """method that determines if all the boxes can be opened."""
    n = len(boxes)

    if n == 0:
        return True

    opened = []

    for i in range(0, n):
        opened.append(False)

    opened[0] = True
    openBox(boxes, opened, 0)

    return all(opened)


def openBox(boxes, opened, nBox):
    """Open boxes recursively."""
    for key in boxes[nBox]:
        if key < len(boxes) and opened[key] is False:
            opened[key] = True
            openBox(boxes, opened, key)
