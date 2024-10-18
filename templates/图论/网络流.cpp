// 网络流
// 最大流
// 最后的残留网络,两点间的反向路径的值就是两点间的实际流量
// EK 算法 O(nm^2) 算法时间复杂度高,只适用于小图
ll flow[n],mp[n][n],pre[n];
ll bfs(int s,int t)
{
    for(int i = 1;i <= n;i++) pre[i] = -1;
    flow[s] = INF;
    pre[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        if(x == t) break;
        for(int i = 1;i <= n;i++)
        {
            if(i != s && mp[x][i] > 0 && pre[i] == -1)
            {
                pre[i] = x;
                q.push(i);
                flow[i] = min(flow[x],mp[x][i]);
            }
        }
    }
    if(pre[t] == -1) return -1;
    return flow[t];
}
ll maxflow(int s,int t)
{
    ll ans = 0;
    while(1)
    {
        ll now = bfs(s,t);
        if(now == -1) break;
        int cur = t;
        while(cur != s)
        {
            int fa = pre[cur];
            mp[fa][cur] -= now;
            mp[cur][fa] += now;
            cur = fa;
        }
        ans += now;
    }
    return ans;
}
void solve()
{
    for(int i = 1;i <= m;i++)
    {
        ll a,b,c;
        cin >> a >> b >> c;
        mp[a][b] += c;
    }
    cout << maxflow(s,t);
}

//Dinic O(n*n*m)
struct edge
{
    int to,w,next;
}edges[m << 1];
int n,m,s,t;
int head[n],cnt = 1;
int now[n],dep[n];
void add(int from,int to,int w)
{
    edges[++cnt].w = w;
    edges[cnt].to = to;
    edges[cnt].next = head[from];
    head[from] = cnt;
}
ll bfs()
{
    for(int i = 1;i <= n;i++) dep[i] = inf;
    dep[s] = 0;
    now[s] = head[s];
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for(int i = head[x];i;i = edges[i].next)
        {
            int to = edges[i].to;
            if(edges[i].w > 0 && dep[to] == inf)
            {
                q.push(to);
                now[to] = head[to];
                dep[to] = dep[x] + 1;
                if(to == t)
                    return 1;
            }
        }
    }
    return 0;
}
ll dfs(int u,ll sum)
{
    if(u == t) return sum;
    ll now = 0;
    for(int i = now[u];i&&sum;i = edges[i].next)
    {
        now[u] = i;
        int to = edges[i].to;
        if(edges[i].w > 0 && dep[to] == dep[u] + 1)
        {
            ll k = dfs(to,min(sum,edges[i].w));
            if(!k) dep[to] = 0;
            edges[i].w -= k;
            edges[i^1].w += k;
            now += k;
            sum -= k;
        }
    }
    return now;
}
void solve()
{
    cin >> n >> m >> s >> t;
    for(int i = 1;i <= m;i++)
    {
        int a,b;
        ll c;
        add(a,b,c);
        add(b,a,0);
    }
    ll ans = 0;
    while(bfs())
        ans += dfs(s,inf);
    cout << ans;
}

//ISAP O(n*n*m)
struct edge
{
    int to,next,from;
    ll w;
}edges[m << 1];
int n,m,s,t;
int head[n],cnt = 1;
int now[n],dep[n],pre[n],gap[n];
void add(int from,int to,int w)
{
    edges[++cnt].w = w;
    edges[cnt].from = from;
    edges[cnt].to = to;
    edges[cnt].next = head[from];
    head[from] = cnt;
}
void bfs()
{
    for(int i = 0;i <= n;i++)
    {
        dep[i] = 0;
        gap[i] = 0;
    }
    dep[t] = 1;
    queue<int> q;
    q.push(t);
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        gap[dep[x]]++;
        for(int i = head[x];i;i = edges[i].next)
        {
            int to = edges[i].to;
            if(edges[i^1].w && !dep[to])
            {
                dep[to] = dep[x] + 1;
                q.push(to);
            }
        }
    }
}
ll augment()
{
    ll v = t,flow = INF;
    while(v != s)
    {
        int u = pre[v];
        flow = min(flow,edges[u].w);
        v = edges[u].from;
    }
    v = t;
    while(v != s)
    {
        int u = pre[v];
        edges[u].w -= flow;
        edges[u^1].w += flow;
        v = edges[u].from;
    }
    return flow;
}

void ISAP()
{
    bfs();
    ll flow = 0;
    int u = s;
    for(int i = 1;i <= n;i++) now[i] = head[i];
    while(dep[s] <= n)
    {
        if(u == t)
        {
            flow += augment();
            u = s;
        }
        bool ok = 0;
        for(int i = now[u];i;i = edges[i].next)
        {
            int v = edges[i].to;
            if(edges[i].w && dep[v] + 1 == dep[u])
            {
                ok = 1;
                pre[v] = i;
                now[u] = i;
                u = v;
                break;
            }
        }
        if(!ok)
        {
            gap[dep[u]]--;
            if(!gap[dep[u]]) break;
            int mi = n + 10;
            for(int i = head[u];i;i = edges[i].next)
            {
                int v = edges[i].to;
                if(dep[v] < mi && edges[i].w)
                    mi = dep[v];
            }
            dep[u] = mi + 1;
            gap[dep[u]]++;
            now[u] = head[u];
            if(u != s)
                u = edges[pre[u]].from;
        }
    }
    cout << flow << "\n";
}
void solve()
{   
    cin >> n >> m >> s >> t;
    for(int i = 1;i <= m;i++)
    {
        int a,b;
        ll c;
        cin >> a >> b >> c;
        add(a,b,c);
        add(b,a,0);
    }
    ISAP();
}

// 最大闭合子图的权值等于所有正权点之和减最小割