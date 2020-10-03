class Solution:
    # @param A : list of integers
    # @return an integer
    def maxArr(self, A):
        max_i = A[0]
        min_i = A[0]
        max_j = A[0]
        min_j = A[0]
        for i in range(len(A)):
            max_i = max(max_i, A[i] + i)
            min_i = min(min_i, A[i] + i)
            max_j = max(max_j, A[i] - i)
            min_j = min(min_j, A[i] - i)
        
        return max(max_i - min_i, max_j - min_j)