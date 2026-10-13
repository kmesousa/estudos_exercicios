''' https://leetcode.com/problems/valid-parentheses/
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
'''
#second try
def isValid(s: str) -> bool:
    stack = []

    pair = {
        "(": ")",
        "[": "]",
        "{": "}"
        }

    for i in s:
        if i in pair.keys():
            stack.append(pair[i])
        else: #elif i in pairs.values() if string had other type of characthers
            if stack == []:
                return False
            elif i != stack[-1]:
                return False
            stack.pop()

    if not stack == []:
        return False

    return True

#first try
def isValid(s: str) -> bool:
    stack = []

    opening = {
        "(": 1,
        "[": 2,
        "{": 3
        }

    closing = {
        ")": 1,
        "]": 2,
        "}": 3
       }

    for i in s:
        if i in opening:
            stack.append(opening[i])
        elif i in closing:
            if stack == []:
                return False
            elif closing[i] - stack[-1] != 0:
                return False
            stack.pop()

    if not stack == []:
        return False

    return True

print(f'valid associations signs'.upper().center(40, '='))

tests = [
    "()",
    "()[]{}",
    "(]",
    "([])",
    "([)]",
    "{[()]}"
]

for i in tests:
    print(f'associations of {i}'.upper().center(40, '='))
    print(f'valid: {isValid(i)}')