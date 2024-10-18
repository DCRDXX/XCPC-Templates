int f[MAXN],dis[MAXN];
for (int i = 1;i <= n;i++)
    f[i] = i;
int find(int x)
{
    if(x == f[x])
        return x;
    int tmp = find(f[x]);
    dis[x] = dis[f[x]] + dis[x];
    return f[x] = tmp;
}
void merge(int a,int b,int w) // w的大小要具体分析
{
    int x = find(a),y = find(b);
    f[x] = y;
    dis[x] = dis[b] + w - dis[a];
}