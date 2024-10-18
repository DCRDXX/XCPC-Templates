// 求x的所有因子 时间复杂度 max(sqrt(x),x的因子数)
map<int,int> mp;
for(int i = 2;i * i <= x;i++)
{
    if(x % i == 0)
    {
        while(x % i == 0)
        {
            mp[i]++;
            x /= i;
        }
    }
}
if(x > 1)
    mp[x]++;
vector<PII> v;
for(auto it : mp)
    v.pb({it.fi,it.se});
vector<int> ans;
void dfs(int p,int x)
{
    if(p == v.size())
    {
        ans.pb(x);
        return;
    }
    for(int i = 0;i <= v[p].se;i++)
    {
        dfs(p+1,x);
        x *= it.fi;
    }
}
dfs(0,1);