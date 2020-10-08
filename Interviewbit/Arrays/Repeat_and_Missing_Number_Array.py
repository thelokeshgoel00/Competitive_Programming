class Solution:
    # @param A : tuple of integers
    # @return a list of integers
    def repeatedNumber(self, A):
        seen = list(range(len(A) + 1))
        a = 0
        b = 0
        
        for elem in A:
            if seen[elem] != 0:
                seen[elem] = 0
            else:
                a = elem
                
        for elem in seen:
            if elem != 0:
                b = elem
        return [a, b]