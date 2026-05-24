int dfs(int i, int* arr, int n, int d, int* dp) {
    if (dp[i] != 0)
        return dp[i];

    int ans = 1;

    // Right
    for (int j = i + 1; j <= i + d && j < n; j++) {
        if (arr[j] >= arr[i])
            break;

        int temp = 1 + dfs(j, arr, n, d, dp);
        if (temp > ans)
            ans = temp;
    }

    // Left
    for (int j = i - 1; j >= i - d && j >= 0; j--) {
        if (arr[j] >= arr[i])
            break;

        int temp = 1 + dfs(j, arr, n, d, dp);
        if (temp > ans)
            ans = temp;
    }

    dp[i] = ans;
    return ans;
}

int maxJumps(int* arr, int arrSize, int d) {
    int dp[1001] = {0};
    int ans = 1;

    for (int i = 0; i < arrSize; i++) {
        int cur = dfs(i, arr, arrSize, d, dp);
        if (cur > ans)
            ans = cur;
    }

    return ans;
}