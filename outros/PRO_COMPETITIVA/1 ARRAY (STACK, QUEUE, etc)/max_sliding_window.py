''' https://leetcode.com/problems/sliding-window-maximum/description/

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation:
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

Window position                Max
---------------               -----
[1  2  -1] 3  5  3  6  7       2
 1 [2  -1  3] 5  3  6  7       3
 1  2 [-1  3  5] 3  6  7       5
 1  2  -1 [3  5  3] 6  7       5
 1  2  -1  3 [5  3  6] 7       6
 1  2  -1  3  5 [3  6  7]      7

Example 2:

Input: nums = [1], k = 1
Output: [1]

começa com o primeiro numero no stack, stack nao começa vazio

se o idx for maior q k, começa a checar se o primeiro valor do stack nao pertence mais a janela, se nao pertencer, remover (checagem precisa ser feita apenas 1 vez por iteração)

adiciona o numero atual ao stack

- se for menor que o primeiro, continuar sem remover nada
- se for maior que os anteiores (precisa apenas ser maior q o primeiro que pertence a janela)

        - remover todos do stack, menos o atual
        - definir o atual como current_max

[ ! pontos importantes ! ]:

- sempre vai adicionar os novos valores/numero atual ao stack, a questão é quando vai remover os antigos e como vai definir qual o maior da janela atual

- stack nunca vai estar vazio.
'''

def formatar_janelas (nums: list[int], k: int) -> list[str]:
    result = []
    #inicio da janela
    for janela in range(len(nums) - k + 1):
        atual = ''
        #lista completa de numeros para cada janela
        for idx in range(len(nums)):
            pre = ''
            pos = ''

            #para os primeiros
            if idx==0 and idx!=janela:
                atual += ' '

            #numeros
            if idx==janela:
                pre = '['
            if idx==janela + k -1:
                pos = ']'

            atual += f'{pre}{nums[idx]}{pos}'

            #espaços entre
            if idx == janela + k -1 or idx == janela -1:
                atual += ' '
            else:
                atual += '  '

        result.append(atual)
    return result

#da pra resolver de várias formas, aparentemete

#intuitivo (error: time run out, O(n²) eu acho?)
def maxSlidingWindow(nums: list[int], k: int) -> list[int]:
    result = []

    for i in range(len(nums) - k + 1):
        result.append(max(nums[i:i+k]))
    return result

#minha tentativa que não sei classificar em qual método vai cair, provavelmente fila
def maxSlidingWindow(nums: list[int], k: int) -> list[int]:
    from collections import deque
    result = []
    stack = deque([(nums[0], 0)])
    current_max = nums[0]
    current_window = 0

    for idx in range(1, len(nums)): #ou: for idx, num in enumerate(nums[1:-k+1]):

        #definir num atual para economizar memoria
        num = nums[idx]

        #se estiver além do limite da primeira janela
        if idx >= k:

            #definir proxima janela
            current_window += 1

            #adicionar maior da janela anterior
            result.append(current_max) #tem q ser definido com cautela anteiormente

            #remover os que nao pertencem a janela atual
            if stack[0][1] < current_window:
                stack.popleft()

        #remover numeros menores que o atual
        while stack and num >= stack[-1][0]:
            stack.pop()

        #adicionar o num atual ao stack e definir current_max
        stack.append((num, idx))
        current_max = stack[0][0]

    #adicionar o ultimo current_max
    result.append(current_max)

    return result

#mais compacta
def maxSlidingWindow(nums: list[int], k: int) -> list[int]:
    from collections import deque
    result = []
    stack = deque()

    for idx in range(len(nums)):

        if idx >= k:

            result.append(stack[0][0])

            if stack[0][1] < idx - k - 1: #current window
                stack.popleft()

            num = nums[idx]

            if len(stack) > 1 and stack[-1][0] <= num:
                stack.pop()

            stack.append((num, idx))

    return result

#heap (preciso tentar entender esse)

#busca binaria ?


#testes
def solucao_completa(nums: list[int], k: int) -> None:
    janelas = formatar_janelas(nums, k)
    resultados = maxSlidingWindow(nums, k)

    for i in range(len(janelas)):
        print(f'{janelas[i]} | {resultados[i] if len(resultados)>i else 'None'}')


print(f'max sliding window'.upper().center(40, '='))

tests = [
    ([1,3,-1,-3,5,3,6,7], 3),
    ([1,1], 1),
    ([8, 2, 4, 5, 7, 2], 4),
    ([8, 2, 4, 5, 7, 10], 4),
    ([9,8,7,6,5], 2),
    ([1,3,1,2,0,5], 3)
]

for l, k in tests:
    print('\n',f'windows of {l} by {k}'.upper().center(40, '='))
    solucao_completa(l, k)

# def test_cases (tests:list, func:function, title:str=None):

#     if not title:
#         print(f'{func.__name__}')
#     else:
#         print(f'{title.upper().center(40, '=')}')

#     for i in tests:
#         pass