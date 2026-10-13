import sys
from collections import deque

n, k = map(int, sys.stdin.readline().split())
flores = deque(map(int, sys.stdin.readline().split()))

def soma_digitos(num):
    soma = 0
    for i in (str(num)):
        soma += int(i)
    return soma

for _ in range(k):
        coleta = soma_digitos(flores[0])
        flores[0] -= coleta
        if flores[0] == 0:
            flores.popleft()
        else:
            flores = deque(sorted(flores, reverse=True))
print(coleta)



