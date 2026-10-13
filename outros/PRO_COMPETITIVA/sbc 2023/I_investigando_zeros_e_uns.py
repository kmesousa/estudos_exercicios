import sys
from collections import deque

num_bits = sys.stdin.readline().strip()
vetor = sys.stdin.readline().split()

contador = 0
impar = False
zeros_entre = 0

for i in range(num_bits):
    if vetor[i] == 0:
        zeros_entre += 1
    elif vetor[i] == 1:
        impar = not(impar)
        zeros_entre = 0

#mds isso parece mt difícil