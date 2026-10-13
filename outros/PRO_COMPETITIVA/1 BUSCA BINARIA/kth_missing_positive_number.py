#https://leetcode.com/problems/kth-missing-positive-number/description/
#me explique claude: https://claude.ai/chat/cdd8f73f-2a03-4630-986a-6e39d5efbb4f

#força bruta
def findKthPositive(arr: list[int], k: int) -> int:
    test = 1
    miss = 1

    while miss<=k:
        if test not in arr:
            miss += 1
        test += 1
    return test-1

assert(findKthPositive([2,3,4,7,11],5))==9
assert(findKthPositive([1,2,3,4],2))==6

#com busca binária
def findKthPositive(arr: list[int], k: int) -> int:
    #howwww im so lazy goddammit

    left = 0
    right = len(arr) - 1

    def faltantes(idx):
        return arr[idx] - (idx + 1)

    if  k <= faltantes(left): #faltantes(0) >= k:
        return k

    elif k > faltantes(right): #faltantes(right) < k:
        return arr[right] + k - faltantes(right)

    else:
        while left <= right:
            mid = (left + right)//2
            #tem q achar o ultimo q tem como faltantes uma qte menor que K

            if faltantes(mid)>=k:
                right = mid - 1
            else:
                left = mid + 1
                if faltantes(left) >=k: #poderia usar isso como parametro do while?
                    break
        idx = left - 1

    return arr[idx] + k - faltantes(idx)
    ''' ou return left + k
    faltantes(idx) = arr[idx] - (idx + 1)
    return arr[idx] + k - arr[idx] + (idx + 1)
    return k + (idx + 1)
    idx = left - 1
    return k + (left - 1 + 1)
    return k + left
    '''


print(findKthPositive([1,10,21,22,25], 12))
print(findKthPositive([2,3,4,7,11], 5))
print(findKthPositive([1,2,3,4], 2))
'''
   def findKthPositive(self, arr: List[int], k: int) -> int:
        tamanho = len(arr)-1
        left = 0
        right = tamanho
        mid = 0

        while left <= right:
            mid = (left + right)//2
            indice = mid+1

            if arr[mid]-indice < k:
                left = mid + 1

            else:
                right = mid - 1
        if left == 0  and arr[0]!=1:
            return k
        else:
            return k+left
'''