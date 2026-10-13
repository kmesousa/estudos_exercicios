'''
pesquisa de quantos alunos por turma numa escola gostam de determinada fruta

- cada turma tem pelo menos 1 aluno
- cada aluno gosta de pelo menos 1 fruta
- cada aluno pertence a uma única fruta

primeira linha número N (número de frutas) e M (número de turmas)
próximas N linhas: M números inteiro Gij indicando quantos alunos da turma j gostam da fruta i

obs: M e N >= 1 e <= 1000, i e j >= 1 e <= N e M


exemplos

entrada
1 1
10

saida = 10

entrada
1 2
10 3

saída = 13

entrada
2 1
10
7

saída = 10

'''

def solucao(matriz):
    qte_turmas = matriz[0][1] #colunas
    qte_frutas = matriz[0][0] #linhas

    total_alunos = 0

    for j in range(qte_turmas):
        maior = 0
        for i in range(1, qte_frutas):
            if matriz[i][j] > maior:
                maior = matriz[i][j]
        total_alunos += maior