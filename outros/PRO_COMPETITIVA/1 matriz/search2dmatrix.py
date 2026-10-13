def search_2d (matrix, target) -> bool:
    '''
    https://leetcode.com/problems/search-a-2d-matrix/description/
    1 4 7 9
    11 13 15 17
    21 35 67 81

    proximo elemento da mesma linha é sempre maior que o anterior
    primeiro elemento da próxima linha é sempre maior que o ultimo da anterior


        [[1,3,5,7],[10,11,16,20],[23,30,34,60]] >> True

    matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13 >> False

    '''
    linhas = len(matrix)
    colunas = len(matrix[0])
    inicio = 0
    fim = linhas*colunas - 1

    mid = (inicio+fim)//2