"""
https://leetcode.com/problems/first-missing-positive/

Note: Your algorithm should run in O(n) time and uses constant extra space.
Approach: Adding a salt of 0.1 to each element I've manipulated (can also be made by making it negative
"""


class Solution:
    @staticmethod
    def first_missing_positive(nums: [int]) -> int:
        for num in nums:
            if 0 < int(num) <= len(nums):
                nums[int(num) - 1] += 0.1
        for i in range(len(nums)):
            if int(nums[i]) == nums[i]:
                return i + 1
        return len(nums) + 1


"""
Input: [1,2,0]
Output: 3

Input: [3,4,-1,1]
Output: 2

Input: [7,8,9,11,12]
Output: 1
"""
