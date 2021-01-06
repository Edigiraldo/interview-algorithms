#!/usr/bin/python3
"""Minimun copy paste operations."""


def minOperations(n):
    """Starting with a single H, minimun number of
    copy or paste operations to achieve n H's in file."""
    if n <= 1:
        return 0

    NOper = 2
    HsInFile = 2
    ClipboardHs = 1

    while HsInFile < n:
        if n % HsInFile == 0:
            ClipboardHs = HsInFile
            NOper += 1
        HsInFile += ClipboardHs
        NOper += 1
    return NOper
