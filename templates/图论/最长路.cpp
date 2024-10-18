void spfa(int s)
{
    for (int i = 1;i <= MAXN;i++)
        dis[i] = -INF;
    dis[s] = 0;
    queue <int> q;
    q.push(s);
    vis[s] = 1;
    while(!q.empty())
    {
        int tmp = q.front();
        q.pop();
        vis[tmp] = 0;
        for (int i = head[tmp];i;i = edges[i].next)
        {
            int to = edges[i].to;
            if(dis[to] < dis[tmp] + edges[i].w)
            {
                dis[to] = dis[tmp] + edges[i].w;
                if(!vis[to])
                {
                    q.push(to);
                    vis[to] = 1;
                }
            }
        }
    }
}