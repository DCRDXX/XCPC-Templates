for (int i = 1;i <= n;i++)
{
    for (auto to : g[i])
    {
        if(scc[i] != scc[to])
            add(scc[i],scc[to]);         
    }
}