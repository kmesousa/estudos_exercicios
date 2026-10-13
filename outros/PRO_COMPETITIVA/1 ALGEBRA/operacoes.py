def fat(number):
    #iterativa
    fat = 1

    for i in range(1, number+1):
        fat *= i
        # if i != number:
        #     print(f'{i} x ', end='')
        # else:
        #     print(f'{i}')
    return fat

    #recursiva

    if number == 0 or number ==1:
        return 1
    else:
        fat = number*fatorial(number-1)
        #print(fat)
    return fat

    #formula