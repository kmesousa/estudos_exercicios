''' https://leetcode.com/problems/time-needed-to-buy-tickets/description/

There are n people in a line queuing to buy tickets, where the 0th person is at the front of the line and the (n - 1)th person is at the back of the line.

You are given a 0-indexed integer array tickets of length n where the number of tickets that the ith person would like to buy is tickets[i].

Each person takes exactly 1 second to buy a ticket. A person can only buy 1 ticket at a time and has to go back to the end of the line (which happens instantaneously) in order to buy more tickets. If a person does not have any tickets left to buy, the person will leave the line.

Return the time taken for the person initially at position k (0-indexed) to finish buying tickets

'''
#cara eu acho que nem precisa de fila pra fazer isso
def timeRequiredToBuy(tickets: list[int], k: int) -> int:
    target = tickets[k] #nossa só fazer isso melhorou mt o uso de memoria uau
    seconds = target

    for i in tickets[:k]:
        if i < target:
            seconds += i
        else:
            seconds += target
    for i in tickets[k+1:]:
        if i > target - 1:
            seconds += target - 1
        else:
            seconds += i

    return seconds

#agora usando fila só pela arte mesmo (seria mt mais difícil nem consigo pensar na lógica)
def timeRequiredToBuy_v2(tickets: list[int], k: int) -> int:
    from collections import deque

    stack = []
    seconds = 0

    return seconds

#testes
print(f'time to buy'.upper().center(40, '='))

tests = [
    ([2,3,2], 2),
    ([5,1,1,1], 0),
]

for tickets, k in tests:
    print(f'tickets: {tickets} k: {k}'.upper().center(40, '='))
    print(f'time required: {timeRequiredToBuy(tickets, k)}')