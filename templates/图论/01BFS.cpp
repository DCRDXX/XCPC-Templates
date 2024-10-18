deque<int> q;
q.push_front(s);
dis[s] = 0;
while(!q.empty())
{
    int x = q.front();
    q.pop_front();
    if(vis[x]) continue;
    vis[x] = 1;
    for(auto it : g[x])
    {
        int to = it.to;
        int w = it.w;
        if(dis[to] > dis[x] + w)
        {
            dis[to] = dis[x] + w;
            if(w)
                q.push_back(to);
            else
                q.push_front(to);
        }
    }
}