void mobius()  // 求1-n的莫比乌斯函数 O(n)
{
    int cnt = 0;
    vis[1] = 1;
    mob[1] = 1;
    for(ll i = 2;i <= n;i++)
    {
        if(!vis[i]) prime[cnt++] = i,mob[i] = -1;
        for(int j = 0;j < cnt && prime[j] * i <= n;j++)
        {
            vis[prime[j] * i] = 1;
            mob[i * prime[j]] = (i % prime[j] ? -mob[i] : 0);
            if(i % prime[j] == 0) break;
        } 
    }
}