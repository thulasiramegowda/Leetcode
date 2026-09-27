/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize) {
   int *answer = malloc(2*numsSize * sizeof(int));
   for(int i=0;i<numsSize;i++){
    answer[i]=nums[i];
    answer[i+numsSize]=nums[i];
   }
   *returnSize = 2*numsSize;
   return answer;
}