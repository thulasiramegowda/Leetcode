/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
  *returnSize=rowIndex+1;
  int *row=(int*)calloc(rowIndex+1,sizeof(int));
  row[0]=1;
  for(int i=1;i<=rowIndex;i++){
    for(int j=i;j>0;j--){
        row[j]+=row[j-1];
    }
  }  
  return row;
}