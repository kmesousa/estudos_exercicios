#https://judge.beecrowd.com/en/problems/view/1258

'''
recebe:
nome do aluno
cor tamanho

retorna:
cor tamanho nome do aluno
'''

import sys

lines = sys.stdin.read().splitlines()

idx = 0
peso = {'P': 1, 'M': 2, 'G': 3}

while not int(lines[idx])==0: #usar o int nao vai dar erro, pq o idx aq sempre será de um num

    #criar espaço caso nao seja a primeira lista
    if idx>0:
        print()

    pedidos = [] #receber a "leva" de pedidos atual
    N = int(lines[idx]) #quantidade de pedidos da "leva" atual

    for i in range(idx+2, idx+2+N*2, 2): #passar pelas linhas da cor e tam, abaixo do nome
        cor, tam = lines[i].split()
        nome = lines[i-1]
        pedidos.append((cor, tam, nome))

    #ordenar lista 1 cor (alfabetico) 2 tamanho (P M G) 3 nome (alfabetico)
    sorted_pedidos = sorted(pedidos, key= lambda x: (x[0], peso[x[1]], x[2]))

    #imprimir
    for cor, tam, nome in sorted_pedidos:
        print(f'{cor} {tam} {nome}')

    #pegar o idx da proxima linha, que contem o numero de pedidos da proxima leva
    idx = i+1 #ou N*2+2

''' resposta do salles
# Lê todas as linhas da entrada
linhas = sys.stdin.read().splitlines()
idx = 0
primeiro = True
pesos = {'P': 1, 'M': 2, 'G': 3}

while idx < len(linhas):
    N = int(linhas[idx])
    if N == 0:
        break

    if not primeiro:
        print()
    primeiro = False

    pedidos = []
    for _ in range(N):
        nome = linhas[idx + 1]
        cor, tam = linhas[idx + 2].split()
        pedidos.append((cor, tam, nome))
        idx += 2
    idx += 1

    # Ordena por Cor, depois pelo Peso do tamanho, depois por Nome
    pedidos.sort(key=lambda x: (x[0], pesos[x[1]], x[2]))

    for cor, tam, nome in pedidos:
        print(f"{cor} {tam} {nome}")
'''