ll dp[505][505][10][10];
ll a[1005][1005];
void RMQ_init2d(int n,int m)
{
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            dp[i][j][0][0] = a[i][j];
        }
    }
    int t = log((double)m) / log(2.0);

    for(int i = 0;i <= t;i++)
    {
        for(int j = 0;j <= t;j++)
        {
            if(i==0&&j==0)
                continue;
            for(int row = 1;row + (1<<i) - 1 <= n;row++)
            {
                for(int col = 1;col + (1<<j) - 1 <= m;col++)
                {
                    if(i)
                        dp[row][col][i][j] = max(dp[row][col][i-1][j],dp[row+(1<<(i-1))][col][i-1][j]);
                    else
                        dp[row][col][i][j] = max(dp[row][col][i][j-1],dp[row][col+(1<<(j-1))][i][j-1]);
                }
            }
        }
    }
}
ll RMQ_2d(int x1,int y1,int x2,int y2)
{
    int k1 = log(double(x2 - x1 + 1)) / log(2.0);
    int k2 = log(double(y2 - y1 + 1)) / log(2.0);
    ll m1 = dp[x1][y1][k1][k2];
    ll m2 = dp[x2 - (1<<k1) + 1][y1][k1][k2];
    ll m3 = dp[x1][y2 - (1<<k2) + 1][k1][k2];
    ll m4 = dp[x2 - (1<<k1) + 1][y2 - (1<<k2) + 1 ][k1][k2];
    ll _max = max(max(m1,m2),max(m3,m4));
    return _max;
}
