int xorOperation(int n, int start) {
   int nums[n];
    for(int i=0;i<n;i++){
      nums[i] = start + 2 * i;
    }
    int answer=0;
    for(int i=0;i<n;i++){
    answer=answer ^ nums[i];
    }
    return answer;
}