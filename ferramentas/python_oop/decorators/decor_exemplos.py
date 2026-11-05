import functools
import logging

logging.basicConfig(level=logging.INFO)

def log_execution(func):
    """Decorator que loga entrada e saída de funções"""
    @functools.wraps(func)
    def wrapper(*args, **kwargs):
        logging.info(f"Executando {func.__name__} com args={args}, kwargs={kwargs}")
        result = func(*args, **kwargs)
        logging.info(f"{func.__name__} retornou: {result}")
        return result
    return wrapper

@log_execution
def calcular_preco(produto, quantidade, desconto=0):
    return produto['preco'] * quantidade * (1 - desconto)

# Uso
produto = {'nome': 'Notebook', 'preco': 2500}
total = calcular_preco(produto, 2, desconto=0.1)
# INFO:root:Executando calcular_preco com args=(...), kwargs={'desconto': 0.1}
# INFO:root:calcular_preco retornou: 4500.0

#fazer sem os imports? parece bem possível