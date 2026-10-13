
''' https://leetcode.com/problems/missing-number/description/
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
'''

class missing_number():
    def __init__(self, vetor: list[int]):
        self.vetor = vetor

#com pa (nem sei como seria isso, só ouvi joao rodrigo ou luis ou sla falando sobre eu acho???)
    def pa (self):
        N = len(self.vetor)
        soma_esperada = N * (N + 1) // 2
        soma_real = sum(self.vetor)
        return soma_esperada - soma_real

#com binary search
    def binary_search (self,ordenado=True):

        if not ordenado:
            aux = self.vetor[:]
            aux.sort()
        else:
            aux = self.vetor[:]

        left = 0
        right = len(aux) - 1

        while left <= right:
            mid = (left + right)//2
            if aux[mid] == mid:
                left = mid + 1
            else: #aux[mid] > mid
                right = mid -1
        return left

''' comparando as duas abordagens
                  Binary search (sua)                            PA (soma)
Precisa ordenar?            Sim                                   Não
Complexidade de tempo      O(n log n) (por causa do sort)         O(n)
Espaço extra              O(n)                                (cópia aux)O(1)
Ideia central Encontrar o índice onde valor != índiceDiferença entre soma teórica e soma real

se o vetor já estivesse ordenado:
Complexidade de tempo: O(log n)
Espaço extra: O(1)

Conclusão: nesse cenário (array já ordenado), a binary search passa a ser estritamente melhor que a solução por PA — O(log n) contra O(n) de tempo, com o mesmo O(1) de espaço. É um bom exemplo de como a "melhor" solução depende muito da pré-condição dos dados: sem ordenação prévia, a PA ganha; com ordenação prévia (de graça), a busca binária ganha.
'''