struct node
{
    ll lx,rx,y,tp;
}len[MAXN];
ll cnt;
ll xx[MAXN];
ll tag[MAXN],t[MAXN];
ll m;
bool cmp(node a,node b)
{
    return a.y < b.y;
};
void pushup(int p,int cl,int cr)
{
    if(tag[p]) t[p] = xx[cr] - xx[cl];
    else t[p] = t[p << 1] + t[p << 1 | 1];
}
void update(int l,int r,int tp,int p = 1,int cl = 1,int cr = m)
{
    if(l <= cl && cr <= r)
    {
        tag[p] += tp;
        pushup(p,cl,cr);
        return;
    }
    if(cl + 1 == cr)
        return;
    int mid = cl + cr >> 1;
    if(l <= mid) update(l,r,tp,p << 1,cl,mid);
    if(r > mid) update(l,r,tp,p << 1 | 1,mid,cr);
    pushup(p,cl,cr);
}
void solve()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        db x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        len[++cnt] = {x1,x2,y1,1};
        xx[cnt] = x1;
        len[++cnt] = {x1,x2,y2,-1};
        xx[cnt] = x2;
    }
    sort(xx+1,xx+1+cnt);
    sort(len+1,len+1+cnt,cmp);
    m = unique(xx+1,xx+1+cnt) - xx - 1;
    ll ans = 0;
    for(int i = 1;i <= cnt;i++)
    {
        ans += t[1] * (len[i].y - len[i-1].y);
        int L = lower_bound(xx+1,xx+1+m,len[i].lx) - xx;
        int R = lower_bound(xx+1,xx+1+m,len[i].rx) - xx;
        update(L,R,len[i].tp);
    }
    cout << ans;
}