// dfs求法
void dfs(int x,int fa)
{
    for(auto to : g[x])
    {
        if(to == fa) continue;
        dis[to] = dis[x] + 1;
        if(dis[to] > dis[p]) p = to;
        dfs(to,x);
    }
}
dfs(1,0);
dis[p] = 0;
dfs(p,0);
cout << dis[p] // 树的直径长度 
// 如果要求出一条直径上所有的节点，则可以在第二次DFS的过程中，记录每个点的前序节点，即可从直径的一段一路向前，遍历直径上的所有节点
// 树形dp求法
int dp[MAXN];
void dfs(int x,int fa)
{
    for(auto to : g[x])
    {
        if(to == fa) continue;
        dfs(to,x);
        ans = max(ans,dp[x] + dp[to] + 1);
        dp[x] = max(dp[x],dp[to] + 1);
    }
}