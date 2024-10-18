//A Hamiltonian path is a path which visits every vertex exactly once.
//旅行商问题/哈密顿回路/哈密顿路径
// 从0号点出发
memset(dp,0x3f,sizeof(dp));
dp[1][0] = 0;
for(int i = 0;i < (1 << n);i++)
{
    for(int j = 0;j < n;j++)
    {
        if(i >> j & 1)
        {
            for(int k = 0;k < n;k++)
            {
                if(k != j && (i >> k & 1))
                    dp[i][j] = min(dp[i][j],dp[i ^ (1ll << j)][k] + dis[k][j]);
            }
        }
    }
}

int mi = inf;
for(int i = 1;i < n;i++)
    mi = min(mi,dp[(1ll << n) - 1][i])  // 哈密顿路径；

mi = inf;
for(int i = 1;i < n;i++)
    mi = min(mi,dp[(1ll << n) - 1][i] + dis[i][0]) // 哈密顿回路