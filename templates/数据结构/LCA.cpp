void dfs(int x,int father) // 求深度
{
    fa[x][0] = father;
    dep[x] = dep[father] + 1;
    for (int i = 1;i <= 20;i++)
        fa[x][i] = fa[fa[x][i-1]][i-1];
    for (auto it : g[x])
    {
        int to = it;
        if(to != father)
            dfs(to,x);
    }
}
int lca(int a, int b)
{
    if (dep[a] > dep[b])
        swap(a, b);
    for(int i = 20;i >= 0;i--)
    {
        if(dep[fa[b][i]] >= dep[a])
            b = fa[b][i];
    }
    if (a == b)
        return a;
    for (int k = 20; k >= 0; k--)
        if (fa[a][k] != fa[b][k])
            a = fa[a][k], b = fa[b][k];
    return fa[a][0];
}