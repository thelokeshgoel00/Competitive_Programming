class Solution:
    # @param A : tuple of integers
    # @return an integer
    def maximumGap(self, A):
        a = list(A)
        n = len(a)
        diff = 0
        
        a.sort()
        
        if n < 2:
            return 0
        
        for i in range(1, n):
            if i == 1:
                result = a[1] - a[0]
            else:
                diff = a[i] - a[i-1]
                if result < diff:
                    result = diff
        
        return result