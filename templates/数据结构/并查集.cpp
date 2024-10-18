for (int i = 1;i <= n;i++)
    f[i] = i;
int find(int x)
{
   return x == f[x] ? x : f[x] = find(f[x]);
}
void merge(int a,int b)
{
    int x = find(a),y = find(b);
    if(x != y)
        f[x] = y;
}