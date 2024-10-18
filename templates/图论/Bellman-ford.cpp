ll dis[MAXN],last[MAXN],re[MAXN] //dis距离，last用来存上一次的结果。
for (int i = 1;i <= n;i++)
{
     for (int j = 1;j <= n;j++)
        re[i][j] = INF;
}
void Bellman_ford()
{
    for (int i = 1;i <= n;i++)
        dis[i] = INF;
    dis[1] = 0;
    for (int i = 1;i < n;i++)
    {
        memcpy(last,dis,sizeof dis);
        for (int j = 1;j <= m;j++)
        {
            ll fr = edges[j].fr,to = edges[j].to,w = edges[j].w;
            dis[to] = min(dis[to],last[fr] + w);
        }

        // for (int j = 1;j <= n;j++)
        //     re[i][j] = dis[j];
        // i 是边数
        // re数组维护了从 1 到 j 使用了 i 条边的最短路
    }
        // for (int j = 1;j <= cnt;j++)
        // {
        //     ll fr = edges[j].fr,to = edges[j].to,w = edges[j].w;
        //     if(last[fr] + w < dis[to])
        //     {
        //         // 有负权回路
        //     }
        // }
}