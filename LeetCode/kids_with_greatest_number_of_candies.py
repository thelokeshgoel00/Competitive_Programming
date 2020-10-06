"""
https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
"""


class Solution:
    @staticmethod
    def kids_with_candies(candies: [], extra_candies: int) -> [bool]:
        m = max(candies)
        n = len(candies)
        for i in range(n):
            if candies[i] + extra_candies >= m:
                candies[i] = True
            else:
                candies[i] = False
        return candies


"""
Input: candies = [2,3,5,1,3], extraCandies = 3
Output: [true,true,true,false,true]

Input: candies = [4,2,1,1,2], extraCandies = 1
Output: [true,false,false,false,false]

Input: candies = [12,1,12], extraCandies = 10
Output: [true,false,true]
"""
