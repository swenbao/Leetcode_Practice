//
//  Created by 筍包 on 2023/11/24.
//
// theoretically, the time complexity of lookup in hash table isn't "close to" O(1), but IS O(1)
// this solution should work, but it will cause Memory Limit Exceeded
// because the array is too large


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize);
int map_index(int key);

int main(){
    int nums[] = {2, 7, 11, 15};
    int numSize = sizeof(nums)/sizeof(int);
    int returnSize;
    int target = 9;
    int* ans = twoSum(nums, numSize, target, &returnSize);

    printf("(");
    for(int i = 0; i < returnSize; i++){
        if(i != returnSize-1)
            printf("%d, ", ans[i]);
        else
            printf("%d", ans[i]);
    }
    printf(")");
    return 0;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* map = malloc(2000000001*sizeof(int));
    for(int i = 0; i < 2000000001; i++){
        map[i] = INT_MIN;
    }
    for(int i = 0; i < numsSize; i++){
        map[map_index(nums[i])] = i;
    }
    int *ans = malloc(2*sizeof(int));
    for(int i = 0; i < numsSize; i++){
        int complement = target - nums[i];
        if(map[complement] != INT_MIN){
            ans[0] = map[complement];
            ans[1] = i;
            return ans;
        }
    }
    return 0;
}

int map_index(int key){
    return key-1000000000;
}