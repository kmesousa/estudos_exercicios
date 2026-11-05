def meu_decorador(func):
    def wrapper(*args, **kwargs):
        print("Antes de executar a função.")
        resultado = func(*args, **kwargs)
        print("Depois de executar a função.")
        return resultado
    return wrapper

def decorador_errado(func):
    print("Antes de executar a função.")
    resultado = func()
    print("Depois de executar a função.")
    return resultado

@meu_decorador
def somar(a, b):
    print(f"Somando {a} + {b}")
    return a + b

@decorador_errado
def mensagem():
    print("Olá, mundo!")
    return "Mensagem enviada."

@meu_decorador
def mensgaem2():
    print("Olá, mundo!")
    return "Mensagem enviada."

print(somar(2, 3))


msg = mensagem
print(msg)
#print(mensagem()) da erro [ pq o decorador errado não retorna uma função, ele retorna o resultado da função decorada, então a função mensagem não existe mais, ela foi substituída pelo resultado da função. ] 

print(mensgaem2())

#----------------------------------------
#             ARGS E KWARGS
#----------------------------------------

def criar_funcao(*args, **kwargs):
    print("args:", args) #O *args é usado para receber uma quantidade variável de argumentos sem a palavra-chave (keyword) na função. 
    print("kwargs:", kwargs) #O **kwargs é usado para receber uma quantidade variável de argumentos com a palavra-chave (keyword) na função.

def funcao_completa(a, b, *args, key1, key2="default", **kwargs):
    print(f"Posicionais obrigatórios: {a}, {b}")
    print(f"Args extras: {args}")
    print(f"Keyword obrigatório: {key1}")
    print(f"Keyword com padrão: {key2}")
    print(f"Kwargs extras: {kwargs}")

funcao1234 = funcao_completa(1, 2, 3, 4, key1="val1", key3="val3", key4="val4")

def separar_args_kwargs(*args, **kwargs):
    print("args:", args)
    print("kwargs:", kwargs)
    print("Soma dos números:", sum(i for i in args if isinstance(i, (int, float))))

funcao_ana = criar_funcao(1, 2, 3, nome="Ana", idade=25)
separar_args_kwargs(funcao_ana)     # (1, 2) {'nome': 'Ana'}

separar_args_kwargs(*[3, 4], **{"x": 5})  # (3, 4) {'x': 5}

#----------------------------------------
#             ARGS E KWARGS COM DECORATOR
#----------------------------------------

import functools

def analisar_funcao(func): #pega a função como argumento 
    #@functools.wraps(func)
    def wrapper(*args, **kwargs): #pega os argumentos e palavras-chave da função
        print(f"Analisando a função: {func.__name__}".upper()) #pegou o nome do wrapper, pq? 
        print("args:", args)
        print("kwargs:", kwargs)
        resultado = func(*args, **kwargs)
        print(f"Resultado da função: {resultado}\n")
        return resultado
    return wrapper

def calcular_duracao(func):
    # def wrapper(): #esse tipo só daria certo se a função não tivesse argumentos
    #     import time
    #     inicio = time.time()
    #     func()
    #     duracao = time.time() - inicio
    #     print(f"Duração da função {func.__name__}: {duracao:.6f} segundos")
    # return wrapper

    @functools.wraps(func)
    def wrapper(*args, **kwargs):
        import time
        inicio = time.time()
        resultado = func(*args, **kwargs)
        duracao = time.time() - inicio
        print(f"Duração da função {func.__name__}: {duracao:.6f} segundos\n")
        return resultado
    return wrapper

    def wrapper(*args, **kwargs): #sem receber o resultado da função decorrada
        import time
        inicio = time.time()
        func(*args, **kwargs)
        duracao = time.time() - inicio
        print(f"Duração da função {func.__name__}: {duracao:.6f} segundos")
    return wrapper


@analisar_funcao #nome da função = wrapper
@calcular_duracao
def multiplicar(a, b):
    return a * b

# @calcular_duracao #nome da função = multiplicar
# @analisar_funcao 
# def multiplicar(a, b):
#     return a * b

print(multiplicar(4, 5))
resultado = multiplicar(4, 5)
print(f"Resultado da multiplicação: {resultado}")
