void floyd()
{
    for (int k = 1;k <= n;k++)
    {
        for (int i = 1;i < k;i++)
        {
            for (int j = 1;j < k;j++)
            {
                if(i!=j)
                    ans = min(ans,dis[i][j] + mp[i][k] + mp[k][j]);
            }
        }
        for (int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= n;j++)
                dis[i][j] = min(dis[i][k]+dis[k][j],dis[i][j]);
        }
    }
}