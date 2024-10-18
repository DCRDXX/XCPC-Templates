struct node
{
    ll x,y,z,w,ans;
}a[MAXN],b[MAXN];
bool cmpx(node a,node b) 
{
    if(a.x != b.x)
        return a.x < b.x;
    else
    {
        if(a.y != b.y)
            return a.y < b.y;
        return a.z < b.z;
    }
}
bool cmpy(node a,node b)
{
    if(a.y != b.y)
        return a.y < b.y;
    return a.z < b.z;
}
ll t[MAXN];
int lowbit(int x)
{
    return x & (-x);
}
void add(int pos,int x)
{
    for(int i = pos;i < MAXN;i += lowbit(i))
        t[i] += x;
}
ll ask(int pos)
{
    ll ans = 0;
    for(int i = pos;i;i -= lowbit(i))
        ans += t[i];
    return ans;
}
void cdq(int l,int r)
{
    if(l == r) return;
    int mid = l + r >> 1;
    cdq(l,mid),cdq(mid + 1,r);
    sort(b+l,b+1+mid,cmpy);
    sort(b+1+mid,b+1+r,cmpy);
    int i = l;
    for(int j = mid + 1;j <= r;j++)
    {
        while(b[i].y <= b[j].y && i <= mid)
            add(b[i].z,b[i].w),i++;
        b[j].ans += ask(b[j].z);
    }
    for(int j = l;j < i;j++)
        add(b[j].z,-b[j].w);
}
ll cnt[MAXN];
void solve()
{
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++)
        cin >> a[i].x >> a[i].y >> a[i].z;
    sort(a+1,a+1+n,cmpx);
    int nn = 0,c = 0;
    for(int i = 1;i <= n;i++) // 去重
    {
        c++;
        if(a[i].x != a[i+1].x || a[i].y != a[i+1].y || a[i].z != a[i+1].z)
            b[++nn] = a[i],b[nn].w = c,c = 0;
    }
    cdq(1,nn);
    for(int i = 1;i <= nn;i++)
        cnt[b[i].ans + b[i].w - 1] += b[i].w;
    for(int i = 0;i < n;i++)
        cout << cnt[i] << '\n';

} 