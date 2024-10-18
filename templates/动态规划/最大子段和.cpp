//mx[i] 代表考虑前i个数的最大子段和
for (int i = 1;i <= n;i++)
{
    dp[i] = max(dp[i-1] + arr[i],arr[i]);
    mx[i] = max(mx[i-1],dp[i]);
}