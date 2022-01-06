##!/usr/bin/python3
"""prime game python script"""


def isWinner(x, nums):
    """
    Function that returns the winner of the game"""

    if not nums or x < 1:
        return None
    max_num = max(nums)
    tmp = [True for _ in range(max(max_num + 1, 2))]
    for i in range(2, int(pow(max_num, 0.5)) + 1):
        if not tmp[i]:
            continue
        for j in range(i * i, max_num + 1, i):
            tmp[j] = False
    tmp[0] = tmp[1] = False
    a = 0
    for i in range(len(tmp)):
        if tmp[i]:
            a += 1
        tmp[i] = a
    p_1 = 0
    for max_num in nums:
        p_1 += tmp[max_num] % 2 == 1
    if p_1 * 2 == len(nums):
        return None
    if p_1 * 2 > len(nums):
        return "Maria"
    return "Ben"
