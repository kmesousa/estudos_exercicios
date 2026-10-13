def print_sudoku(matrix):
    '''
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
    '''
    det = 3 #sudoku 3 x 3, poderia tirar a raiz quadrada para descobrir, mas vamos desconsiderar por enquanto para evitar impressisões
    for x in range(det):
        n = 0
        for i in range(det):
            for j in range(n,det+n):
                print(matrix[i][j], end='')
        print('')
        n +=3

    #AH eu tava fazendo isso pensando que cada lista era pra ser um bloco, mas na vdd cada lista é uma linha msm, é mais simples doq eu pensei ent esquece isso
# print_sudoku([["5","3",".",".","7",".",".",".","."]
        #     ,["6",".",".","1","9","5",".",".","."]
        #     ,[".","9","8",".",".",".",".","6","."]
        #     ,["8",".",".",".","6",".",".",".","3"]
        #     ,["4",".",".","8",".","3",".",".","1"]
        #     ,["7",".",".",".","2",".",".",".","6"]
        #     ,[".","6",".",".",".",".","2","8","."]
        #     ,[".",".",".","4","1","9",".",".","5"]
        #     ,[".",".",".",".","8",".",".","7","9"]])
        '''vai itinerando cada linha aaaaaaaaaaaaaaa'''

def validar_sudoku(sudoku):
    m=1
    for li in range(len(sudoku[0])): #percorre cada linha
        n=1
        for col in range(len(sudoku)): #percorre cada coluna/ elemento da linha
            if sudoku[li][col]!='.':
                print(sudoku[li][col], li, col)
                for c in range(n, len(sudoku)): #compara o elemento atual com cada elemento da mesma linha
                    if sudoku[li][col]==sudoku[li][c]:
                        print(sudoku[li][col], li, col, sudoku[li][c], li, c)
                        return False
                for l in range(m, len(sudoku)): #compara o elemento atual com cada elemento da mesma coluna
                    if sudoku[li][col]==sudoku[l][col]:
                        print(sudoku[li][col], li, col, sudoku[l][col], l, col)
                        return False
                #falta comparar o elemento com cada elemento de seu mesmo bloco
                p = 2 - li%3 #li%3 = 0, 1 ou 2, linhas que vai ter que olhar >> 2, 1 ou 0, respectivamente
                for l in range(li+1, li+p+1):
                    match col%3:
                        case 0: #vai ollhar para as duas colunas seguintes
                            for c in range(col+1,col+3):
                                if sudoku[li][col]==sudoku[l][c]:
                                    return False
                        case 1: #vai olhar a coluna anterior e a coluna seguinte
                            for c in range(col-1, col+3, 2):
                                if sudoku[li][col]==sudoku[l][c]:
                                    return False
                        case 2: #vai olhar as duas colunas anteriores
                            for c in range(col-2, col):
                                if sudoku[li][col]==sudoku[l][c]:
                                    return False
            n+=1
        m+=1
    return True

print(validar_sudoku(
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]))

print(validar_sudoku(
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]))
