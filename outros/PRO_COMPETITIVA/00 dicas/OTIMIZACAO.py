#https://claude.ai/chat/6a8206b6-06c1-49c1-933f-1b69328e2632
'''cuidado com as aspas'''

import sys

#INPUT (input em python é devagar, usando o sys pode otimizar)

linha = input() #lê uma linha da entrada, excluindo \n
#Se o stdin acabar sem mais linhas, levanta EOFError

texto = sys.stdin.read() #lê o arquivo restante inteiro, preservando \n, espaços e etc
tokens = sys.stdin.read().split() #separa todos os elementos por espaços e linhas
linhas = sys.stdin.read().splitlines() #separa as linhas do texto, excluindo os \n
matriz = [linha.split() for linha in sys.stdin.read().splitlines()] #separa os tokens, preservando a organização das linhas (se quiser só a matriz direto, for linha in sys.stdin é mt melhor)

linha = sys.stdin.readline() #lê uma linha da entrada, preservando \n
linha = sys.stdin.readline().strip() #remove \n e espaços em branco
linhas = [sys.stdin.readline() for _ in sys.stdin]

linhas = sys.stdin.readlines() #ou list(sys.stdin) #lista todas as linhas restantes do arquivo, preservando \n
matriz = [linha.split() for linha in sys.stdin.readlines()] #separa os tokens, preservando organização das linhas (se quiser só a matriz direto, for linha in sys.stdin é mt melhor)

#sem carregar na memória
for linha in sys.stdin: #linha preserva \n, precisa de strip
    pass
matriz = [linha.split() for linha in sys.stdin]

#OUTPUT
resultado = 'resultado'
sys.stdout.write(f"{resultado}\n")

#RECURSÃO
sys.setrecursionlimit(10**6) #padrão do python é apenas ~1000

#FUNCAO MAP

lista_numeros = list(map(int, tokens))
matriz_numeros = [list(map(int, linha)) for linha in sys.stdin]

#OUTRAS BIBIOTECAS

'''
pop left é O(n) normalmente, o deque da biblioteca collections tem pop left com O(1)
'''

from collections import deque

teste_deque = deque(range(1, 10))
teste_deque = deque(lista_numeros)
teste_deque.popleft()


from collections import Counter

#basicamente cria um dicionário para ver quantos itens de cada tipo há em uma lista ou string

#It is a collection where elements are stored as dictionary keys and their counts are stored as dictionary values. Counts are allowed to be any integer value including zero or negative counts.

contagem = Counter(["ovo", "ovo", "banana", "ovo", "ovo", "banana"])

#SORT
''''''

#FUNÇÕES QUE PODEM SER UTEIS NSEI

def somar_digitos (num:float):
    soma = 0
    for i in str(num):
        if i.isdigit():
            soma += int(i)
    return soma