import sys

# Lê o total de números
N = int(sys.stdin.readline())

numeros = []
for _ in range(N):
    numeros.append(int(sys.stdin.readline()))

# Ordena: os pares ganham prioridade 0 (vêm antes) e os ímpares ganham 1.
# O sinal de menos no -x inverte a ordem dos ímpares para decrescente.
numeros.sort(key=lambda x: (x % 2, x if x % 2 == 0 else -x))

# Imprime o resultado
for num in numeros:
    print(num)