class gerar_binarios():
    def __init__(self, qte_digitos):
        self.qte_digitos = qte_digitos

    #forma mais GENERALISTA, com recursão (lógica usada em outros problemas)

    #minha tentativa sozinha
    def recursao_string(self):
        qte_digitos = self.qte_digitos
        atual = ''
        def backtrack(binario):
            if len(binario)==qte_digitos:
                print(binario)
                return
            backtrack(binario + '0')
            backtrack(binario + '1')

        backtrack(atual + '0')
        backtrack(atual + '1')

    #mais resumido
    def recursao_string(self, atual=''):
        qte_digitos = self.qte_digitos
        if len(atual)==qte_digitos:
            print(atual)
            return
        self.recursao(atual + '0')
        self.recursao(atual + '1')
    #entendi finalmente ebaaa

    #com lista
    def recursao(self, atual=None):
        qte_digitos = self.qte_digitos

        if atual is None:
            atual = []

        if len(atual) == qte_digitos:
            print(atual)
            return

        atual.append(0)
        self.recursao(qte_digitos, atual)
        atual.pop()

        atual.append(1)
        self.recursao(qte_digitos, atual)
        atual.pop()

    #versao do claude, melhor pq retorna uma lista com todos os resultados (apesar de ser facil adicionar isso na anterior)
    def recursao2(self):
        qte_digitos = self.qte_digitos

        resultado = []
        atual = []

        def backtrack(pos):
            print(pos, atual)
            if pos == qte_digitos:
                resultado.append(atual.copy())
                return
            for valor in (0, 1):
                atual.append(valor)
                backtrack(pos + 1)
                atual.pop()

        backtrack(0)

        for i in range(len(resultado)):
            print(f'{resultado[i]}')
        return resultado

    #forma mais  EFICIENTE, com iterações (mais específica para esse problema)
    def iteracao (self):
        qte_digitos = self.qte_digitos
        qte_binarios = 2 **(qte_digitos)

        resultado = [[] for _ in range(qte_binarios)]

        for i in range(qte_digitos): #definir critério
            qte_blocos = 2**(i+1)
            tam_bloco = qte_binarios//qte_blocos

            for j in range(qte_binarios): #aplicar critério para a posição atual
                resultado[j].append((j // tam_bloco) % 2)

        for i in range(len(resultado)):
            print(f'{resultado[i]}')
        return resultado

print('iteração'.upper().center(50, '='))
for i in [3,4,5]:
    gerar_binarios(i).iteracao()

print('recursão'.upper().center(50, '='))
for i in [3,4,5, 2]:
    gerar_binarios(i).recursao()