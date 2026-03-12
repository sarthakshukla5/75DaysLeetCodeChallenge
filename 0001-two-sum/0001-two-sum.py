class Solution:
    def twoSum(self, nums, target):
        d = {}

        for i in range(len(nums)):
            x = nums[i]
            y = target - x

            if y in d:
                return [d[y], i]

            d[x] = i