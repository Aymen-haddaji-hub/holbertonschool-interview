#!/usr/bin/python3
"""
You have n number of locked boxes in front of you. Each box is numbered
sequentially from 0 to n - 1 and each box may contain keys to the other boxes.

"""


def canUnlockAll(boxes):
    """
    a method that determines if all the boxes can be opened.
    """

    n = len(boxes)
    keys = boxes[0]
    locked_box = [False] + [True] * (n - 1)
    for i in keys:
        if ((i < n) and (locked_box[i] is True)):
            locked_box[i] = False
            keys.extend(boxes[i])
    return not any(locked_box)
