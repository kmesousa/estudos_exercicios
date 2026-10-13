def binary_search (vetor: list[int], target: int):
    left, right = 0, len(vetor) - 1

    if not (vetor[left] > target and vetor[right] < target):
        while left <= right:
            mid = (left + right)//2
            print( left, vetor[left], mid, vetor[mid], right, vetor[right])
            if vetor[mid]==target:
                return True, mid
            elif vetor[mid] > target:
                right = mid - 1
            else:
                left = mid + 1
    return False

tests = [
    ([1, 2, 3, 4, 5],  5),
    ([1, 2, 3, 4, 5, 5],  5),
    ([1, 2, 3, 4, 5, 5],  6),
    ([1, 2, 3, 4, 5],  3),
    ([1, 2, 3, 4, 5],  2),
    ([1, 2, 3, 4, 5],  0),
]

for v, t in tests:
    print(binary_search(v, t))