/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize) {
    int* answer = malloc(numsSize * sizeof(int));
    answer[0] = nums[0];
      for(int i=1;i<numsSize;i++){
       answer[i]=answer[i-1]+nums[i];
        }
     *returnSize = numsSize;
     return answer;
}