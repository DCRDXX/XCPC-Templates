// 预处理LCA 预处理(nlogn) 查询(o1)
vector<int> g[MAXN];
int dep[MAXN],mi[MAXN][25];
int idx,dfn[MAXN],que[MAXN],lg[MAXN];
for(int i = 1;i <= idx;i++)
        lg[i] = lg[i-1] + (1 << (lg[i-1] + 1) == i);
void dfs(int x,int father)
{
    dfn[x] = ++idx,que[idx] = x;
    dep[x] = dep[father] + 1;
    for(auto it : g[x])
    {
        int to = it;
        if(to != father)
        {
            dfs(to,x);
            que[++idx] = x;            
        }
    }
}
void buildst()
{
    for(int i = 1;i <= idx;i++)
        mi[i][0] = que[i];
    for(int j = 1;j <= 20;j++)
    {
        for(int i = 1;i + (1 << j) - 1 <= idx;i++)
        {
            if(dep[mi[i][j-1]] < dep[mi[i + (1 << (j-1))][j-1]])
                mi[i][j] = mi[i][j-1];
            else
                mi[i][j] = mi[i + (1 << (j-1))][j-1];
        }
    }
}
int lca(int l,int r)
{
    l = dfn[l],r = dfn[r];
    if(l > r)
        swap(l,r);
    int s = lg[r - l + 1];
    if(dep[mi[l][s]] < dep[mi[r - (1 << s) + 1][s]])
        return mi[l][s];
    else
        return mi[r - (1 << s) + 1][s];
}