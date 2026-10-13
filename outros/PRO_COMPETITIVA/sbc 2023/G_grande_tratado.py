import sys
from collections import deque

def reinos_infinitos():
    num_de_reinos = int(input())

    # if num_de_reinos <= 4:
    #     for i in range(1, num_de_reinos + 1):
    #         print(i, end=' ')
    #     return

    x, y = map(int, input().split())

    dict_coord = {
        'maior_x': [x, [1]],
        'menor_x': [x, [1]],
        'maior_y': [y, [1]],
        'menor_y': [y, [1]]
    }

    lista_final = deque(1)

    #descobrir
    for id in range(num_de_reinos):

        x, y = map(int, sys.stdin.readline().split())

        if x >= dict_coord['maior_x'][0]:
            if x > dict_coord['maior_x'][0]:
                dict_coord['maior_x'][1].clear()
                dict_coord['maior_x'][0] = x
            dict_coord['maior_x'][1].append(id + 2)

        elif x <= dict_coord['menor_x'][0]:
            if x < dict_coord['menor_x'][0]:
                dict_coord['menor_x'][1].clear()
                dict_coord['menor_x'][0] = x
            dict_coord['menor_x'][1].append(id + 2)

        if y >= dict_coord['maior_y'][0]:
            if y > dict_coord['maior_y'][0]:
                dict_coord['maior_y'][1].clear()
                dict_coord['maior_y'][0] = y
            dict_coord['maior_y'][1].append(id + 2)

        elif y <= dict_coord['menor_y'][0]:
            if y < dict_coord['menor_y'][0]:
                dict_coord['menor_y'][1].clear()
                dict_coord['menor_y'][0] = y
            dict_coord['menor_y'][1].append(id + 2)

    print(' '.join(lista_final))

reinos_infinitos()
