'''move zeros to the end
in place

001 >> 100

0100234 >> 123400

0 1 0 0 2 3 4
1 1
  i
    j


0 1 1 0
1 1 1 0 0
    i
      j

0 0 1 0 3 24 0 0
1 3 24
      i
                  j

1 2
i
  j

1 0 1
i
  j

1 2 3 0
i
  j

1 2 3
i
  j

0 1 1 0 0
1 1 1 0 0
    i
      j

'''

def move_zeros(nums):
    i = 0
    j = i + 1
    s = False
    m = False

    while j < len(nums):
        #print('a', nums, nums[i], j, s)
        if nums[i]==0:
            if nums[j]!=0:
                nums[i]=nums[j]
                i += 1
                s = True
                m = True
        elif nums[i]!=0:
            if (j+1<=len(nums) or nums[j]!=0) and not s:
                i += 1
            elif nums[j]!=0 and s:
                nums[i]=nums[j]
                i += 1
                s = False
                m = True
        j += 1
    while m and i<len(nums):
        #print('b', nums, nums[i], j)
        nums[i]=0
        i +=1
    return nums

def move_zeros(nums):
    i = 0
    j = i+1
    s = False
    m = False

    while j < len(nums):
        #print(f'a {nums} i[{i}]:{nums[i]} j[{j}]:{nums[j]}')
        # if nums[j]==0:
        #     j+=1
        if nums[i]!=0 and not s :
            i += 1
        elif nums[j]!=0:
            nums[i]=nums[j]
            i +=1
            m = True
            s = not s
        # elif nums[j]==0 and not s:
        #     i += 1
        j +=1

    while m and i < len(nums):
        nums[i]=0
        i +=1

    return nums
print(move_zeros([0,1,0,0,2,3,4]))
print(move_zeros([0,1,0,3,12]))
print(move_zeros([0,0,1]))
print(move_zeros([0]))
print(move_zeros([1]))
print(move_zeros([1,0]))
print(move_zeros([0,1]))
print(move_zeros([1,0,1]))
print(move_zeros([0,1,1,0]))
print(move_zeros([1,2]))