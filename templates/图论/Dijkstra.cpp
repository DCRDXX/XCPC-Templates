void dij(int s)
{
    for (int i = 1;i <= n;i++)
        dis[i] = INF;
    dis[s] = 0;
    priority_queue<PII,vector<PII>,greater<PII>>q;
    q.push({0,s});
    while(!q.empty())
    {
        int x = q.top().second;
        q.pop();
        if(vis[x]) continue;
        vis[x] = 1;
        for (auto it : g[x])
        {
            int to = it.to;
            int w = it.w;
            if(dis[to] > dis[x] + w)
            {
               dis[to] = dis[x] + w;
               q.push({dis[to],to});
            }
        }
    }
}