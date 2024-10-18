// 可持久化线段树求区间第k小 多测令cnt = 0
int n,m;
ll a[MAXN];
ll b[MAXN];
int root[MAXN];
int cnt;
int nn;
struct node
{
    int l,r,num;
}t[MAXN << 5];
int update(int pre,int x,int cl = 1,int cr = nn)
{
    int rt = ++cnt;
    t[rt].l = t[pre].l;
    t[rt].r = t[pre].r;
    t[rt].num = t[pre].num + 1;
    int mid = cl + cr >> 1;
    if(cl < cr)
    {
        if(x <= mid)
            t[rt].l = update(t[pre].l,x,cl,mid);
        else
            t[rt].r = update(t[pre].r,x,mid + 1,cr);
    }
    return rt;
}
int ask(int l,int r,int k,int cl = 1,int cr = nn)
{
    if(cl == cr)
        return cl;
    int x = t[t[r].l].num - t[t[l].l].num;
    int mid = cl + cr >> 1;
    if(x >= k)
        return ask(t[l].l,t[r].l,k,cl,mid);
    else
        return ask(t[l].r,t[r].r,k-x,mid + 1,cr);
}
void solve()
{
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        cin >> a[i],b[i] = a[i];
    sort(b+1,b+1+n);
    nn = unique(b+1,b+1+n) - b - 1;
    for(int i = 1;i <= n;i++)
    {
        int p = lower_bound(b+1,b+1+nn,a[i]) - b;
        root[i] = update(root[i-1],p);
    }
    for(int i = 1;i <= m;i++)
    {
        int l,r,k;
        cin >> l >> r >> k;
        int t = ask(root[l-1],root[r],k);
        cout << b[t] << "\n";
    }
}