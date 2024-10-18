ll get(int l,int r)
{
    return h[r] - h[l-1] * p[r-l+1];
}
p[0] = 1;
for(int i = 1;i <= n;i++)
{
    h[i] = h[i-1]*base+s[i];
    p[i] = p[i-1]*base;
}