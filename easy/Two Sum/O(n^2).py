# 
#   try.py
#   Created by 筍包 on 2023/11/24.

# code 很少，但超慢
# run time : 500ms 左右


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            complement = target - nums[i]
            if (complement in nums) and (nums.index(complement) != i):
                return [i, nums.index(complement)]
            
# complement in nums => O(n)
# nums.index(complement) => O(n)
# they are nested under the for loop 
# So the total time complxity => O(n^2)