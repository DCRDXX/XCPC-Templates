for (int i = 1;i <= 2 * n;i++)
    fa[i] = i;
int f = 0;
for (int i = 1;i <= n;i++)
{
    int a,b;
    cin >> a >> b;
    merge(a,b+n);
    merge(b,a+n);
}
for (int i = 1;i <= n;i++)
{
    if(find(i) == find(i + n))
        return false;
}