"""
https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/
"""
from itertools import combinations


class Solution:
    @staticmethod
    def combination_possible(n, combination) -> bool:
        in_degree = [0] * n
        out_degree = [0] * n
        for node in combination:
            out_degree[node[0]] += 1
            in_degree[node[1]] += 1
        # print(combination, in_degree, out_degree)
        return in_degree == out_degree

    @staticmethod
    def maximum_requests(n: int, requests: [[int]]) -> int:
        maximum_requests = 0
        for requestsIncluded in range(1, len(requests) + 1):
            for combination in list(combinations(requests, requestsIncluded)):
                if Solution.combination_possible(n, combination):
                    maximum_requests = requestsIncluded
                    continue
        return maximum_requests


"""
Input: n = 5, requests = [[0,1],[1,0],[0,1],[1,2],[2,0],[3,4]]
Output: 5

Input: n = 3, requests = [[0,0],[1,2],[2,1]]
Output: 3

Input: n = 4, requests = [[0,3],[3,1],[1,2],[2,0]]
Output: 4
"""
