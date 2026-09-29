/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* replaceElements(int* arr, int arrSize, int* returnSize) {

    int* answer = malloc(arrSize * sizeof(int));

    int maxRight = -1;

    for (int i = arrSize - 1; i >= 0; i--) {

        answer[i] = maxRight;

        if (arr[i] > maxRight) {
            maxRight = arr[i];
        }
    }

    *returnSize = arrSize;

    return answer;
}