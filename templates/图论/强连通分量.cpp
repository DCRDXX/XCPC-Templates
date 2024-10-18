stack<int> s;
// ins : 是否在栈中 scc：每个点所属的强连通分量编号 sum：强连通分量的数量
int dfn[n],low[n],ins[n],scc[n],cnt,sum;
void tarjan(int x)
{
    low[x] = dfn[x] = ++cnt;
    ins[x] = 1;
    s.push(x);
    for(auto to : g[x])
    {
        if(!dfn[to])
        {
            tarjan(to);
            low[x] = min(low[x],low[to]);
        }
        else if(ins[to])
            low[x] = min(low[x],dfn[to]);
    }
    if(low[x] == dfn[x])
    {
        ++sum;
        while(!s.empty())
        {
            int tmp = s.top();
            s.pop();
            ins[tmp] = 0;
            scc[tmp] = sum;
            if(tmp == x)
                break;
        }
    }
}

for (int i = 1;i <= n;i++)
{
    if(!dfn[i])
        tarjan(i);
}