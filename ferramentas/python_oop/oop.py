class Pessoa:
    def __init__(self, nome:str, idade:int, dinheiro:int):
        self.nome = nome
        self.idade = idade
        self.dinheiro = dinheiro
    def __str__(self):
        print(f"nome: {self.nome}, idade: {self.idade}, dinheiro: {self.dinheiro}")
    def envelhecer(self):
        self.idade += 1
    def enriquecer (self):
        self.dinheiro += 10

class Politico(Pessoa):
    def enriquecer(self):
        self.dinheiro += 1000

kme = Pessoa("kme", 19, 2000)
kme.__str__()
kme.envelhecer()
kme.__str__()
