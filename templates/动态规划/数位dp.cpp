//limit 当前位限制 lead 前导0
ll ans[20];
ll arr[50];
ll dp[50][2][2][50];
int digit;
ll dfs(int pos,int limit,int lead,int sum)
{
    ll ans = 0;
    if(!pos)
        return sum;
    if(dp[pos][limit][lead][sum] != -1 && !limit && !lead)
        return dp[pos][limit][lead][sum];
    for (int i = 0;i <= (limit ? arr[pos] : 9);i++)
    {
        if(lead && i == 0)
            ans = ans + dfs(pos-1,limit && i == arr[pos],1,sum);
        else
            ans = ans + dfs(pos-1,limit && i == arr[pos],0,sum + (i == digit));
    }
    if(!lead && !limit)
        dp[pos][limit][lead][sum] = ans;
    return ans;
}
ll f(ll x)
{
    memset(dp,-1,sizeof(dp));
    int cnt = 0;
    while(x)
    {
        arr[++cnt] = x % 10;
        x /= 10;
    }
    return dfs(cnt,1,1,0);
}
void solve()
{ 
    ll a,b;
    cin >> a >> b;
    cout << f(b) - f(a-1) << ' ';
}