'''
Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.

Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
'''

from permutations import permute

#lógica demorada primeira tentativa, que não funciona rip
def combine(n: int, k: int) -> list[list[int]]:

    if k==1:
        return [list(range(1, n + 1))]

    combinations = []
    current = []

    def backtrack(size, k):
        if size < k:
            current.append(i)
            size += 1
            backtrack(size, k)
        else:
            for j in combinations:
                for k in permute(j):
                    if not k==current:
                        combinations.append(current.copy())
                        current.clear()
                        size = 0
                        break
                break

    for i in range(1, n + 1):
        size = 0
        current = []
        backtrack(size, k)

    return combinations

#lógica errada mas versão certa (era pra eu ter conseguido fazer sozinha, vacilei)
def combine(n: int, k: int) -> list[list[int]]:

    if k==1:
        #return [list(range(1, n + 1))]
        return [[i for i in range(1, n + 1)]]

    combinations = []
    current = []

    def backtrack():
        if len(current) < k:
            for i in range(1, n + 1): #faz todas as combinações
                if i not in current:
                    current.append(i)
                    backtrack()
                    current.pop()
        else:
            is_new = True
            for existing in combinations:
                if current in permute(existing):
                    is_new = False
                    break
            if is_new:
                combinations.append(current.copy())

    backtrack()

    return combinations


#while nao funciona, não entendo direito o porque, pergutar para salles

def combine(n: int, k: int) -> list[list[int]]:

    if k==1:
        return [[i for i in range(1, n +1)]]

    combinations = []
    current = []

    def backtrack(start=0):
        while len(current) < k:
            for i in range(start, (n + 1) - (k - len(current) - 1)): #n - k + len(current) + 2
                current.append(i)
                backtrack(i + 1)
                current.pop()
        combinations.append(current.copy())

    backtrack()

    return combinations


def combine(n: int, k: int) -> list[list[int]]:

    if k==1:
        return [[i for i in range(1, n +1)]]

    combinations = []
    current = []
    start = len(current) + 1

    def backtrack(start):
        if len(current) == k:
            combinations.append(current.copy())
        else:
            for i in range(start, (n + 1) - (k - len(current) - 1)): #ou: n - k + len(current) + 2
                current.append(i)
                backtrack(i + 1)
                current.pop()

    backtrack(start)

    return combinations
    #não foi tão difícil, me atrasou fazer os rascunhos com abcd e não número

def combine_list (items: list, k: int) -> list[list]:
    pass

#com itertools
from itertools import combinations
def combine_itertools ():
    pass

print(f'combinations'.upper().center(40, '='))

tests = [
    (4,1),
    (4,2),
    (4,3),
    (4,4),
    (1,1),
]

for n, k in tests:
    print(f'combinations of 1 to {n} by {k}'.upper().center(40, '='))
    result = combine(n,k)
    if result and isinstance(result, list):
        for j in result:
            print(j)