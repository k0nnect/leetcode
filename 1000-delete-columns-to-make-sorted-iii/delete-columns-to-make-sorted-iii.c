int minDeletionSize(char** strs, int strsSize) {
    int m = strlen(strs[0]);
    int dp[105];
    int maxKeep = 0;

    for (int j = 0; j < m; j++) {
        dp[j] = 1;
    }

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < j; i++) {
            int valid = 1;
            for (int r = 0; r < strsSize; r++) {
                if (strs[r][i] > strs[r][j]) {
                    valid = 0;
                    break;
                }
            }
            if (valid) {
                if (dp[i] + 1 > dp[j]) {
                    dp[j] = dp[i] + 1;
                }
            }
        }
        if (dp[j] > maxKeep) {
            maxKeep = dp[j];
        }
    }

    return m - maxKeep;
}