def isStringPermutation(s1, s2):
    if len(s1) != len(s2):
        return False
    s = set(s1)
    for c in s2:
        if c not in s:
            return False
    return True

print isStringPermutation("hello", "olhle")


#TO DO: Fix this fxn to not repeat pairs
def pairsThatEqualSum(arr, targetSum):
    ret = []
    #O(n) operation
    s = set(arr);
    #O(n) loop
    for num in arr:
        # O(1) lookup
        if (targetSum - num) in s:
            ret.append((num, targetSum - num))
    return ret


ans = pairsThatEqualSum([0, 1, 2, 3, 4, 5], 5)
for k in ans:
    print k
        
#expected: (0,5), (1,4), (2,3)
#actual: (0,5), (1,4), (2,3), (3,2), (4,1), (5,0)        
