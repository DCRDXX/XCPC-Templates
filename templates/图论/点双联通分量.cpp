void tarjan(int x,int father)
{
    low[x] = dfn[x] = ++cnt;
    s.push(x);
    for(auto to : g[x])
    {
        if(!dfn[to])
        {
            tarjan(to,x);
            low[x] = min(low[x],low[to]);
        }
        else if(to != father)
            low[x] = min(low[x],dfn[to]);
    }
    if(low[x] == dfn[x])
    {
        sum++;
        while(!s.empty())
        {
            int tmp = s.top();
            s.pop();
            scc[tmp] = sum;
            css[sum] = tmp;
            if(tmp == x)
                break;            
        }
    }
}