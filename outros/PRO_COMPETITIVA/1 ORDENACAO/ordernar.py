def ordenar2 (n1:float, n2:float):
    if n2 <= n1:
        n1, n2 = n2, n1

    return n1,n2

print(ordenar2(9,7))

def ordenar3 (n1,n2,n3):

    n1, n2 = ordenar2(n1,n2)
    n2, n3= ordenar2(n2,n3)
    n1, n2 = ordenar2(n1,n2)

    return n1, n2, n3

print(ordenar3(90, 10, 14))

def ordenarX (numeros:list) -> list:
    pass