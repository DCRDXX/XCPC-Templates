int n,m;
ll a[MAXN];
ll b[MAXN];
int root[MAXN];
int cnt;
int nn;
struct node
{
    ll l,r,num,sum,s,val;
}t[MAXN << 5];
int update(int pre,int x,ll v,int cl = 1,int cr = nn)
{
    int rt = ++cnt;
    t[rt].l = t[pre].l;
    t[rt].r = t[pre].r;
    t[rt].num = t[pre].num + 1;
    t[rt].sum = t[pre].sum + v;
    int mid = cl + cr >> 1;
    if(cl == cr)
    {
        t[rt].val = v;
        return rt;
    }
    if(cl < cr)
    {
        if(x <= mid)
            t[rt].l = update(t[pre].l,x,v,cl,mid);
        else
            t[rt].r = update(t[pre].r,x,v,mid + 1,cr);
    }
    return rt;
}
ll ask(int l,int r,int k,int cl = 1,int cr = nn)
{
    if(cl == cr)
        return t[r].val * k;
    int x = t[t[r].r].num - t[t[l].r].num;
    int mid = cl + cr >> 1;
    if(x >= k)
        return ask(t[l].r,t[r].r,k,mid+1,cr);
    else
        return t[t[r].r].sum - t[t[l].r].sum + ask(t[l].l,t[r].l,k-x,cl,mid);
}
void solve()
{
    cnt = 0;
    cin >> n;
    for(int i = 1;i <= n;i++)
        cin >> a[i],b[i] = a[i];
    sort(b+1,b+1+n);
    nn = unique(b+1,b+1+n) - b - 1;
    for(int i = 1;i <= n;i++)
    {
        int p = lower_bound(b+1,b+1+nn,a[i]) - b;
        root[i] = update(root[i-1],p,a[i]);
    }
    cin >> m;
    for(int i = 1;i <= m;i++)
    {
        int l,r,k;
        cin >> l >> r >> k;
        ll ans = ask(root[l-1],root[r],k);
        ll tmp = r - l + 1;
        cout << tmp * (tmp + 1) * (2 * tmp  + 1) / 6 + ans << "\n";
        // cout << ans << "\n";
    }
}