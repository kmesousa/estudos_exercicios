#ACEITO

import sys

n, h = map(int, input().split())
linhas = list(map(int, input().split()))

contador = 0
for i in linhas:
    if i <= h:
        contador += 1

print(contador)