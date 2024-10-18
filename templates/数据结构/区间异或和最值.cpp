//nlogn 01字典树优化 trie
int arr[MAXN],num[MAXN];
int nex[MAXN][2],cnt,exist[MAXN];
void insert(int x)
{
    int cur = 0;
    for (int i = 30;i >= 0;i--)
    {
        int u = x >> i & 1;
        if(!nex[cur][u])
            nex[cur][u] = ++cnt;
        cur = nex[cur][u];
        exist[cur] = 1;
    }   
}
int query(int x)
{
    int ans = 0,cur = 0;
    for (int i = 30;i >= 0;i--)
    {
        int u = x >> i & 1;
        if(exist[nex[cur][!u]])
        {
            cur = nex[cur][!u];
            ans = ans * 2 + 1;
        }
        else
        {
            cur = nex[cur][u];
            ans = ans * 2;
        }
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 0;i <= cnt;i++)
    {
        nex[i][0] = 0;
        nex[i][1] = 0;
        exist[i] = 0;
    }
    cnt = 0;
    for (int i = 1;i <= n;i++)
    {
        cin >> arr[i];
        num[i] = num[i-1] ^ arr[i];
    }
    insert(0);
    int ans = 0;
    for (int i = 1;i <= n;i++)
    {
        ans = max(ans,query(num[i]));
        insert(num[i]);
    }
    cout << ans << "\n";
}