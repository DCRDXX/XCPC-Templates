void prim()
{
    for(int i = 1;i <= n;i++)
        dis[i] = INF;
    dis[1] = 0;
    int cnt = 0;
    priority_queue<PII,vector<PII>,greater<PII>> q;
    q.push({0,1});
    while(!q.empty())
    {
        int x = q.top().se;
        ll d = q.top().fi;
        q.pop();
        if(vis[x]) continue;
        vis[x] = 1;
        ans += d;
        cnt++;
        for(auto it : g[x])
        {
            int to = it.fi;
            if(dis[to] > it.se)
            {
                dis[to] = it.se;
                q.push({dis[to],to});
            }
        }
    }
    if(cnt == n)
        cout << ans;
    else
        cout << "orz";
}