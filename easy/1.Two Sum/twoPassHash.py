# 
#   Created by 筍包 on 2023/11/24.

# time complexity: O(n)
    # since the hash table reduces the look up time close to O(1)
# space complexity: O(n)

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        map = {}
        for i in range(len(nums)):
            map[nums[i]] = i
        print(map)
        for i in range(len(nums)):
            complement = target - nums[i]
            if (complement in map) and (map[complement] != i):
                return [map[target-nums[i]], i]
