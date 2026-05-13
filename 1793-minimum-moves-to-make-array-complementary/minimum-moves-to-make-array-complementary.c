#include <stdlib.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int minMoves(int* nums, int numsSize, int limit) {

    int size = 2 * limit + 2;

    int* diff = (int*)calloc(size, sizeof(int));

    int left = 0;
    int right = numsSize - 1;

    while(left < right) {

        int a = nums[left];
        int b = nums[right];

        int low = min(a, b);
        int high = max(a, b);

        int sum = a + b;

        // Initially assume 2 moves
        diff[2] += 2;

        // 1 move range starts
        diff[1 + low] -= 1;

        // back to 2 moves
        diff[limit + high + 1] += 1;

        // 0 move at exact sum
        diff[sum] -= 1;

        // back to 1 move
        diff[sum + 1] += 1;

        left++;
        right--;
    }

    int answer = numsSize;

    int current = 0;

    for(int s = 2; s <= 2 * limit; s++) {

        current += diff[s];

        if(current < answer) {
            answer = current;
        }
    }

    free(diff);

    return answer;
}