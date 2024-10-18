// tarjan求边双
ll n, m, u, v, cnt;
int dfn[100005], low[100005];
vector<PII> g[100005];
stack<int> st;
int mm;
int scc[100005];
int sz[100005];
void tarjan(int x, int las){
    low[x] = dfn[x] = ++cnt;
    st.push(x);
    for (auto it: g[x]){
        if (it.se == (las ^ 1)) continue;
        if (!dfn[it.fi]){
            tarjan(it.fi, it.se);
            low[x] = min(low[x], low[it.fi]);
        }else low[x] = min(low[x], dfn[it.fi]);
    }
    if (dfn[x] == low[x]){
        vector<int> vec;
        scc[x] = ++mm;
        sz[mm]++;
        while (st.top() != x){
            scc[st.top()] = mm;
            sz[mm]++;
            st.pop();
        }
        st.pop();
    }
}
for(int i = 1;i <= m;i++)
{
    int a,b;
    cin >> a >> b;
    g[a].pb({b,i << 1});
    g[b].pb({a,i << 1|1});
}
for(int i = 1;i <= n;i++)
{
    if(!dfn[i])
        tarjan(i,0);
}