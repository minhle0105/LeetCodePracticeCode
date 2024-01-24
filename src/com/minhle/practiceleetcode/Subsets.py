class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
        current = []
        res.append([])
        self.backtracking(res, current, nums, 0)
        return res
    

    def backtracking(self, res, current, nums, index):
        if index == len(nums):
            return
        for i in range(index, len(nums)):
            current.append(nums[i])
            res.append(current)
            self.backtracking(res, current, nums, i + 1)
            current.pop()
