import sys

n = int(sys.stdin.readline().strip())
baloes = list(map(int,sys.stdin.readline().split()))

qte_flechas = 1
sequencias = [baloes[0]]

for i in range(1, n):
    altura_balao = baloes[i]

    #procuar com busca binaria se tem 1 maior
    add = True
    left, right = 0, qte_flechas - 1
    target = altura_balao + 1

    if not(sequencias[left] > target and sequencias[right] < target):
        while left <= right:
            mid = (left + right)//2
            if sequencias[mid] == target:
                add = False
                sequencias[mid] = altura_balao
                sequencias.sort()
                break
            elif target > sequencias[mid]:
                left = mid + 1
            else:
                right = mid - 1
    if add:
        sequencias.append(altura_balao)
        sequencias.sort()
        qte_flechas += 1

print(qte_flechas)