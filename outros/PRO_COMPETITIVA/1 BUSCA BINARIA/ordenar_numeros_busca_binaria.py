#ordenar numeros utilizando busca binariaa
def ordenar_numeros(vetor:list, reverse=False): #como adaptar para funcionar tbm para ordenações decrescentes?
    sorted = [vetor[0]]
    for i in range(1, len(vetor)):
        left = 0
        right = len(vetor)
        mid = (left + right)//2
        while True:
            if vetor[i]==vetor[mid]:
                sorted.insert(mid, vetor[i])
                break
            elif vetor[i] < vetor[mid]:
                if vetor[i] <= vetor[left]:
                    sorted.insert(left, vetor[i])
                    break
                right = mid - 1
            elif vetor[i] > vetor[mid]:
                if vetor[i] >= vetor[right]:
                    sorted.insert(right, vetor[i])
                    break
                left = mid + 1
    return sorted

print(sorted([2, 3, 1, 1, 2, 4, 7, 6, 3]))
print(sorted([2, 3, 1, 1, 2, 4, 7, 6, 3, 2, 3, 1, 1, 2, 4, 7, 6, 3]))
#CARALHO DEU CERTO DE PRIMEIRA N ACREDITO PUTA QUE PARIU