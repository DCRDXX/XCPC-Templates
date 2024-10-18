for (int i = 1;i <= n;i++)
{
    for (int j = 1;j <= m;j++)
    {
        for (int k = 0;k < s[i];k++)
        {
            if(j < k*w[i])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j],dp[i-1][j - k*w[i]] + k*v[i]);
        }
    }
}