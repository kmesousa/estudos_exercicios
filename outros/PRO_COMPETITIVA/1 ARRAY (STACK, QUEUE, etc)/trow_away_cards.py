#https://judge.beecrowd.com/en/problems/view/1110
from collections import deque

'''
ex: 7
7 cartas enumeradas de 1 a 7
carta 1 esta no topo e carta 7 em baixo
carta do topo é removida (1)
a carta do topo é movida para baixo (2)
repete até sobrar só 1

1 2 3 4 5 6 7
3 4 5 6 7 2
5 6 7 2 4
7 2 4 6
4 6 2
2 6
6

cartas removidas: 1 3 5 7 4 2
carta restante: 6

podia fazer isso com listas, mas creio que seja ineficiente para crlh
ent tenho que pensar em uma formula que resolva isso,
vamos ver

10
1 2 3 4 5 6 7 8 9 10
2 4 6 8 10

outros exemplos
7
19
10
6
0

Discarded cards: 1, 3, 5, 7, 4, 2
Remaining card: 6
Discarded cards: 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 4, 8, 12, 16, 2, 10, 18, 14
Remaining card: 6
Discarded cards: 1, 3, 5, 7, 9, 2, 6, 10, 8
Remaining card: 4
Discarded cards: 1, 3, 5, 2, 6
Remaining card: 4

'''

#JEITO MAIS INTUITIVO E O QUE SALES USOU TBM
def trowing_literal (number):
    if number < 1:
        return

    #creating the pile of cards
    # cards = []
    # for i in range(1, number+1):
    #     cards.append(i)

    #creating a deque of cards (pop left O(1))
    cards = deque(range(1, number + 1))

    discarded = []
    while len(cards)>=2:
        # discarded.append(cards.pop(0))
        # cards.append(cards.pop(0))
        discarded.append(str(cards.popleft()))
        cards.append(cards.popleft())

    print(f'Discarded cards: {", ".join(discarded)}')
    print(f'Remaining card: {cards[0]}')

def trowing_literal_analyzed (number):
    if number < 1:
        return
    if number < 2:
        return number

    #creating the pile of cards
    cards = []
    for i in range(1, number+1):
        cards.append(i)

    print(f'lista: {cards}')

    removidas = []
    ultimo = cards[-1]
    nova_fase = False
    printar = False
    while len(cards)>1:
        removida = cards.pop(0)
        movida = cards.pop(0)
        removidas.append(removida)
        cards.append(movida)
        if movida==ultimo:
            ultimo = cards[-1]
            nova_fase = True
        elif removida==ultimo:
            ultimo = cards[-1]
            nova_fase = True
        if nova_fase or printar:
            print('-'*30)
            print(f'removidas: {removidas} {len(removidas)} \nlista atual: {cards} {len(cards)}')
            nova_fase = False
    print('-'*30)

trowing_literal(8)

#JEITO MAIS COMPLEXO PORÉM MAIS EFICIENTE (na real nem sei se seria tanto assim, já que popleft com deque é bem eficiente, esse aq talvez seja mais demorado se pá)
def trowing_formula (number):
    removidas = []
    turno = 1
    while len(removidas)!=number-1:
        if (number-len(removidas))%2==0:
            for i in range(1*turno, number, 2*turno):
                removidas.append(i)
                print(removidas)
        turno += 1
    print(removidas)

trowing_formula(16)
