for (int k = l;k < r;k++)
    dp[l][r] = min(dp[l][k] + dp[k+1][r]) + w(l,r);
   // 优化为：
for (int k = m[l][r-1];k <= m[l+1][r];k++)
    dp[l][r] = min(dp[l][k] + dp[k+1][r]) + w(l,r);