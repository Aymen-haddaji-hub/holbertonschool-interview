##!/usr/bin/python3
"""prime game python script"""


def isWinner(x, nums):
    """
    Function that returns the winner of the game"""

    if not nums:
        return None
    max_num = max(nums)
    filters = [True for i in range(max(max_num + 1, 2))]
    for i in range(2, int(pow(max_num, 0.5)) + 1):
        if filters[i]:
            for j in range(i * i, max_num + 1, i):
                filters[j] = False
    filters[0] = filters[1] = False
    a = 0
    for i in range(len(filters)):
        if filters[i]:
            a += 1
        filters[i] = a
    player_1 = 0
    for max_num in nums:
        player_1 += filters[max_num] % 2 == 1
    if player_1 * 2 == len(nums):
        return None
    if player_1 * 2 > len(nums):
        return "Maria"
    return "Ben"
