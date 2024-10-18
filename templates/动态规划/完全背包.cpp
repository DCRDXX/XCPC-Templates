for (int i = 1;i <= n;i++)
{
    for (int j = w[i];j <= m;j++)
        dp[j] = max(dp[j],dp[j - w[i]] + v[i]);
}