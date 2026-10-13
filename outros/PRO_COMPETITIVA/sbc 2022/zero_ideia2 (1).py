import sys

quant_cartas = int(sys.stdin.readline().strip())
cartas_frente = list(map(int, sys.stdin.readline().split()))
cartas_verso = list(map(int, sys.stdin.readline().split()))
qnt_escolhidas, qnt_viradas = map(int, sys.stdin.readline().split())

def pontuacao_carta(c_f, c_v, qnt_e, qnt_v):
    right = quant_cartas
    left = 0
    soma = 0
    v_verso = 0
    contador = 0

    while left < right and contador < qnt_e:
        if (c_f[left] + c_v[left]) >= (c_f[right-1] + c_v[right-1]) :
            soma += c_f[left]
            if v_verso < c_v[left]:
                v_verso = c_v[left]
            left +=1
            contador += 1
        else:
            soma += c_f[right - 1]
            if v_verso < c_v[right - 1]:
                v_verso = c_v[right - 1]
            right -=1
            contador += 1

    soma += v_verso

    return soma


print(pontuacao_carta(cartas_frente, cartas_verso, qnt_escolhidas, qnt_viradas))