"""Pascal Triangle module"""


def pascal_triangle(n):
    """
    Function that returns a list of lists of integers representing the Pascal's
    triangle of n
    """
    if n <= 0:
        return []
    if n == 1:
        return [[1]]
    if n == 2:
        return [[1], [1, 1]]
    prev = pascal_triangle(n - 1)
    curr = [1]
    for i in range(len(prev[-1]) - 1):
        curr.append(prev[-1][i] + prev[-1][i + 1])
    curr.append(1)
    prev.append(curr)
    return prev
