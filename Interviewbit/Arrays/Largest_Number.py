class Solution:
    # @param A : tuple of integers
    # @return a strings
    def largestNumber(self, A):
        result = sorted(map(str, A), key=lambda a: a * 2, reverse=True)
        if int(''.join(result)) == 0:
            return '0'
        return ''.join(result)