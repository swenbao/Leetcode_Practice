# 
#   Created by 筍包 on 2023/11/27.
#   nested for in range()

#   Runtime ~= 4500ms
#   Time : O(n^2)
#   Space: O(1)

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        i = 0
        while i < len(nums):
            j = i+1
            while j < len(nums):
                if nums[i]+nums[j]==target:
                    return [i, j]
                j+=1
            i+=1

# This is way slower than the nested for i in range()

# chatGPT : 
#   is similar to slowBrute.py but uses while loops, 
#   which can be slightly less efficient due to manual index management and incrementation,
#   possibly leading to more overhead compared to the for loop construct.