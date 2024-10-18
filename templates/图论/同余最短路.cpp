for(int i = 1;i <= n;i++)
    cin >> a[i];
sort(a+1,a+1+n);
for(int i = 0;i < a[1];i++)
{
    for(int j = 2;j <= n;j++)
        g[i].pb({(i + a[j]) % a[1],a[j]});
}
dij();
ll ans = 0;
for(int i = 0;i < a[1];i++)
{
    // 统计ans
}
cout << ans;