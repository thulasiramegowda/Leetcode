bool isGood(int* nums, int numsSize) {
    int max = nums[0];
    for(int i=0;i<numsSize;i++){
        if(nums[i]>max){
            max = nums[i];
        }
    }
    if(numsSize != max+1){
        return false;
    }
    int freq[201] ={0};
    for(int i=0;i<numsSize;i++){
        freq[nums[i]]++;
    }
    for(int i=1;i<max;i++){
        if(freq[i] != 1){
            return false;
        }
    }
    if(freq[max] != 2){
        return false;
    }
    return true;
}