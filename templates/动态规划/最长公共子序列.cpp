for(int i = 1;i <= n;i++)
{
    for(int j = 1;j <= m;j++)
    {
        if(s1[i] == s2[j])
            dp[i][j] = max(dp[i][j],dp[i-1][j-1] + 1);
        else
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
    }
}