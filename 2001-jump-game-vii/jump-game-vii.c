bool canReach(char* s, int minJump, int maxJump) {
    int n= strlen(s);
    int *queue = (int*)malloc(n*sizeof(int));
    int front = 0, rear = 0;
    queue[rear++] = 0;

    int farthest = 1;

    while (front < rear) {
        int i = queue[front++];

        int start = (i + minJump > farthest) ? i + minJump : farthest;
        int end = (i + maxJump < n - 1) ? i + maxJump : n - 1;

        for (int j = start; j <= end; j++) {
            if (s[j] == '0') {
                if (j == n - 1) {
                    free(queue);
                    return true;
                }
                queue[rear++] = j;
            }
        }

        if (end + 1 > farthest)
            farthest = end + 1;
    }

    free(queue);
    return (n == 1);
}