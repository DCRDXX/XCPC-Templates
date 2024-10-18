//dsu on tree O(nlogn) (cf 600E)
map<int,int> dfs(int x,int fa)
{
    map<int,int> mp;
    mp[c[x]] = 1;
    mx[x] = 1;
    ans[x] = c[x];
    for(auto to : g[x])
    {
        if(to == fa)
            continue;
        map<int,int> mp2 = dfs(to,x);
        if(mp.size() < mp2.size())
        {
            mx[x] = mx[to];
            ans[x] = ans[to];
            swap(mp,mp2);
        }
        for(auto it : mp2)
        {
            mp[it.fi] += it.se;
            if(mp[it.fi] > mx[x])
                ans[x] = it.fi,mx[x] = mp[it.fi];
            else if(mp[it.fi] == mx[x])
                ans[x] += it.fi;
        }
    }
    return mp;
}