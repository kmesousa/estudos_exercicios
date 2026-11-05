REGISTERED_FUNCTIONS = []

def register (func):
    def wrapper(*args, **kwargs):
        print(f"Registrando a função: {func.__name__}")
        REGISTERED_FUNCTIONS.append(func)
        print(f"Funções registrada: {func.__name__}")
        #print(f"Funções registradas: {[f.__name__ for f in REGISTERED_FUNCTIONS]}")
        return func(*args, **kwargs)
    return wrapper


@register
def my_function() -> None:
    print("funcao executada")

@register
def another_function(msg:str) -> str:
    print("outra funcao executada")
    return f"Mensagem recebida: {msg}"

print(f"Funções registradas: {[f.__name__ for f in REGISTERED_FUNCTIONS]}")

my_function()  # Executa a função decorada
another_function("Olá!")  # Executa a função decorada

print(f"Funções registradas: {[f.__name__ for f in REGISTERED_FUNCTIONS]}") #só entra no registro dps de ser execultada