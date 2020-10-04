class Solution:
#@param A : list of integers
#@ return a list of integers
    def plusOne(self, A):
        a = list(map(lambda a: str(a), A))
        b = int(''.join(a))
        c = [i for i in str(b + 1)]
        result = list(map(lambda a: int(a), c))
        return result