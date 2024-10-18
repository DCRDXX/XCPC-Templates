void tarjan(int x,int father)
{
    low[x] = dfn[x] = ++cnt;
    int child = 0;
    for(auto to : g[x])
    {
        if(!dfn[to])
        {
            tarjan(to,x);
            low[x] = min(low[x],low[to]);
            if(low[to] >= dfn[x])
                child++;
        }
        else if(to != father)
            low[x] = min(low[x],dfn[to]);
    }

    if((x == father && child >= 2)||(x != father && child >= 1))
    {
        sum++;
        ans[x] = 1;
    } 
}
for (int i = 1;i <= n;i++)
{
    if(!dfn[i])
        tarjan(i,i);
}