//普通莫队 O(n * sqrt(m))
int belong(int x)
{
    return x/b;
}
bool cmp(qry a,qry b)
{
    if(belong(a.l) == belong(b.l))
    {
        if(belong(a.l) & 1)
            return a.r < b.r;
        else
            return a.r > b.r;
    }
    return belong(a.l) < belong(b.l);
}
void erase(int x)
{

}
void insert(int x)
{

}
    cin >> n >> m >> k;
    b = n / (sqrt(m) + 1) + 1;
    for (int i = 1;i <= n;i++)
        cin >> arr[i];
    for (int i = 1;i <= m;i++)
    {
        cin >> q[i].l >> q[i].r;
        q[i].t = i;
    }
    sort(q+1,q+m+1,cmp);
    int l = 1,r = 0;
    for (int i = 1;i <= m;i++)
    {
        while(l < q[i].l)
            erase(arr[l]),l++;
        while(l > q[i].l)
            l--,insert(arr[l]);
        while(r < q[i].r)
            r++,insert(arr[r]);
        while(r > q[i].r)
            erase(arr[r]),r--;
        l = q[i].l , r = q[i].r;
        Ans[q[i].t] = ans;
    }
    for (int i = 1;i <= m;i++)
        cout << Ans[i] << "\n";