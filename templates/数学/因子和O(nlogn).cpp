// g[i]代表i的因子和
for(int i = 1;i <= n;i++)
{
    for(int j = i;j <= n;j+=i)
        g[j] += i;
}