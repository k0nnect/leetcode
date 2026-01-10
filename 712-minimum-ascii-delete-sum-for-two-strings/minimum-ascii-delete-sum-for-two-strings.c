#include <string.h>
#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minimumDeleteSum(char* s1, char* s2) {
    int m = strlen(s1);
    int n = strlen(s2);
    
    int** dp = (int**)malloc((m + 1) * sizeof(int*));
    for (int i = 0; i <= m; i++) {
        dp[i] = (int*)malloc((n + 1) * sizeof(int));
    }

    dp[0][0] = 0;

    for (int i = 1; i <= m; i++) {
        dp[i][0] = dp[i - 1][0] + (int)s1[i - 1];
    }

    for (int j = 1; j <= n; j++) {
        dp[0][j] = dp[0][j - 1] + (int)s2[j - 1];
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                int deleteS1 = (int)s1[i - 1] + dp[i - 1][j];
                int deleteS2 = (int)s2[j - 1] + dp[i][j - 1];
                dp[i][j] = MIN(deleteS1, deleteS2);
            }
        }
    }

    int result = dp[m][n];

    for (int i = 0; i <= m; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}