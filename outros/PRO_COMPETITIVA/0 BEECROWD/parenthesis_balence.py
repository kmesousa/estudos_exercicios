import sys

def parenthesis_check (exp):
    counter = 0
    for i in range(len(exp)):
        if exp[i]=="(":
            counter += 1
        elif exp[i]==")":
            counter -= 1

        if counter < 0:
            return False

    return counter==0

## for beecrowd input format
# linhas = sys.stdin.read().splitlines()

# for linha in linhas:
#     if not linha: #pular se for uma linha em branco
#         continue
#     if parenthesis_check(linha):
#         print("correct")
#     else:
#         print("incorret")


parenthesis_check("a+(b*c)-2-a")
parenthesis_check("(a+b*(2-c)-2+a)*2")
parenthesis_check("(a*b-(2+c)")
parenthesis_check("2*(3-a))")
parenthesis_check(")3+b*(2-c)(")