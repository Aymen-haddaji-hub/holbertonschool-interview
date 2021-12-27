#!/usr/bin/python3
"""
finds minimum number of coins needed
to meet a given amount total.
"""


def makeChange(coins, total):
    """
    returns minimum number of coins needed
    to meet a given amount total.
    """
    if total <= 0:
        return 0
    coins.sort(reverse=True)
    a = 0
    count = 0
    while (a < len(coins)):
        if total == 0:
            return count
        if coins[a] > total:
            a += 1
        else:
            total -= coins[a]
            count += 1

    return -1