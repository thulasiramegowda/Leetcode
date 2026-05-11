/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* separateDigits(int* nums, int numsSize, int* returnSize) {
     int totalDigits = 0;
     for(int i=0;i<numsSize;i++){
        int n = nums[i];
        while(n>0){
            totalDigits++;
            n/=10;
      }
     }
     int* answer = (int*)malloc(totalDigits * sizeof(int));
     int index=0;
      for(int i=0;i<numsSize;i++){
        int n = nums[i];
        int digits[10];
        int count=0;

        while(n>0){
            digits[count++] = n%10;
            n /=10;
        }
        for(int j=count-1;j>=0;j--){
            answer[index++] = digits[j];
        }
     }
     *returnSize = totalDigits;
     return answer; 
}