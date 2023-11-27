# 
#   Created by 筍包 on 2023/11/24.
#   code 很少，但慢
#   run time : 500ms 左右

#   Time : O(n^1.5) ?????
#   Space: O(1) ????? 


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            complement = target - nums[i]
            if (complement in nums) and (nums.index(complement) != i):
                return [i, nums.index(complement)]
            
# complement in nums => O(n) ?? maybe had been optmized
# nums.index(complement) => O(n) ?? maybe had been optmized
# they are nested under the for loop 
# So the total time complxity => O(n^2) ?? O(n^1.5)

# chatGPT :
#   time complexity of O(n^2) in the worst case 
#   because `complement in nums`` is an O(n) operation that is performed for each element in nums.
#   the `in` operator, which is O(n) on average for lists​​. 
#   However, it's optimized in C and can be faster than a Python for loop.
#   The index() method, also O(n), then finds the position of the complement.