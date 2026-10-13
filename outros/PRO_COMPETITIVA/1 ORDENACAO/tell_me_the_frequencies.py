#https://judge.beecrowd.com/en/problems/view/1251

'''
Given a line of text you will have to find out the frequencies of the ASCII characters present in it. The given lines will contain none of the first 32 or last 128 ASCII characters. Of course lines may end with ‘\n’ and ‘\r’ but always keep those out of consideration

Input
Several lines of text are given as input. Each line of text is considered as a single input. Maximum length of each line is 1000 characters.

Output
Print the ASCII value of the ASCII characters which are present and their frequency according to the given format below. A blank line should separate each set of output. Print the ASCII characters in the ascending order of their frequencies. If two characters are present the same time print the information of the ASCII character with higher ASCII value first. Input is terminated by end of file.


AAABCC
12233

PERGUNTA: os caracteres vão estar sempre em ordem como nos exemplos dados? isso muda muito no código

66 1
67 2
65 3

49 1
51 2
50 2
'''
def frequencies (exp:str):
    if not exp.strip():
        return

    dic = {}
    for i in exp:
        if ord(i) not in dic:
            dic[ord(i)] == 1
        else:
            dic[ord(i)] += 1

    valores = list(dic.values())
    chaves = list(dic.keys())

    #ordenar 1 aparições 2 id ascii
    sorted = [(chaves[0]), dic[chaves[i]]]

    #tentando fazer com busca binária mas mt dificil rip
    for i in range(1,len(chaves)):
        left = 0
        right = len(sorted)
        while left < right:
            mid = (left + right)//2
            if dic[chaves[i]] > sorted[mid][1]: #procurar onde tem aparição menor
                if dic[chaves[i]] > sorted[right-1][1]:
                    sorted.insert()
                    break
                left = mid + 1
            elif dic[chaves[i]] < sorted[mid][1]:
                if dic[chaves[i]] < left:
                    sorted.insert()
                    break
                right = mid - 1

'''como eu pensei em fazer:
criar uma lista original e uma lista ordenada vazia
ir adicionando os itens da original na vazia de acordo com onde ele deve se encaixar, começo, fim, meio, usando busca binária para determinar, primeiro de acordo com a aparição, depois de acordo com o número ascii
'''

#solução do salles
def frequencies (exp:str):
    from collections import Counter

    freq = Counter(exp) #contar a frequencia de cada caractere em um dicionário

    #ordenar: 1 frequencia 2 numero ascii
    sorted_chars = sorted(freq.items(), key=lambda x: (x[1], -ord(x[0]))) #nao entendo como esse lamba funciona, perguntar pro claude dps!!

    #imprimir
    for char, count in sorted_chars:
        print(f'{ord(char)} {count}')

#como o dict items funciona kme
dic = {
    'harrow': 17,
    'gideon': 18,
    'ianthe': 21,
}

print(dic.items()) #dict_items([('harrow', 17), ('gideon', 18), ('ianthe', 21)])
