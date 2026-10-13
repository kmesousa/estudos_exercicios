import sys

n = int(sys.stdin.readline().strip())
letras = sys.stdin.readline().strip()

contador = 0

eh_a = False
eh_seq = False

#com variáveis de controle
for i in letras:
    if i=="a":
        if eh_a: #quando já teve A antes
            contador += 1
            eh_seq = True
        else: #quando é o primeiro A
            eh_a = True
    else:
        if eh_seq:
            eh_seq = False
            contador += 1
        eh_a = False

if eh_a and eh_seq:
    contador += 1

print(contador)

#com two pointers
contador = 0
i, j = 0, 1
while j < n:
    if letras[i]=="a" and letras[j]=="a":
        contador += 1
        while letras[j]=="a":
            contador += 1
            j += 1
        j += 1
    elif letras[j]=="a":
        i = j
        j += 1
    else:
        j += 1