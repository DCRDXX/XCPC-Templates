for (int i = 1; i <= n1; ++i)
    for (int j = 1; j <= n2; ++j)
        if (s1[i - 1] == s2[j - 1])
            dp[i][j] = dp[i - 1][j - 1] + 1;
        else
            dp[i][j] = 0;

for (int i = 1; i <= n1; ++i)
    for (int j = 1; j <= n2; ++j)
        ma = max(ma, dp[i][j]);