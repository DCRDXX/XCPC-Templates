struct edge
{
    int fr,to,w;
}edges[n];
int find(int x)
{
    return x == f[x] ? x : f[x] = find(f[x]);
}
bool cmp(edge a,edge b)
{
    return a.w < b.w;
}
void kruskal()
{
    for (int i = 1;i <= n;i++)
        f[i] = i;
    sort(edges+1,edges+1+cnt,cmp);
    for (int i = 1;i <= cnt;i++)
    {
        int a = find(edges[i].fr);
        int b = find(edges[i].to);
        if(a != b) 
        {
            ans += edges[i].w;
            f[a] = b;
            tmp++;
            if(tmp == n-1)
                return;
        }
    }
    return << orz //不连通
}