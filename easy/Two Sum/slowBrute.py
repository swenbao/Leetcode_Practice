# 
#   Created by 筍包 on 2023/11/27.
#   nested for in range()

#   Runtime ~= 2500ms
#   Time : O(n^2)
#   Space: O(1)

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                if nums[i]+nums[j]==target:
                    return [i, j]

# I guess python optimized nested for i in range()

# chatGPT :  
#   uses nested for loops to check each pair of elements explicitly,
#   which is less efficient than the `in` operator because it's implemented directly in Python, 
#   making it inherently slower due to the language's higher-level nature.