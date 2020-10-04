class Solution:
    # @param A : tuple of integers
    # @return an integer
    def repeatedNumber(self, A):
        bucket = dict()
        repeat = -1
        for i in range(len(A)):
            repeat = A[i]
            try:
                bucket[str(A[i])].append(i)
                break
            except:
                bucket[str(A[i])] = [i]
                
        return repeat