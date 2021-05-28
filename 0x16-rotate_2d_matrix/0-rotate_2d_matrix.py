#!/usr/bin/python3
"""Funciton rotate_2d_matrix."""


def rotate_2d_matrix(matrix):
    """
    Given an n x n 2D matrix, rotate it 90 degrees clockwise.

    - matrix: matrix for 90 degrees in place rotation.
    """
    L = len(matrix[0])

    for i in range(L // 2):
        L1 = L - 1
        for j in range(i, L1 - i):
            temp = matrix[i][j]
            matrix[i][j] = matrix[L1 - j][i]
            matrix[L1 - j][i] = matrix[L1 - i][L1 - j]
            matrix[L1 - i][L1 - j] = matrix[j][L1 - i]
            matrix[j][L1 - i] = temp
