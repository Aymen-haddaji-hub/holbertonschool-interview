#!/usr/bin/python3
"""
calculate how many square units of water will be retained after it rains
"""


def rain(walls):
    """
    calculat how many square units of water
    will be retained after it rains
    """

    if not len(walls):
        return 0
    size = len(walls)
    water = 0
    for i in range(size):
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])
        right = walls[i]
        for j in range(i + 1, len(walls)):
            right = max(right, walls[j])
        water += min(left, right) - walls[i]
    return water
