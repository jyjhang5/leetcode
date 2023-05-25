from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for x in range(0, len(nums)):
            for y in range(x+1, len(nums)):
                if nums[x] + nums[y] == target:
                    return [x, y]
        return []

    def twoSum2(self, nums: List[int], target: int) -> List[int]:
        dict = {}
        for i, n in enumerate(nums):
            if n in dict:
                return [dict[n], i]
            else:
                dict[target - n] = i


# nums = [2,7,11,15]
# target = 9

# nums = [3,2,4]
nums = [3, 3]
target = 6

s = Solution()
print(s.twoSum2(nums, target))