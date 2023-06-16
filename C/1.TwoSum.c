#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *result = (int*)malloc(sizeof(int) * 2);
    result[0] = 0;
    result[1] = 0;

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }

    *returnSize = 0;
    return result;
}

void main() {
    // int nums[4] = {2, 7, 11, 15};
    // int target = 9;

    // int nums[3] = {3, 2, 4};
    int nums[2] = {3, 3};
    int target = 6;
    
    int rtnSize = 2;
    int *returnSize = &rtnSize;

    int *result = twoSum(nums, sizeof(nums)/sizeof(nums[0]), target, returnSize);
    
    printf("%d, %d\n", result[0], result[1]);
}