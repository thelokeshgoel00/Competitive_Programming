class Solution:
    # @param A : tuple of integers
    # @return an integer
    def maxSubArray(self, A):
        best = A[0]
        current = A[0]
        for a in A:
            current = max(current + a, a)
            best = max(best, current)
        return best