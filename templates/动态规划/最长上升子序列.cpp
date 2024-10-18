int len = 0; //len是答案
for (int i = 1;i <= n;i++)
{
    if(dp[len] < arr[i])
        dp[++len] = arr[i];
    else
        *lower_bound(dp+1,dp+len+1,arr[i]) = arr[i];
}
//要求完整的子序列可以权值线段树维护dp