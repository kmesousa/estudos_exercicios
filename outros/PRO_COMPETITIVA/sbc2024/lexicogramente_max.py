# 4
# 8 4 2 1

n = int(input())
nums = list(map(int, input().split()))

valores = [1]
for i in range(30):
    valores.append( valores[-1]*2 )

#print(valores)

contadores = [0]*31
for num in nums:
    index = 0
    valor = num
    while valor>0:
        if valor%2==1:
            contadores[index]+=1
        valor //= 2
        index+=1

saida = [0]*n
for index, contador in enumerate(contadores):
    for i in range(contador):
        saida[i] += valores[index]

print(*saida)