for (int i = 1;i <= n;i++)
{
    int x;
    cin >> x;
    ma[i][0] = x;
}
for (int j = 1;j <= 20;j++)
{
    for (int i = 1;i + (1 << j) - 1 <= n;i++)
        ma[i][j] = max(ma[i][j-1],ma[i + (1 <<(j - 1))][j-1]);   
}
for(i = 0;i < m;i++)
{
    int l,r;
    cin >> l >> r;
    int s = lg[r - l + 1];
    int ma1 = max(ma[l][s],ma[r - (1 << s)+1][s]);
}