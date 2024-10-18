for (int i = 1;i <= n;i++)
{
    int w,v,p;
    cin >> w >> v >> p;
    for (int j = 1;j <= p;j = j << 1)
    {
        arr.push_back({j*w,j*v});
        p -= j;
    }
    if(p)
        arr.push_back({p*w,p*v});
}
for (int i = 0;i < arr.size();i++)
{
    for (int j = m;j >= arr[i].first;j--)
        dp[j] = max(dp[j],dp[j - arr[i].first] + arr[i].second);
}