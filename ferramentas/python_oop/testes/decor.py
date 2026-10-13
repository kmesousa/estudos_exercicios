def meu_decorador(func):
    def wrapper(*args, **kwargs):
        print("Antes de executar a função.")
        resultado = func(*args, **kwargs)
        print("Depois de executar a função.")
        return resultado
    return wrapper

@meu_decorador
def somar(a, b):
    return a + b

print(somar(2, 3))


def minha_funcao(*args, **kwargs):
    print("args:", args)
    print("kwargs:", kwargs)

minha_funcao(1, 2, 3, nome="Ana", idade=25)

def f(*args, **kwargs):
    print(args, kwargs)
    print(sum(args))

f(1, 2, nome="Ana")     # (1, 2) {'nome': 'Ana'}
f(*[3, 4], **{"x": 5})  # (3, 4) {'x': 5}
