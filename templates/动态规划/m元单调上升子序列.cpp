// m元单调上升子序列
cin >> n >> m;
for (int i = 1;i <= n;i++)
{
    cin >> arr[i];
    brr[i] = arr[i];
}
sort(brr+1,brr+1+n);
n1 = unique(brr+1,brr+1+n) - (brr+1);
for (int i = 1;i <= n;i++)
{
    arr[i] = lower_bound(brr+1,brr+1+n1,arr[i]) - brr;
    dp[1][i] = 1;
}
for (int i = 2;i <= m;i++)
{
    memset(t,0,sizeof(t));
    for (int j = 1;j <= n;j++)
    {
        dp[i][j] = ask(arr[j]-1);
        add(arr[j],dp[i-1][j]);
    }
}
ll ans = 0;
for (int i = 1;i <= n;i++)
    ans = (ans + dp[m][i]) % mod;