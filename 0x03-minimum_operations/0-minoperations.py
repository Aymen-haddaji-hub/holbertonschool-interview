#!/usr/bin/python3
"""
Minimum Operations Module.
"""


def minOperations(n):
    """
    method that calculates the fewest number of operations
    needed to result in exactly n H characters in the file
    """

    if (not isinstance(n, int)):
        return 0

    if (n < 2):
        return 0

    res = 0
    i = 2
    while i <= n:
        if n % i == 0:
            res += i
            n = n / i
            i = i - 1
        i = i + 1
    return int(res)
