#https://leetcode.com/problems/permutations/description/
'''
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

All the integers of nums are unique.
'''

#primeira tentativa
def permute (nums: list[int]) -> list[list[int]]:
    permutations = []
    current = []

    def backtrack(current):
        if len(current)==len(nums):
            permutations.append(current.copy()) #copy() é um detalhe importante!
            return
        for i in nums:
            if i not in current:
                current.append(i)
                backtrack(current)
                current.pop()

    for i in nums:
        current.append(i)
        backtrack(current)
        current.clear()

    for i in range(len(permutations)):
        print(f'{permutations[i]}')

    return permutations

#tentando rezumir
def permute (nums: list[int]) -> list[list[int]]:
    permutations = []
    current = []

    def backtrack():
        if len(current)==len(nums):
            permutations.append(current.copy()) #copy() é um detalhe importante!
            return
        for i in nums:
            if i not in current:
                current.append(i)
                backtrack(current)
                current.pop()
    backtrack()

    return permutations

#sem a subfunção backtrack
def permute (nums: list[int], current=None, permutations=None) -> list[list[int]]:

    if current==None:
        current = []
    if permutations==None:
        permutations = []

    if len(current)==len(nums):
        permutations.append(current.copy()) #copy() é um detalhe importante!
        #print(f'{current}')
        return

    for i in nums:
        if i not in current:
            current.append(i)
            permute(nums, current, permutations)
            current.pop()

    return permutations

#copiando/ tentando entender a versão mais rápida do leetcode
from collections import defaultdict

def permute_leetcode  (nums: list[int]) -> list[list[int]]:
    pass

    # check=defaultdict(bool)
    # res=[]
    # for i in nums:
    #     check[i]=False
    # def backtracking(current,check):
    #     if len(nums)==len(current):
    #         res.append(current.copy())
    #         return
    #     for i in nums:
    #         if check[i]:
    #             continue
    #         current.append(i)
    #         check[i] = True
    #         backtracking(current,check)
    #         current.pop()
    #         check[i]= False
    # backtracking([],check)
    # return res

print(f'permutations'.upper().center(40, '='))

tests = [
    [1,2,3],
    [0,1],
    [1],
    ['a', 'b', 'c', 'd'],
]

for i in tests:
    print(f'permutations of {i}'.upper().center(40, '='))
    result = permute(i)
    for j in result:
        print(j)
