#ACEITA 62 ms

import sys
from collections import deque

#1 ler a primeira linha e armazenar valores em variaveis

disposicao, qte_c, qte_r= map(int, sys.stdin.readline().split())

#2 criar variavel para armazenar qtes atvds serao realizadas, todas as revigorantes serão realizadas obrigatoriamente

contador = qte_r

#3 criar as listas das atividades cansativas

c = deque()

for _ in range(qte_c):
    c.append(int(sys.stdin.readline().strip()))

for _ in range(qte_r):
    #r.append(int(input()))
    disposicao += int(sys.stdin.readline().strip())

# 4 resolver

while c: #realizar cansativas enquanto puder

    if disposicao >= c[0]:
        contador += 1
        disposicao -= c[0]
        c.popleft()

    else:
        break

print(contador)

# COMO FAZER ISSO COM BUSCA BINÁRIA??

