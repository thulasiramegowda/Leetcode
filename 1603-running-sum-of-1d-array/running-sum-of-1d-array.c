/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize) {
    int* answer = malloc(numsSize * sizeof(int));
    for(int i=1;i<numsSize;i++){
        answer[i]=nums[i]+nums[i-1];
        nums[i]=answer[i];
    }
    *returnSize = numsSize;
    return nums;
}