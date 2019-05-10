
def isStringPermutation(s1, s2):
    if len(s1) != len(s2):
        return False
    s = set(s1)
    for c in s2:
        if c not in s:
            return False
    return True

print isStringPermutation("hello", "olhle")
