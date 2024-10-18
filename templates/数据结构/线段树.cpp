ll tree[n << 2],mark[n << 2],n,m,arr[n];
void build(int p = 1,int cl = 1,int cr = n)
{
    if(cl == cr)
    {
        tree[p] = arr[cl];
        return;
    }
    int mid = (cl + cr) >> 1;
    build(p << 1,cl,mid);
    build(p << 1 | 1,mid+1,cr);
    tree[p] = tree[p << 1] + tree[p << 1 | 1];
}
void push_down(int p,int len)
{
    mark[p << 1] += mark[p];
    mark[p << 1 | 1] += mark[p];
    tree[p << 1] += mark[p] * (len - len / 2);
    tree[p << 1 | 1] += mark[p] * (len / 2);   
    mark[p] = 0;
}
void update(int l,int r,int d,int p = 1,int cl = 1,int cr = n)
{
    if(cl >= l && cr <= r)
    {
        tree[p] += (cr - cl + 1) * d;
        mark[p] += d;
        return;
    }
    push_down(p,cr-cl+1);
    int mid = (cl + cr) >> 1;
    if(mid >= l) update(l,r,d,p << 1,cl,mid);
    if(mid < r) update(l,r,d,p << 1 | 1,mid+1,cr);
    tree[p] = tree[p << 1] + tree[p << 1 | 1];
}
ll ask(int l,int r,int p = 1,int cl = 1,int cr = n)
{
    if(l <= cl && cr <= r)
        return tree[p];
    push_down(p,cr - cl + 1);
    ll mid = (cr + cl) >> 1,ans = 0;
    if(mid >= l) ans += ask(l,r,p << 1 ,cl ,mid);
    if(mid < r) ans += ask(l,r,p << 1 | 1,mid+1,cr);
    return ans;
}