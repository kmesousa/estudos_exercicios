import sys

linha = list(map(int, sys.stdin.readline().split()))

soma = sum(linha)

if soma > 8:
    print("F")
else:
    print("S")